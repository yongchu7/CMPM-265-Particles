#ifndef _PENNER_CIRC
#define _PENNER_CIRC

#include <math.h>

class behavior {

public:

	static float CirceaseIn(float t, float b, float c, float d);
	static float CirceaseOut(float t, float b, float c, float d);
	static float CirceaseInOut(float t, float b, float c, float d);
	static float LineareaseNone(float t, float b, float c, float d);
	static float LineareaseIn(float t, float b, float c, float d);
	static float LineareaseOut(float t, float b, float c, float d);
	static float LineareaseInOut(float t, float b, float c, float d);
	static float CubiceaseIn(float t, float b, float c, float d);
	static float CubiceaseOut(float t, float b, float c, float d);
	static float CubiceaseInOut(float t, float b, float c, float d);
	static float QuadeaseIn(float t, float b, float c, float d);
	static float QuadeaseOut(float t, float b, float c, float d);
	static float QuadeaseInOut(float t, float b, float c, float d);
};

#endif