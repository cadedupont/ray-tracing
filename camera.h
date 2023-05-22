#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"

// Declare class for camera
class camera {
    private:
        // Declare variables for storing camera origin, horizontal, vertical, lower left corner
        position lowerLeftCorner, origin;
        vec3 vertical, horizontal;
    
    public:
        // Default constructor and destructor
        camera();
        ~camera();

        // Declare function for getting ray from camera to pixel
        ray getRay(float u, float v) const;
};

#endif