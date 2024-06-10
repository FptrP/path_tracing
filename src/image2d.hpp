#ifndef IMAGE2D_HPP_INCLUDED
#define IMAGE2D_HPP_INCLUDED

#include <vector>
#include <cstdint>
#include <glm/glm.hpp>
#include <string>
#include <cassert>

namespace rt::cpu
{

template <typename PixelT>
class Image2D
{
public:

  using Type = PixelT;

  Image2D(uint32_t w, uint32_t h)
    : width {w}, height {h}
  {
    data.resize(width * height);
  }

  uint32_t getWidth() const { return width; }
  uint32_t getHeight() const { return height; }

  const PixelT &at(uint32_t x, uint32_t y) const
  {
    assert(x < width && y < height);
    return data[y * width + x];
  }

  PixelT &at(uint32_t x, uint32_t y)
  {
    assert(x < width && y < height);
    return data[y * width + x];
  }

  const PixelT *rawPtr() const { return data.data(); }
  PixelT *rawPtr() { return data.data(); }

private:
  uint32_t width, height;
  std::vector<PixelT> data;
};

using RGBAImage2D = Image2D<glm::u8vec4>;
using F4Image2D = Image2D<glm::vec4>;

void save_png(const std::string &name, const RGBAImage2D &image);

}

#endif