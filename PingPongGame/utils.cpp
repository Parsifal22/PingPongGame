#include "win32_platform.h"


inline extern int clamp(int min, int val, int max)
{
	if (val < min) return min;
	if (val > max) return max;
	return val;

}