#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	Vector2i screenSize = { 1376, 768 };

	RenderWindow* window = new RenderWindow();
	window->create(VideoMode(screenSize.x, screenSize.y), "Snake", Style::Close);
	window->setFramerateLimit(60);

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}
		}
	}

	return 0;
}