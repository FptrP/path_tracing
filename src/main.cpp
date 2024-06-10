#include <iostream>
#include <glm/glm.hpp>

#include <stb_image.h>
#include <stb_image_write.h>

#include "image2d.hpp"

int main()
{
  std::cout << "Hello world!\n";

  rt::cpu::RGBAImage2D target {800, 600};

  for (uint32_t y = 0; y < target.getHeight(); y++)
  {
    for (uint32_t x = 0; x < target.getWidth(); x++)
    {
      target.at(x, y) = glm::vec4(1.f, 0.f, 0.f, 1.f);
    }
  }

  rt::cpu::save_png("test.png", target);
  return 0;
}