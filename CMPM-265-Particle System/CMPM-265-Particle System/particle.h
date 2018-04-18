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

using namespace sf;
using namespace std;


class Particle
{
public:
	
	Vector2f position;
	Vector2f vel;
	Vector2f oldVelocity, newVelocity;
	Vector2f oldSize, newSize;
	Vector2f scale;
	Vector2f startposition;
	RectangleShape rectshape;
	Clock clock;
	float lifetime;
	float time;
	int tex;
	float velocity;
	float angle;
	int behavior;
	bool isdead;
	void update();
	void draw(RenderWindow &window);
	Particle(Vector2f position, float velocity, float angle, Vector2f scale, float lifetime,int behavior, int tex);





};
