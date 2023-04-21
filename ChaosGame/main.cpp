//Iain Briggs. No partner. Everything in this file. Availability for infinite vertices. Choices for distance factor given.
//Up to 20 vertices looks fine on the lowest distance factor given. Anything past ends up turning into a blob for obvious reasons.
//Vertices are placed as white dots while the chaos dots are purple.

#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

int main()
{
    VideoMode vm(1920, 1080);                        
    RenderWindow window(vm, "Chaos Game", Style::Default);
    Text text, textForDots;                               
    Font font;
    font.loadFromFile("fonts/arial.ttf");        
    text.setFont(font);
    text.setCharacterSize(18);
    text.setPosition(5,5); //top left corner
    text.setFillColor(Color::White);
    textForDots = text;
    textForDots.setPosition(5, 840); //bottom left corner (in my presentation it shows it higher, my monitor is based as 2560 x 1440 so it places it according to my monitor resolution not the resolution I place it to.)
    int dotCounter = 0; //counts dots and to send to bottom left corner
    RectangleShape dots;
    dots.setSize( Vector2f (2,2));
    Color red(255, 0, 0), blue(0, 0, 255), green(0, 255, 0), yellow(255, 255, 0), purple(127, 0, 255), orange(255,128,0), teal(0,128,128), pink(255,192,203), brown(150,75,0), aqua(0,255,255);
    vector<Color> rgb{red,orange,yellow,green,teal,blue,purple,pink,aqua,brown};
    dots.setFillColor(Color::White);               
    Vector2f temp,temp2;    
    int add_points_count = 10;
    vector<RectangleShape> points;
    bool is_points_input_end = false;
    bool mouse_left_pressed = false;
    float f = 0.5;
    vector<RectangleShape> initial_points;
    int rng;
    while(window.isOpen())
    {
        int x,y;
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed) window.close();
        }
        window.clear();
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Q)
            {
                f = 0.5;
            }
            if(event.key.code == Keyboard::W)
            {
                f = 0.45;
            }
            if(event.key.code == Keyboard::E)
            {
                f = 0.4;
            }
            if(event.key.code == Keyboard::R)
            {
                f = 0.375;
            }
            if(event.key.code == Keyboard::T)
            {
                f = 0.33;
            }
            if(event.key.code == Keyboard::Y)
            {
                f = 0.3;
            }
            if(event.key.code == Keyboard::U)
            {
                f = 0.25;
            }
            if(event.key.code == Keyboard::I)
            {
                f = 0.2;
            }
            if(event.key.code == Keyboard::O)
            {
                f = 0.15;
            }
            if(event.key.code == Keyboard::P)
            {
                f = 0.1;
            }
        }
        if(!is_points_input_end)
        {
            if(event.type == Event::MouseButtonPressed && !mouse_left_pressed)
            {
                mouse_left_pressed = true;
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                RectangleShape* tempDot = new RectangleShape;
                *tempDot = dots;
                tempDot->setPosition(x,y);
                dotCounter++;
                initial_points.push_back(*tempDot);
                points.push_back(*tempDot);
            }
            if(Keyboard::isKeyPressed(Keyboard::Return))
            {
                is_points_input_end = true;
            }

            if(mouse_left_pressed && event.type == Event::MouseButtonReleased)
            {
                mouse_left_pressed = false;
            }

        }
        else
        {
            int n = initial_points.size();
            for(float i=0; i < add_points_count; i++)
            {
                RectangleShape* tempDot = new RectangleShape;
                rng = rand() % (n);
                tempDot->setSize(Vector2f(1.5,1.5));
                temp = points.at(rng).getPosition();
                temp2 = points.at(points.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, f);
                temp.y = lerp(temp.y, temp2.y, f);
                tempDot->setPosition(temp);
                tempDot->setFillColor(purple);
                points.push_back(*tempDot);
                dotCounter++;
            }
        }
        if(dotCounter == 0)
        {
            text.setString("Chaos Game: \n Q = 0.5 distance factor. \n W = 0.45 distance factor. \n E = 0.4 distance factor. \n R = 0.375 distance factor. \n T = 0.33 distance factor. \n Y = 0.3 distance factor. \n U = 0.25 distance factor. \n I = 0.2 distance factor. \n O = 0.15 distance factor. \n P = 0.1 distance factor.");
        }
        if(dotCounter > 0)
        {
            text.setString("Create as many vertices as you want. \n Press Enter when you are ready to start.");
        }
        stringstream sstream;
        sstream << "Amount of dots: " << dotCounter;
        textForDots.setString(sstream.str());         
        window.clear();                                            
        window.draw(text);
        window.draw(textForDots);
        for (float i = 0;i < points.size();i++)     
        {
            window.draw(points.at(i));
        }
        window.display();
        if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
    }
    return 0;
}