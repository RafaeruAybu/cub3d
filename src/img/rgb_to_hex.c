#include "../cub3d.h"

int	rgb_to_hex(int t, int r, int g, int b)
{
	int	ret;

	ret = t << 24 | r << 16 | g << 8 | b;
	return (ret);
}
