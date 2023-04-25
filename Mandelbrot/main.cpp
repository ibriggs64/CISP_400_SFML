#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
#include <cmath>
#include "ComplexPlane.h"
using namespace sf;
using namespace std;

int main()
{
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    size_t pixels = VideoMode::getDesktopMode().width * VideoMode::getDesktopMode().height;
    float aspectRatio = VideoMode::getDesktopMode().width / VideoMode::getDesktopMode().height;
    RenderWindow window(vm, "Mandelbrot", Style::Default);
    ComplexPlane plane(aspectRatio);
    Font font;
    Text text;
    VertexArray(Points, pixels);
    enum state {CALCULATING, DISPLAYING};
    state(0);
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
            if(event.type == Event::MouseButtonPressed)
            {
                Vector2f mouse = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    plane.zoomIn();
                    plane.setCenter(mouse);
                }
                if(Mouse::isButtonPressed(Mouse::Right))
                {
                    plane.zoomOut();
                    plane.setCenter(mouse);
                }
                state(0);
            }
            if(event.type == Event::MouseMoved)
            {
                Vector2f mouse = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
            }
        }
    }
}