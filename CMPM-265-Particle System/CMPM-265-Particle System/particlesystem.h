#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include <iostream>
#include <memory>

#include "particle.h"

using namespace sf;
using namespace std;

class particlesystem {
public:
	particlesystem(Vector2f emitterposition, float rate, float angle, Vector2f size,float velocity,int behavior, int texture);
	Vector2f emitterposition;
	Vector2f size;
	Clock clock;
	float rate;
	float angle;
	float velocity;
	float time;
	float pressedtime;
	int behavior;
	int texture;
	void update();
	void destroy();
	void draw(RenderWindow& window);
	vector <Particle*> particles;
	Particle* createParticles();
};