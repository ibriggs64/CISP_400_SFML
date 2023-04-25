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

ComplexPlane::ComplexPlane(float aspectRatio)
{
    m_aspectRatio = aspectRatio;
    m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio);
    m_view.setCenter(0.0,0.0);
    m_zoomCount = 0;
}
void ComplexPlane::zoomIn()
{
    m_zoomCount++;
    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    float y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
    m_view.setSize(x,y);
}
void ComplexPlane::zoomOut()
{
    m_zoomCount--;
    float x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    float y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
    m_view.setSize(x,y);
}
void ComplexPlane::setCenter(Vector2f coord)
{
    m_view.setCenter(coord);
}
void ComplexPlane::setMouseLocation(Vector2f coord)
{
    m_mouseLocation = coord;
}
void ComplexPlane::loadText(Text& text)
{
    stringstream sstream;
    Text textForCoords;
    sstream << "\nCenter: "; //m_view.getCenter();
    sstream << endl;
    sstream << "Cursor: "; //m_mouseLocation;
    textForCoords.setString(sstream.str());
    text.setString("Mandelbrot Set \n \n \n Left-click to Zoom in \n Right-click to Zoom out");
}
size_t ComplexPlane::countIterations(Vector2f coord)
{

}
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
    
}