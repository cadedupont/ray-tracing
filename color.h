#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

void drawColor(std::ostream& out, color pixelColor) {
    out << int(255.999f * pixelColor.getX()) << ' '
        << int(255.999f * pixelColor.getY()) << ' '
        << int(255.999f * pixelColor.getZ()) << '\n';
}

#endif