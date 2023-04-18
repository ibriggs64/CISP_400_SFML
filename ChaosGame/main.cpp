//Iain Briggs. No partner :( did get some help from Jordan M. and Eduardo C.
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
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
    text.setPosition(10,10);
    text.setFillColor(Color::White);
    textForDots = text;
    textForDots.setPosition(10, 1000);
    int dotCounter = 0; //dot counter and initial click counter (dot counter on screen does NOT count initial dots)
    RectangleShape dots;
    dots.setSize( Vector2f (1,1));
    dots.setFillColor(Color::White);
    vector<RectangleShape> dotList;
    bool acceptClicks = true;                
    Vector2f temp,temp2;    
    Color red(255, 0, 0);                      
    Color blue(0, 0, 255);
    Color green(0, 255, 0);
    Color yellow(255, 255, 0);
    Color purple(127, 0, 255);
    Color orange(255,128,0);
    Color teal(0,128,128);
    Color pink(255,192,203);
    Color brown(150,75,0);
    Color aqua(0,255,255);
    vector<Color> rgb = {red, orange, yellow, green, blue, purple, teal, pink, brown, aqua };
    bool isTri = false;
    bool square = false;
    bool pentagon = false;
    bool hexagon = false;
    bool heptagon = false;
    bool octagon = false;
    bool nonagon = false;
    bool decagon = false;
    int rng;

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

        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Q)
            {
                isTri = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::W)
            {
                square = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::E)
            {
                pentagon = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::R)
            {
                hexagon = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::T)
            {
                heptagon = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Y)
            {
                octagon = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::U)
            {
                nonagon = true;
            }
        }
        if(Event::KeyPressed)
        {
            if(event.key.code == Keyboard::I)
            {
                decagon = true;
            }
        }
        //attempted more than 3, had it working, then my entire code somehow got corrupted and I had to restart.
        //esstreamentially lost all that and had to restart from scratch and didnt have the time to do it again
        //can create more than 3 vertices but will still attempt to create the triangle, disregarding the last 2 chosen vertices
        if ( isTri == true && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && dotCounter < 4 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == true && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && dotCounter < 5 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == false && pentagon == true && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && dotCounter < 6 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == true && heptagon == false && octagon == false && nonagon == false && decagon == false && dotCounter < 7 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if ( isTri == false && square == false && pentagon == false && hexagon == false && heptagon == true && octagon == false && nonagon == false && decagon == false && dotCounter < 8 && acceptClicks)                             
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == true && nonagon == false && decagon == false && dotCounter < 9 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == true && decagon == false && dotCounter < 10 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == true && dotCounter < 11 && acceptClicks)                            
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* tempDot = new RectangleShape;       
                x = event.mouseButton.x;                          
                y = event.mouseButton.y;                          
                *tempDot = dots;
                tempDot->setPosition(x, y);                                                     
                dotCounter++;                                 
                acceptClicks = false;                              
                dotList.push_back(*tempDot);                           
            }
        }
        if (isTri == true && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (3);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.5);
                temp.y = lerp(temp.y, temp2.y, 0.5);
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == true && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (4);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.45);
                temp.y = lerp(temp.y, temp2.y, 0.45);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == true && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (5);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.4);
                temp.y = lerp(temp.y, temp2.y, 0.4);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == true && heptagon == false && octagon == false && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (6);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.33);
                temp.y = lerp(temp.y, temp2.y, 0.33);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == true && octagon == false && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (7);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.3);
                temp.y = lerp(temp.y, temp2.y, 0.3);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == true && nonagon == false && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (8);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.28);
                temp.y = lerp(temp.y, temp2.y, 0.28);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == true && decagon == false && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (9);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.25);
                temp.y = lerp(temp.y, temp2.y, 0.25);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == true && Event::KeyPressed) //Press Enter/Return to start process.
        {
            if(event.key.code == Keyboard::Enter)
            {
                RectangleShape* tempDot = new RectangleShape;            
                tempDot->setSize(Vector2f(1,1));
                rng = rand() % (10);
                tempDot->setFillColor(rgb.at(rng));
                temp = dotList.at(rng).getPosition();                     
                temp2 = dotList.at(dotList.size() - 1).getPosition();   
                temp.x = lerp(temp.x, temp2.x, 0.22);
                temp.y = lerp(temp.y, temp2.y, 0.22);  
                tempDot->setPosition(temp);                                
                dotList.push_back(*tempDot);                               
                dotCounter++;
            }
        }
        if (event.type == Event::MouseButtonReleased)     
        {
            acceptClicks = true;
        }
        if(dotCounter == 0 && isTri == false && square == false && pentagon == false && hexagon == false && heptagon == false && octagon == false && nonagon == false && decagon == false)
        {
            text.setString("Chaos Game: \n Q = triangle. \n W = Quadrilateral. \n E = Pentogram. \n R = Hexagon. \n T = Heptagon. \n Y = Octagon. \n U = Nonagon. \n I = Decagon.");
        }
        if(isTri == true && dotCounter < 4)
        {
            text.setString("Triangle: Select 3 vertices. \n Press Enter to start.");
        }
        if(square == true && dotCounter < 5)
        {
            text.setString("Quadrilateral: Select 4 vertices. \n Press Enter to start.");
        }
        if(pentagon == true && dotCounter < 6)
        {
            text.setString("Pentagon: Select 5 vertices. \n Press Enter to start.");
        }
        if(hexagon == true && dotCounter < 7)
        {
            text.setString("Hexagon: Select 6 vertices. \n Press Enter to start.");
        }
        if(heptagon == true && dotCounter < 8)
        {
            text.setString("Heptagon: Select 7 vertices. \n Press Enter to start.");
        }
        if(octagon == true && dotCounter < 9)
        {
            text.setString("Octagon: Select 8 vertices. \n Press Enter to start.");
        }
        if(nonagon == true && dotCounter < 10)
        {
            text.setString("Nonagon: Select 9 vertices. \n Press Enter to start.");
        }
        if(decagon == true && dotCounter < 11)
        {
            text.setString("Decagon: Select 10 vertices. \n Press Enter to start.");
        }
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
//Had some help from others since I had no partner. Helped me with the text output to the screen and the lerp function.