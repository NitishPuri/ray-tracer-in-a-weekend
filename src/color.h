#pragma once

#include "vec3.h"

#include <iostream>

struct ImageColor {
    using uchar = unsigned char;
    ImageColor(uchar r, uchar g, uchar b) : rgb{r, g, b} {}
    ImageColor(const color& color) : rgb(){
        rgb[0] = static_cast<uchar>(255.999 * color.x());
        rgb[1] = static_cast<uchar>(255.999 * color.y());
        rgb[2] = static_cast<uchar>(255.999 * color.z());        
    }
    uchar rgb[3];
};

// void write_color(std::ostream& out, color pixel_color) {
//     // Write the translated [0,255] value of each color component.
//     out << static_cast<int>(255.999 * pixel_color.x()) << ' '
//         << static_cast<int>(255.999 * pixel_color.y()) << ' '
//         << static_cast<int>(255.999 * pixel_color.z()) << '\n';    
// }