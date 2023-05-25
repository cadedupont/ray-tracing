#ifndef COLOR_H
#define COLOR_H

#include "main.h"

#include <iostream>

void drawColor(std::ostream& out, color pixelColor, int samplesPerPixel = 1) {
    // Get color of pixel
    float r = pixelColor.getX();
    float g = pixelColor.getY();
    float b = pixelColor.getZ();

    // Divide color by number of samples and gamma correct for gamma = 2.0
    float scale = 1.0f / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write color to output stream
    out << int(256 * clamp(r, 0.0f, 0.999f)) << ' '
        << int(256 * clamp(g, 0.0f, 0.999f)) << ' '
        << int(256 * clamp(b, 0.0f, 0.999f)) << '\n';
}

#endif