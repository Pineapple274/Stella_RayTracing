// camera.h

#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "rtweekend.h"
#include "vec3.h"

class camera{
    public:
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 origin; 

        camera(){
            //viewer
            lower_left_corner = vec3(-2.0, -1.0, -1.0);
            horizontal        = vec3( 4.0,  0.0,  0.0);
            vertical          = vec3( 0.0,  2.0,  0.0);     
            origin            = vec3( 0.0,  0.0,  0.0);
        };
        
        ray get_ray(const double& u, const double& v){
            return ray(origin, lower_left_corner + u * horizontal + v * vertical);
        };

    // public:
   
};

#endif