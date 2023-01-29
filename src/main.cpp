
#include "image.h"
#include "ray.h"
#include "vec3.h"
#include "color.h"

#include <string>
#include <iostream>

color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {

    // Image

    const int image_width = 600;
    const int image_height = 500;
    Image image(image_width, image_height);

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i) / (image_width-1), double(j) / (image_height-1), 0.25);

            image.set(i, j, pixel_color);
        }
    }

    image.write("result.bmp");
    
}