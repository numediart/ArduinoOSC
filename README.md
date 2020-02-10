# ArduinoOSC

OSC library for Arduino (ESP, Teensy, AVR, etc.) forked from https://github.com/hideakitai/ArduinoOSC

See the original readme for more information

## Changes made

1. Create a file ArduinoOSC.cpp next to ArduinoOSC.h
2. Copy/Paste this code in ArduinoOSC.cpp

```C++
#include "ArduinoOSC.h"

bool ArduinoOSC::match(const String& pattern, const String& test, bool full)
{
	if (full) return oscpkt::fullPatternMatch(pattern.c_str(), test.c_str());
	else      return oscpkt::partialPatternMatch(pattern.c_str(), test.c_str());
}
```

3. In ArduinoOSC.h, at line 18, remove the implementation of match function, so you get declaration only:

```C++
bool match(const String& pattern, const String& test, bool full = true);
```

4. Create a file Packetizer.cpp next to Packetizer.h in ArduinoOSC/lib folder
5. Copy/Paste this code in Packetizer.cpp

```C++
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
```

6. In Packetizer.h, at line 30, remove the implementation of crc8 function, so you get declaration only:

```C++
uint8_t crc8(const uint8_t* data, size_t size);
```

## License

MIT
