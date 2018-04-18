#include "behavior.h"

float behavior::CirceaseIn(float t, float b, float c, float d) {
	return -c * (sqrt(1 - (t /= d)*t) - 1) + b;
}
float behavior::CirceaseOut(float t, float b, float c, float d) {
	return c * sqrt(1 - (t = t / d - 1)*t) + b;
}

float behavior::CirceaseInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
	return c / 2 * (sqrt(1 - t*(t -= 2)) + 1) + b;
}

float behavior::LineareaseNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float behavior::LineareaseIn(float t, float b, float c, float d) {
	return c*t / d + b;
}
float behavior::LineareaseOut(float t, float b, float c, float d) {
	return c*t / d + b;
}

float behavior::LineareaseInOut(float t, float b, float c, float d) {
	return c*t / d + b;
}
float behavior::CubiceaseIn(float t, float b, float c, float d) {
	return c*(t /= d)*t*t + b;
}
float behavior::CubiceaseOut(float t, float b, float c, float d) {
	return c*((t = t / d - 1)*t*t + 1) + b;
}

float behavior::CubiceaseInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
	return c / 2 * ((t -= 2)*t*t + 2) + b;
}
float behavior::QuadeaseIn(float t, float b, float c, float d) {
	return c*(t /= d)*t + b;
}
float behavior::QuadeaseOut(float t, float b, float c, float d) {
	return -c *(t /= d)*(t - 2) + b;
}

float behavior::QuadeaseInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return ((c / 2)*(t*t)) + b;
	return -c / 2 * (((t - 2)*(--t)) - 1) + b;
}