#include "utils.hpp"
#include "const.hpp"

namespace maze
{
  /**
   * resizeTexture - resize the texture of the maze
   * @texture: The texture to be resized
   * @size: The size of texture.
   * Return: void
  */
  void resizeTexture(std::vector<Uint32>* texture, const int size)
  {
    for (int a = 0; a < size; ++a)
    {
      texture[i].resize(texWidth * texHeight);
    }
  }

}
