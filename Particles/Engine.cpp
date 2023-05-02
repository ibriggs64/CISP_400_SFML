#include "Engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "Particles", Style::Default);
}

void Engine::run()
{
    Clock clock;
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    while(m_Window.isOpen())
    {
        Time elapsed1 = clock.restart();
        input();
        update(elapsed1.asSeconds());
        draw();
    }
}

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            m_Window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
        if(event.type == Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == Mouse::Left)
            {
                Vector2f coord;
                coord = m_Window.mapPixelToCoords(Mouse::getPosition());
                for(int i = 0; i < 5; i++)
                {
                    float numPoints = 25 + (rand() % 50);
                    Particle p2(m_Window, numPoints, coord);
                    m_particles.push_back(p2);
                }
            }
        }
    }
}

void Engine::update(float dtAsSeconds)
{
    for(int i = 0; i < m_particles.size(); i++)
    {
        if(p2.getTTL() > 0.0)
        {
            m_particles.at(i).update(i);
        }
        else
        {
            
        }
    }
}

void Engine::draw()
{
    m_Window.clear();
    for(int i = 0; i < m_particles.size(); i++)
    {
        m_Window.draw(m_particles.at(i));
    }
    m_Window.display();
}