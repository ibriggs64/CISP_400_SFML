//Iain Briggs. No partner :(
#include <iostream>
#include <sstreamtream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main()
{
    VideoMode vm(1920, 1080);                        
    RenderWindow window(vm, "Chaos Game", Style::Fullscreen);

    Text text, textForDots;                               
    Font font;
    font.loadFromFile("fonts/arial.ttf");        
    text.setFont(font);
    text.setCharacterSize(25);
    text.setPosition(10,10);
    text.setFillColor(Color::White);
    textForDots = text;
    textForDots.setPosition(10, 140);

    int dotCounter = 0, initialDotCounter = 0; //dot counter and initial click counter (dot counter on screen does NOT count initial dots)
    RectangleShape dots;
    dots.setSize( Vector2f (1,1));
    dots.setFillColor(Color::White);
    vector<RectangleShape> dotList;
    int rng, rng2, rng3; //had multiple to attempt at getting more than 3 vertices again. Failed.
    bool acceptInput = true;                
    Vector2f temp,temp2;    
    Color pink(255, 0, 0);                      
    Color blue(0, 0, 255);
    Color green(0, 255, 0);
    Color yellow(150, 150, 0);
    Color purple(150, 0, 150);

    while (window.isOpen())    
    {
        int x,y; 
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) 
        {
            window.close();
        }
        //attempted more than 3, had it working, then my entire code somehow got corrupted and I had to restart.
        //esstreamentially lost all that and had to restart from scratch and didnt have the time to do it again
        //can create more than 3 vertices but will still attempt to create the triangle, disregarding the last 2 chosen vertices
        if (acceptInput && initialDotCounter<5)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* ndot = new RectangleShape;          //new dot
                x = event.mouseButton.x;                            //GET X THEN Y
                y = event.mouseButton.y;                           
                *ndot = dots;
                ndot->setPosition(x, y);                            //SET DOT X,Y                              
                initialDotCounter++;                                       //INCREMENT
                acceptInput = false;                                //AVOID 100 MPH
                dotList.push_back(*ndot);                           //Push in vector
            }
        }
        if (dotCounter >= 6 || Keyboard::isKeyPressed(Keyboard::Return)) //Press Enter/Return to start process.
        {
            RectangleShape* ndot = new RectangleShape;            
            ndot->setSize(Vector2f(1,1));
            rng = rand() % (3);
            if (rng == 0)
            {
                ndot->setFillColor(green);
                temp = dotList.at(0).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = temp.x + temp2.x;                              
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;                                    
                ndot->setPosition(temp);                                
                dotList.push_back(*ndot);                               
                dotCounter++;
            }
            else if (rng == 1)                                          
            {
                ndot->setFillColor(blue);
                temp = dotList.at(1).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = temp.x + temp2.x;
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;
            }
            else if (rng == 2)
            {   
                ndot->setFillColor(purple);
                temp = dotList.at(2).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = temp.x + temp2.x;
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;
            }
        }
        if (event.type == Event::MouseButtonReleased)     
        {
            acceptInput = true;
        }
        text.setString("Welcome to Chaos Game! \n Choose 3 points for triangle. \n Choose 4 points for Quadrilateral. \n Choose 5 points for Pentogram. \n Press Enter when ready to start.");
        stringstream sstream;
        sstream << "Amount of dots: " << dotCounter;
        textForDots.setString(sstream.str());         
        window.clear();                                            
        window.draw(text);
        window.draw(textForDots);
        for (int i = 0;i < dotList.size();i++)     
        {
            window.draw(dotList.at(i));
        }
        window.display();
    }
}
//Had some help from others since I had no partner. Helped me with the text output to the screen.