#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <unistd.h>
#include "RectangleShape.hpp"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

/*void glVertex2v(RectangleShape v) //Mouse vector coords
{
    glVertex2f(v.x, v.y);
}

void drawVectorPoints(vector<RectangleShape> *v) //Function for adding Vertex points. Any amount is available.
{
    glBegin(GL_POINTS);
    for(int i=0; i<v->size(); i++)
        glVertex2v(v->at(i));
    glEnd();
}*/

void addPoints(vector<RectangleShape> *initial_points, vector<RectangleShape> *points, int add_points_count) //Chaos part, adds points at random in between vertexes
{
    for(int i=0; i<add_points_count; i++)
        {
            int rand_point = rand()%initial_points->size();

            RectangleShape new_point = (points->at(points->size()-1) + 2.0*initial_points->at(rand_point))/3.f;

            points->push_back(new_point);
        }
}

void addMiddlePoints(vector<RectangleShape> *points) //For extra function of adding instant midpoints between vertexes before starting the run
{
    int points_count = points->size();

    for(int i=0; i<points_count-1; i++)
    {
        RectangleShape middle = (points->at(i) + points->at(i+1))/2.0;
        points->push_back(middle);
    }

    RectangleShape middle = (points->at(0) + points->at(points_count-1))/2.0;
    points->push_back(middle);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    vector<RectangleShape> initial_points;

    float delay = 100;

    int add_points_count = 5;
    if(argc > 1)
        add_points_count = atoi(argv[1]);

    Clock delay_timer;

    vector<RectangleShape> points;

	VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Chaos Game", Style::Fullscreen);

    bool point_input_done = false;
    bool left_click_pressed = false;
    bool space_pressed = false;

	RectangleShape dot1;
	dot1.setSize(Vector2f(1,1));
	dot1.setFillColor(Color::White);
	int rng;

	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	Text text;
	text.setFont(font);
	text.setString("Hello World");
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::White);
	text.setOutlineThickness(3.f);
	text.setCharacterSize(100);
	FloatRect text_rect = text.getLocalBounds();
	text.setOrigin(floorf(text_rect.left + text_rect.width/5),floorf(text_rect.top + text_rect.height/5)); //sets origin of text
	text.setPosition(50,50);
	

    while(window.isOpen())
    {
		int x,y;
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
		}

        if(!point_input_done)
        {
            if(event.type == Event::MouseButtonPressed && !left_click_pressed)
            {
				x = event.mouseButton.x;
				y = event.mouseButton.y;
				RectangleShape* ndot = new RectangleShape;
				*ndot = dot1;
				ndot->setPosition(x,y);
                initial_points.push_back(*ndot);
				left_click_pressed = true;
            }

            if(Keyboard::isKeyPressed(Keyboard::Space) && !space_pressed)
            {
                addMiddlePoints(&initial_points);
                space_pressed = true;
            }

            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                point_input_done = true;
            }

            if(left_click_pressed && !Mouse::isButtonPressed(Mouse::Left))
                left_click_pressed = false;

            if(space_pressed && !Keyboard::isKeyPressed(Keyboard::Space))
                space_pressed = false;

            //drawVectorPoints(&initial_points);
        }
        else
        {
            if(delay_timer.getElapsedTime().asMicroseconds() > delay)
            {
                addPoints(&initial_points, &points, add_points_count);

                delay_timer.restart();
            }
			

            //drawVectorPoints(&initial_points);
            //drawVectorPoints(&points);
        }
		window.draw(text);
        window.display();
        //usleep(10000);

        if(Keyboard::isKeyPressed(Keyboard::Q)) window.close();
    }

    return 0;
}