#include "ArduinoOSC.h"

bool ArduinoOSC::match(const String& pattern, const String& test, bool full)
{
	if (full) return oscpkt::fullPatternMatch(pattern.c_str(), test.c_str());
	else      return oscpkt::partialPatternMatch(pattern.c_str(), test.c_str());
}
