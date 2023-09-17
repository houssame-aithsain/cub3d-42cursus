#include "cub3d.h"

void *_new_line_remover(char *tmp)
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
	fd = open("map.cub", O_RDONLY);
	src.map = malloc(sizeof(char *) * 200 + 1);
	tmp = get_next_line(fd);
	while (tmp && tmp[0])
	{
		_new_line_remover(tmp);
		src.map[i] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	src.map[i] = NULL;
	//tmp map init
	/*src.map = malloc(sizeof(char *) * 20 + 1);
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
	}*/
	src.map[i] = NULL;
	// end map
	// map printer
	/*i = -1;
	while (src.map[++i])
		printf("%s\n", src.map[i]);
	exit(0);*/
	// end print
	map_drawer(&src);	
	mlx_image_to_window(src.mlx, src.img, 0, 0);
	mlx_loop(src.mlx);
    mlx_terminate(src.mlx);
}
