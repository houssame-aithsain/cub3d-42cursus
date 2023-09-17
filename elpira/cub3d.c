#include "cub3d.h"

int main()
{
	int i;
	int x;
	t_src src;
	
	i = -1;
	//tmp map init
	src.map = malloc(sizeof(char *) * 20 + 1);
	while (++i < 20)
	{
		x = -1;
		src.map[i] = malloc(sizeof(char) * 20 + 1);
		while (++x < 20)
		{
			if (!i || i == 19 || !x || x == 19)
				src.map[i][x] = '1';
			else
				src.map[i][x] = '0';
		}
		src.map[i][x] = 0;
	}
	src.map[i] = NULL;
	// end map
	// map printer
	i = -1;
	/*while (src.map[++i])
		printf("%s\n", src.map[i]);
	exit(0);*/
	// end print
	map_drawer(&src);	
	mlx_image_to_window(src.mlx, src.img, 0, 0);
	mlx_loop(src.mlx);
    mlx_terminate(src.mlx);
}
