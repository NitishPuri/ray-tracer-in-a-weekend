#pragma once

#include "color.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include <string>

class Image
{
public:
    Image(int w, int h) : width(w), height(h)
    {
        data = (unsigned char *)malloc(width * height * 3);
    }
    ~Image()
    {
        if (data)
        {
            free(data);
            data = nullptr;
        }
    }

    void Image::set(int x, int y, ImageColor color)
    {
        if (!data || x < 0 || y < 0 || x >= width || y >= height)
        {
            return;
        }

        memcpy(data + (x + y * width) * num_components, color.rgb, num_components);
    }

    // Color get(int x, int y) const {
    //     Color c {};
    //     c.rgb[0] = data[x + y * width + 0];
    //     c.rgb[1] = data[x + y * width + 1];
    //     c.rgb[2] = data[x + y * width + 2];
    //     return c;
    // }

    int write(const std::string &filename, bool flip = true)
    {
        stbi_flip_vertically_on_write(1);
        return stbi_write_jpg(filename.c_str(), width, height, num_components, data, 95);
        // return stbi_write_bmp(filename.c_str(), width, height, num_components, data);
    }

private:
    unsigned char *data = nullptr;
    int width = 0;
    int height = 0;
    const int num_components = 3;
};
