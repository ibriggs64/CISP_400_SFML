//Iain Briggs. No partner. Mandelbrot Set

#include "ComplexPlane.h"
using namespace std;
using namespace sf;

int main()
{
	float aspectRatio;
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	aspectRatio = resolution.y / resolution.x;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Mandelbrot", Style::Default);
	ComplexPlane plane(aspectRatio);
	Text text;	
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.TTF");
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(50, 50);
	text.setFillColor(Color::Red);
	VertexArray background;
	background.setPrimitiveType(Points);
	background.resize(resolution.x * resolution.y);
	enum action { CALCULATING, DISPLAYING };
	action now = CALCULATING;
	while (window.isOpen())
	{
		Vector2f coord, vcoord;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) 
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) 
            {
				if (event.mouseButton.button == Mouse::Left) 
                {
					plane.zoomIn();
					coord = window.mapPixelToCoords(Mouse::getPosition(), plane.getView());
					plane.setCenter(coord);
					now = CALCULATING;
				}
				if (event.mouseButton.button == Mouse::Right) 
                {
					plane.zoomOut();
					coord = window.mapPixelToCoords(Mouse::getPosition(), plane.getView());
					plane.setCenter(coord);
					now = CALCULATING;
				}
			}
			if (event.type == sf::Event::MouseMoved) 
            {
				vcoord = window.mapPixelToCoords(Mouse::getPosition(), plane.getView());
				plane.setMouseLocation(vcoord);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (now == CALCULATING)
		{
			for (float j = 0; j < resolution.x; j++)
			{
				for (float i = 0; i < resolution.y; i++)
				{
					background[j + i * resolution.x].position = { (float)j,(float)i };
					float counter = 0;
					Vector2i coord(j, i);
					Vector2f worldCord;
					worldCord = window.mapPixelToCoords(coord, plane.getView());
					counter = plane.countIterations(worldCord);
					Uint8 r, g, b;
					plane.iterationsToRGB(counter, r, g, b);
					background[j + i * resolution.x].color = { r,g,b };
				}
			}
			now = DISPLAYING;
		}
		plane.loadText(text);
		window.clear();
		window.draw(background);
		window.draw(text);
		window.display();
	}
}