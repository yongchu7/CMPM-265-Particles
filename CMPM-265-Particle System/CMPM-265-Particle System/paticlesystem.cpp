#include "particlesystem.h"

particlesystem::particlesystem(Vector2f emitterposition, float rate, float angle, Vector2f size, float velocity, int behavior, int texture) {
	this->emitterposition = emitterposition;
	this->rate = rate;
	this->angle = angle;
	this->size = size;
	this->velocity = velocity;
	this->behavior = behavior;
	this->texture = texture;
	this->pressedtime = 0;
	this->time = 0;

	
}

void particlesystem::update() {
	float dt = clock.restart().asSeconds();
	time += dt;
	pressedtime += dt;

	for (Particle *particle : particles) {
		particle->update();
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && pressedtime > 0.1f) {
		rate *= 1.5f;
		//particles.push_back(createParticles());
		pressedtime = 0;
	
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && pressedtime > 0.1f) {
		rate *= 0.8f;
		//particles.pop_back();
		pressedtime = 0;

	}
	if (time > rate) {
		particles.push_back(createParticles());
		time = 0;
	}
	destroy();
}

void particlesystem::destroy() {
	for (auto it = particles.begin(); it != particles.end(); ++it)
	{
		if ((*it)->isdead)
		{
			Particle* particle = *it;
			it = particles.erase(it);
			delete particle;
			continue;
		}
	}
}

void particlesystem::draw(RenderWindow &window) {
	for (Particle* particle : particles) {
		particle->draw(window);
	}
}


Particle* particlesystem::createParticles() {
	float speed = rand() % 10 * 0.5f + velocity;
	float lifespan =rand() % 5  + 5.0f;
	float dir = ((rand() % 180) + angle) * 3.14f / 360.f;
	return new Particle(this->emitterposition,speed,dir,size,lifespan,behavior,texture);
}