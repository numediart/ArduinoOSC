#include "Packetizer.h"

uint8_t Packetizer::crc8(const uint8_t* data, size_t size)
{
	uint8_t result = 0xFF;
	for (result = 0; size != 0; --size)
	{
		result ^= *data++;
		for (size_t i = 0; i < 8; ++i)
		{
			if (result & 0x80)
			{
				result <<= 1;
				result ^= 0x85; // x8 + x7 + x2 + x0
			}
			else
				result <<= 1;
		}
	}
	return result;
}
