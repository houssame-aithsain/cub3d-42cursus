#include "cub3d.h"

void _new_line_remover(char *tmp)
{
	int i;

	i = -1;
	while (tmp && tmp[++i])
	{
		if (tmp[i] == '\n')
			tmp[i] = 0;
	}
}
int main()
{
	int i;
	int x;
	int fd;
	char *tmp;
	t_src src;
	
	i = 0;
	// map reader
	fd = open("map.cub", O_RDONLY);
	src.map = malloc(sizeof(char *) * 200 + 1);
	tmp = get_next_line(fd);
	while (tmp && tmp[0])
	{
		_new_line_remover(tmp);
		src.map[i] = ft_strdup(tmp);
		printf("%s\n", src.map[i]);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	src.map[i] = NULL;
	src.plx = 0;
	src.pa = 90 * (M_PI / 180);
	src.mlx = mlx_init(get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH), "CUB3D", true);
	src.img = mlx_new_image(src.mlx, get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH));
	mlx_loop_hook(src.mlx, &_movement, &src);
	mlx_image_to_window(src.mlx, src.img, 0, 0);
	mlx_loop(src.mlx);
    mlx_terminate(src.mlx);
}
