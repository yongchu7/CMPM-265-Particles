#include "particle.h"
#include "behavior.h" 

extern vector<Texture> textures;


Particle::Particle(Vector2f position, float velocity, float angle, Vector2f scale, float lifetime, int behavior,int tex) {
	this->position = position;
	this->vel = Vector2f(velocity*cos(angle), velocity * sin(angle));
	this->angle = angle;
	this->scale = scale;
	this->lifetime = lifetime;
	this->behavior = behavior;
	this->tex = tex;
	this->startposition = position;
	this->oldVelocity = vel;
	this->oldSize = scale;
	this->time = 0;
	this->isdead = false;
	
	rectshape.setSize(scale);
	rectshape.setPosition(position);
	rectshape.setTexture(&textures [tex]);
	rectshape.setOrigin(scale.x / 2,scale.y / 2);

	switch (behavior) {
	case 0:
		this->newSize = scale * 2.0f;
		this->newVelocity = vel * 0.5f;
		cout << "work0" << endl;
		break;
	case 1:
		this->newSize = scale * 0.5f;
		this->newVelocity = vel * 3.0f;
		cout << "work1" << endl;
		break;
	case 2:
		this->newSize = scale * 5.0f;
		this->newVelocity = vel * 2.0f;
		cout << "work2" << endl;
		break;
	case 3:
		this->newSize = scale * 5.0f;
		this->newVelocity = vel * 0.7f;
		cout << "work3" << endl;
		break;
	}

}


void Particle::update()
{

	time += clock.restart().asSeconds();
	float rotation = behavior::LineareaseOut(time,0,180,lifetime);
	switch (behavior) {
	case 0:
		scale = oldSize + (time / lifetime)*(newSize - oldSize);
		vel = oldVelocity + (time / lifetime)*(newVelocity - oldVelocity);
		break;
	case 1:

		scale.x = behavior::CirceaseIn(time, newSize.x, newSize.x - oldSize.x, lifetime);
		scale.y = behavior::CirceaseIn(time, newSize.y, newSize.y - oldSize.y, lifetime);
		vel.x = behavior::CirceaseIn(time, newVelocity.x, newVelocity.x - oldVelocity.x, lifetime);
	    vel.y = behavior::CirceaseIn(time, newVelocity.y, newVelocity.y - oldVelocity.y, lifetime);
		cout << 1 << endl;
		break;
	case 2:
		scale.x = behavior::QuadeaseIn(time, newSize.x, newSize.x - oldSize.x, lifetime);
		scale.y = behavior::QuadeaseIn(time, newSize.y, newSize.y - oldSize.y, lifetime);
		vel.x = behavior::QuadeaseIn(time, newVelocity.x, newVelocity.x - oldVelocity.x, lifetime);
		vel.y = behavior::QuadeaseIn(time, newVelocity.y, newVelocity.y - oldVelocity.y, lifetime);
		break;
	case 3:
		scale.x = behavior::CubiceaseIn(time, newSize.x, newSize.x - oldSize.x, lifetime);
		scale.y = behavior::CubiceaseIn(time, newSize.y, newSize.y - oldSize.y, lifetime);
		vel.x = behavior::CubiceaseIn(time, newVelocity.x, newVelocity.x - oldVelocity.x, lifetime);
		vel.y = behavior::CubiceaseIn(time, newVelocity.y, newVelocity.y - oldVelocity.y, lifetime);
		cout << 3 << endl;
		break;

	}
		rectshape.setSize(scale);
		rectshape.setOrigin(scale.x / 2, scale.y / 2);
		position = position + vel;
		rectshape.setPosition(position);
		rectshape.setRotation(rotation);

		if (time > lifetime) {
			time = 0;
			position = startposition;
			vel = oldVelocity;
			scale = oldSize;
			isdead = true;
		}

}

void Particle :: draw(RenderWindow &window)
{
	window.draw(rectshape);
}


