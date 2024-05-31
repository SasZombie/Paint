#include "canvas.hpp"
#include <raylib.h>

Canvas::Canvas(const float Nx, const float Ny, const float NWidth, const float NHeight, const Color &Nbackground)
    : backgroundColor(Nbackground)
{
    shape.x = Nx;
    shape.y = Ny;
    shape.width = NWidth;
    shape.height = NHeight;

}


Rectangle Canvas::getRec()
{
    return shape;
}


Color Canvas::getColor()
{
    return backgroundColor;
}