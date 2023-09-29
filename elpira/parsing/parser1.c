/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:19:08 by gothmane          #+#    #+#             */
/*   Updated: 2023/09/28 15:39:05 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// #include "../gnl/get_next_line.h"
// #include <fcntl.h>

int ft_strcmp_cub(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

t_dir *ft_lstlast_cub(t_dir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
void ft_lstadd_back_cub(t_dir **lst, t_dir *new)
{
	t_dir *last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast_cub(*lst);
		last->next = new;
	}
}
t_dir *ft_lstnew_cub(char *key, char *value)
{
	t_dir *ls;

	ls = malloc(sizeof(t_dir));
	if (!ls)
		return (0);
	ls->key = ft_strdup(key);
	ls->value = ft_strdup(value);
	ls->next = NULL;
	return (ls);
}

int ft_only_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int ft_check_if_map_starts(char *file)
{
	int i;
	int fd = -1;
	char *line = NULL;
	int c = 0;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0])
		{
			if (ft_only_spaces(line) != 0 && c < 6)
				c++;
			else
			{
				close(fd);
				free(line);
				return (c);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (c);
}

int ft_check_splited(char **sp)
{
	int i = 0;
	
	while (sp[i])
		i++;
	if (i != 2)
		return (1);
	return (0);
}

typedef struct s_utils
{
	char *line;
	t_dir *dir;
	char **splited;
	int i;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int ca;
}				t_utils;


void ft_init_utils_var_as(t_utils *u, int fd)
{
	(*u).i = 0;
	(*u).a = 0;
	(*u).b = 0;
	(*u).c = 0;
	(*u).d = 0;
	(*u).e = 0;
	(*u).f = 0;
	(*u).ca = 0;
	(*u).i = 0;
	(*u).dir = NULL;
	(*u).splited = NULL;
	(*u).line = get_next_line(fd);
}

void	ft_freesplited(char **splited)
{
	int	i;
	int	k;
	
	k = 0;
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int ft_sar(t_utils *u)
{
	if ((*u).line[0] == 'N' && (*u).line[1] == 'O')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "NO") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).a++;
		}
	}
	else if ((*u).line[0] == 'S' && (*u).line[1] == 'O')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "SO") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).b++;
		}
	}
	else if ((*u).line[0] == 'W' && (*u).line[1] == 'E')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "WE") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).c++;
		}
	}
	else if ((*u).line[0] == 'E' && (*u).line[1] == 'A')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "EA") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).d++;
		}
		printf("%d\n", (*u).d);
	}
	else if ((*u).line[0] == 'F')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "F") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).e++;
		}
	}
	else if ((*u).line[0] == 'C')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		(*u).splited = ft_split((*u).line, ' ');
		if ((*u).splited[0] && (*u).splited[1] && ft_strcmp_cub((*u).splited[0], "C") == 0 && ft_check_splited((*u).splited) == 0)
		{
			ft_lstadd_back_cub(&(*u).dir, ft_lstnew_cub((*u).splited[0], (*u).splited[1]));
			(*u).f++;
		}
	}
	else if ((*u).line[0] != ' ')
	{
		if ((*u).splited)
			ft_freesplited((*u).splited);
		printf("There's strange data in the first section of the file ! Abortion\n");
		return (0);
	}
	return (1);
}

t_dir *ft_check_first_lines(int fd, int fl)
{
	t_utils u;
	
	ft_init_utils_var_as(&u, fd);
	if (!(u).line)
		return (NULL);
	while ((u).ca < 6 && (u).line && ft_only_spaces((u).line) != 0)
	{
		if (((u).line[0] && (u).line[1]) || (u).line[0] == ' ')
		{
			if (ft_sar(&u) == 0)
			{
				free(u.line);
				return (NULL);
			}
		}
		if ((u).ca < 5)
		{
			free(u.line);
			(u).line = get_next_line(fd);
		}
		if ((u).line && (u).line[0] != '\n')
			(u).ca++;
		if (!(u).line || (((u).a + (u).b + (u).c + (u).d + (u).e + (u).f) == 6 &&
					  ((u).a != 0 && (u).b != 0 && (u).c != 0 && (u).d != 0 && (u).e != 0 && (u).f != 0) && ((u).ca) == fl))
					  {
						ft_freesplited((u).splited);
						free(u.line);
						return ((u).dir);
					  }
	}
	return (NULL);
}

int	ft_count_the_map(char *name)
{
	int	i;
	
	i = 0;
	char *line= NULL;
	int nbr  = 0;
	int fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	nbr++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		nbr++;
	}
	free(line);
	return (nbr);
}

char **ft_get_map_2d(int fd)
{
	char **map = NULL;
	int i = 1;

	map = malloc(sizeof(char *) * ft_count_the_map("map.cub") + 1);
	map[0] = get_next_line(fd);

	while (map[0] && map[0][0] == '\n')
	{
		free(map[0]);
		map[0] = get_next_line(fd);
	}
	i--;
	while (map[i])
	{
		map[i + 1] = get_next_line(fd);
		i++;
	}
	// i--;
	// if (map[i - 1][ft_strlen(map[i - 1]) - 1] == '\n')
	// 	return (NULL);
	// printf("1 => MAAAAAAAAAAAAAAAAAAAAAAAAAAAAP\n");
	// i = 0;
	// while (map[i])
	// {
	// 	printf("%s", map[i]);
	// 	printf(" i = %d\n", i);
	// 	i++;
	// }
	// printf(" i = %d | map (%c)\n", i, map[i - 1][ft_strlen(map[i - 1]) - 1]);
	// if (!map[i - 1])
	// {
	// 	printf("test\n");
	// }
	if (i > 0 && map[i - 1][ft_strlen(map[i - 1]) - 1] == '\n')
		return (NULL);
		// printf("1 => END MAAAAAAAAAAAP\n");
	return (map);
}



int ft_check_for_new_line(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int ft_check_map_2d(char **map)
{
	int i = 0;
	int j = 0;
	int size = 0;
	int main_size = 0;

	while (map[i])
	{
		j = 0;
		if (map[i + 1])
			size = ft_strlen(map[i + 1]);
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (ft_check_for_new_line(map[i]) == 1)
					main_size = j - 1;
				if ((size > 0 && main_size > 0 && size < main_size) 
				|| (map[i][j + 1] && map[i][j + 1] == ' ') 
				|| ((map[i + 1] && map[i + 1][j] == ' ') 
				|| (map[i + 1] && map[i + 1][j] == '\n')) 
				|| (i > 0 && (!map[i - 1][j] || (map[i - 1][j] && map[i - 1][j] == ' ')))
				|| (map[i][j - 1] && map[i][j - 1] == ' ') 
				|| ((map[i - 1] && map[i - 1][j] == ' ') 
				|| (map[i - 1] && map[i - 1][j] == '\n')))
				{
					printf("LKHWA ERROR\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}

	return (0);
}

int ft_count_2d(char **map)
{
	int i = 0;

	while (map[i])
		i++;
	return (i);
}

int ft_detect_pos_of_player(char **map)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])		
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'O')
			{
				if (i > 0 && map[i - 1][j] && (map[i - 1][j] == ' ' || map[i - 1][j] == '\n'))
					return (-1);
				if (i > 0 && map[i + 1][j] && (map[i + 1][j] == ' ' || map[i + 1][j] == '\n'))
					return (-1);
				if (i > 0 && map[i][j - 1] && (map[i][j - 1] == ' ' || map[i][j - 1] == '\n'))
					return (-1);
				if (i > 0 && map[i][j + 1] && (map[i][j + 1] == ' ' || map[i][j + 1] == '\n'))
					return (-1);
				else if (!map[i][j + 1] || !map[i][j - 1] || !map[i + 1][j] || !map[i - 1][j])
					return (-2);
			}	
			j++;
		}
		i++;
		
	}
	return (0);
}

int ft_check_wrapper(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0 || i == (ft_count_2d(map) - 1))
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == '0' || map[i][j] == 'N' 
					|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int ft_check_sides_map(char **map)
{
	int i;
	int j;
	int last_idx = 0;

	i = 0;
	j = 0;
	while (map[i])
	{
		last_idx = ft_strlen(map[i]) - 1;
		if ((last_idx > 0 && map[i][0] && (map[i][0] != '1' && map[i][0] != ' ')) 
			|| (map[i][last_idx - 1] != '1' && map[i][last_idx - 1] != ' '))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_check_for_diff_chars(char **map)
{
	int i = 0;
	int j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' 
			&& map[i][j] != ' ' && map[i][j] != '\n' 
			&& map[i][j] != 'N' && map[i][j] != 'S' 
			&& map[i][j] != 'E' && map[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_check_player_dup(char **map)
{
	int i = 0;
	int j = 0;
	int existing = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				existing++;
			j++;
		}
		i++;
	}
	if (existing == 1)
		return (0);
	return (1);
}



int ft_check_first_data_section(t_dir *dir)
{
	t_dir *tmp;

	tmp = dir;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->next && (ft_strcmp_cub(tmp->key, tmp->next->key) == 0))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int ft_rbg_checker(t_dir *dir)
{
	int i;

	i = 0;
	while (dir)
	{
		printf(" =>>>>>> key = %s\n", dir->key);
		if (dir->key && dir->value && (dir->key[0] == 'F' || dir->key[0] == 'C'))
		{
			i = 0;
			while (dir->value[i])
			{
				if (ft_isdigit(dir->value[i]) != 1
					&& dir->value[i] != ',' && dir->value[i] != '\n')
					return (-1);
				i++;
			}
		}
		dir = dir->next;
	}
	return (0);
}

int ft_rbg_comma(t_dir *dir)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	while (dir)
	{
		if (dir->key && dir->value 
			&& (dir->key[0] == 'F' || dir->key[0] == 'C'))
		{
			i = 0;
			while (dir->value[i])
			{
				if (i > 0 && dir->value[i] == ',' 
					&&( ft_isdigit(dir->value[i + 1]) != 1
					|| ft_isdigit(dir->value[i - 1]) != 1))
					{
						return (-1);
					}
				else if (i == 0 && dir->value[0] == ',')
					return (-2);
				else if (dir->value[i] == ',')
					comma++;
				i++;
			}
		}
		dir = dir->next;
	}

	return (comma);
}

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}			t_rgb;

t_rgb	ft_rgb(char *rgb)
{
	t_rgb rg;
	char **splited = ft_split(rgb, ',');
	int i = 0;
	rg.r = 0;
	rg.g = 0;
	rg.b = 0;
	while (splited[i])
		i++;
	if (i == 3)
	{
		rg.r = ft_atoi(splited[0]);
		rg.g = ft_atoi(splited[1]);
		rg.b = ft_atoi(splited[2]);
	}
	return (rg);
}

unsigned int rgb_to_int(unsigned char r, unsigned char g, unsigned char b) {
    // Ensure the RGB values are within the valid range
    if (r > 255) {
        r = 255;
    } else if (r < 0) {
        r = 0;
    }
    if (g > 255) {
        g = 255;
    } else if (g < 0) {
        g = 0;
    }
    if (b > 255) {
        b = 255;
    } else if (b < 0) {
        b = 0;
    }

    // Shift and combine the RGB values into a single integer
    return ((unsigned int)r << 16) | ((unsigned int)g << 8) | (unsigned int)b;
}


char	ft_player_direction(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
                return ('N');
            if (map[i][j] == 'S')
                return ('S');
            if (map[i][j] == 'E')
                return ('E');
            if (map[i][j] == 'W')
                return ('W');
            j++;
		}
		i++;
	}
	return (0);
}


t_cub3d *ft_parser_cub3d(char *v)
{
	int fd;
	t_dir *dir = NULL;
	t_cub3d *cub = NULL;
	int nbr_start = 0;
	// int i = 0;
	
	cub = malloc(sizeof(t_cub3d));
	nbr_start = ft_check_if_map_starts(v);
	fd = open(v, O_RDONLY);
	if (fd == -1)
		return (0);
	dir = ft_check_first_lines(fd, nbr_start);
	cub->map = ft_get_map_2d(fd);

	if (dir == NULL)
	{
		printf("The dir array that holds data related to he map is empty ! Check for errors in the data or the file !!\n");
		return (0);
	}
	if (!cub->map)
	{
		exit(0);
		return (0);
	}

	cub->ka = 0;
	cub->sides = 0;
	cub->wrapper = 0;
	cub->weird_ins = 0;
	cub->player_checker = 0;
	cub->dup = 0;
	cub->rgb = -1;
	cub->cm = 0;
	cub->pos = 0;
	cub->player_dir = 0;
	
	cub->pos = ft_detect_pos_of_player(cub->map);
	cub->dup = ft_check_first_data_section(dir);
	cub->weird_ins = ft_check_for_diff_chars(cub->map);
	cub->wrapper = ft_check_wrapper(cub->map);
	cub->sides = ft_check_sides_map(cub->map);
	cub->cm = ft_rbg_comma(dir);
	cub->player_dir = ft_player_direction(cub->map);
	if (cub->cm == 4)
	{
		printf("****** Checking RGB *******\n");
		cub->rgb = ft_rbg_checker(dir);
	}
	if (cub->sides == 0 && cub->wrapper == 0)
		cub->ka = ft_check_map_2d(cub->map);
	cub->player_checker = ft_check_player_dup(cub->map);
	
	if (cub->ka != 0 || cub->sides != 0 || cub->wrapper != 0
		|| cub->weird_ins != 0 || cub->player_checker != 0
		|| cub->dup != 0 || cub->rgb != 0 || cub->cm != 4
		|| cub->pos != 0 || cub->player_dir ==  0) 
		return (0);
	// printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAP\n");
	// while (cub->map[i])
	// {
	// 	printf("%s", cub->map[i]);
	// 	i++;
	// }
	// printf("END MAAAAAAAAAAAP\n");
	// printf("\n\n\n\n");
	printf("#########################\n");
	printf("====== SUMMARY ======\n");
	printf("RBG = %d\n", cub->rgb);
	printf("cm= %d\n", cub->cm);
	printf("dup = %d\n", cub->dup);
	printf("weird_ins = %d\n", cub->weird_ins);
	printf("sides = %d\n", cub->sides);
	printf("check for khwa = %d\n", cub->ka);
	printf("wrapper = %d\n", cub->wrapper);
	printf("player_checker = %d\n", cub->player_checker);
	printf("player position checker = %d\n", cub->pos);
	printf("player dir = %d\n", cub->player_dir);
	printf("#########################\n");
	return (cub);
}

// int main()
// {
//     // int        i;
//     // int        x;
//     // int        fd;
//     // char    *tmp;
//     t_cub3d    *cub;
//     // t_src    src;
    
//     // i = 0;
//     // fd = open("map.cub", O_RDONLY);
//     // src.map = malloc(sizeof(char *) * 14 + 1);
//     // tmp = get_next_line(fd);
//     // while (tmp && tmp[0])
//     // {
//     //     _new_line_remover(tmp);
//     //     src.map[i] = ft_strdup(tmp);
//     //     free(tmp);
//     //     tmp = get_next_line(fd);
//     //     i++;
//     // }
//     // src.map[i] = NULL;
//     // free(tmp);
//     // close(fd);
//     cub = ft_parser_cub3d("map.cub");
//     printf("##################[checked now]##############\n");
//     printf("%s\n", cub->map[0]);
//     exit(0);
//     if (!cub->map)
//         exit(0);
//     // src.map = cub->map;
//     // src.plx = 0;
//     // src.pa = 90 * (M_PI / 180);
//     // src.mlx = mlx_init(get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH), "CUB3D", true);
//     // src.img = mlx_new_image(src.mlx, get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH));
//     // src.rays = malloc(sizeof(ray) * src.img->width + 1);
//     // i = -1;
//     // while (++i <= src.img->width)
//     //     src.rays[i].distance = -1;
//     // mlx_loop_hook(src.mlx, &walk_direction, &src);
//     // mlx_image_to_window(src.mlx, src.img, 0, 0);
//     // mlx_loop(src.mlx);
//     // mlx_terminate(src.mlx);
//     // return (EXIT_SUCCESS);
// }
