#include "image2d.hpp"

#include <stb_image.h>
#include <stb_image_write.h>
#include <stdexcept>

namespace rt::cpu
{

void save_png(const std::string &name, const RGBAImage2D &image)
{
  int res = stbi_write_png(name.c_str(), 
    (int)image.getWidth(), 
    (int)image.getHeight(), 
    4, 
    image.rawPtr(), image.getWidth() * sizeof(RGBAImage2D::Type));
  
  if (!res)
    throw std::runtime_error{"Image save error"};
}

}