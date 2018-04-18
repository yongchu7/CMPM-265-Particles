#include "particlesystem.h"

using namespace std;
using namespace sf;

vector<Texture> textures;

int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 800), " Particle System");

	Texture tex1;
	Texture tex2;
	Texture tex3;

	tex1.loadFromFile("snorlax.png");
	tex2.loadFromFile("Jigglypuff.png");
	tex3.loadFromFile("Psyduck.png");
	textures.push_back(tex1);
	textures.push_back(tex2);
	textures.push_back(tex3);

	particlesystem par1(Vector2f(500.0f, 400.0f), 1.0f, 180.0f, Vector2f(50.0f, 50.0f), 0.5f,1, 0);
	particlesystem par2(Vector2f(550.0f, 400.0), 1.0f, -180.0f, Vector2f(10.0f, 10.0f), 0.5f,3, 1);
	particlesystem par3(Vector2f(550.0f, 450.0), 1.0f, 70.0f, Vector2f(10.0f, 10.0f), 0.5f,2, 2);
	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		par1.update();
		par2.update();
		par3.update();
		window.clear();
		par1.draw(window);
		par2.draw(window);
		par3.draw(window);
		window.display();

	}
	
	return 0;
}
