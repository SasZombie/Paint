#include <raylib.h>
#include <memory>
#include <iostream>

class Canvas
{
private:
    Rectangle shape;
    Color backgroundColor;

public:
    Canvas(const float Nx, const float Ny, const float Nwidth, const float Nheight , const Color &Nbackground);

    Rectangle getRec();
    Color getColor();
    
    ~Canvas() = default;
};
