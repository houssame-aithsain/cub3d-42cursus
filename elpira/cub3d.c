#include "cub3d.h"

int main()
{
	int			i;
	int			x;
	void		*mlx;
	void		*mlx_win;
	mlx_image_t	*img;
	char map[5][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};

	x = -1;
	mlx = mlx_init(1000, 1000, "CUB3D", true);
	img = mlx_new_image(mlx, 256, 256);
	while (++x < 50)
	{
		i = -1;
		while (++i < 50)
			mlx_put_pixel(img, x, i, 0xFF0000FF);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
    mlx_terminate(mlx);
}
