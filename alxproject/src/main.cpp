#include "utils.hpp"

/**
 * main - entry point to main
 * @ar: argument count
 * @arv: argument vector
 * @env: env
 * Return: 0 on success, otherwise 1 on failure
 */
int main(int ar, char **arv, char **env)
{
  double posX = 22, posY = 12;      /* X and Y start positions */
  double dirX = -1, dirY = 0;       /* Initial direction vector */
  double planeX = 0, planeY = 0.66; /* The 2d raycaster version of camera plane */

  double time = 0;    /* Time of current frame */
  double oldTime = 0; /* Time of previous frame */

  std::vector<Uint32> texture[11];
  maze::resizeTexture(*texture, 11);
  maze::generateStructures();

  return (0);
}
