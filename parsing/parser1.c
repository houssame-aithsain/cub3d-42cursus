/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:19:08 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/03 19:58:10 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		if (str[i] == ' ' && str[i] != '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_close_nd_free(char *line, int fd)
{
	close(fd);
	free(line);
}

typedef	struct s_checkfile
{
	int		i;
	int		fd;
	char	*line;
	int		c;
}		t_checkfile;

int ft_check_if_map_starts(char *file)
{
	t_checkfile	cf;

	cf.i = 0;
	cf.c = 0;
	cf.fd = open(file, O_RDONLY);
	if (cf.fd == -1)
		return (0);
	cf.line = get_next_line(cf.fd);
	while (cf.line)
	{
		if (cf.line[0])
		{
			if (ft_only_spaces(cf.line) != 0 && cf.c < 6)
				cf.c++;
			else
			{
				ft_close_nd_free(cf.line, cf.fd);
				return (cf.c);
			}
		}
		free(cf.line);
		cf.line = get_next_line(cf.fd);
	}
	ft_close_nd_free(cf.line, cf.fd);
	return (cf.c);
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



void ft_init_utils_var_as(t_utils *u, int fd)
{
	(u)->i = 0;
	(u)->a = 0;
	(u)->b = 0;
	(u)->c = 0;
	(u)->d = 0;
	(u)->e = 0;
	(u)->f = 0;
	(u)->ca = 0;
	(u)->i = 0;
	(u)->dir = NULL;
	(u)->splited = NULL;
	(u)->line = get_next_line(fd);
}

void	ft_freesplited(char **splited)
{
	int	i;
	int	k;
	
	k = 0;
	i = 0;
	if (!splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	ft_sp_utils(t_utils	*u, char *key, int *a)
{
	if ((u)->splited)
			ft_freesplited((u)->splited);
	(u)->splited = ft_split((u)->line, ' ');
	if ((u)->splited[0] && (u)->splited[1] 
		&& ft_strcmp_cub((u)->splited[0], key) == 0 
		&& ft_check_splited((u)->splited) == 0)
	{
		ft_lstadd_back_cub(&u->dir, 
			ft_lstnew_cub((u)->splited[0], (u)->splited[1]));
		(*a) = (*a) + 1;
	}
}

int ft_sar(t_utils *u)
{
	if ((u)->line[0] == 'N' && (u)->line[1] == 'O')
		ft_sp_utils(u, "NO", &u->a);
	else if ((u)->line[0] == 'S' && (u)->line[1] == 'O')
		ft_sp_utils(u, "SO", &u->b);
	else if ((u)->line[0] == 'W' && (u)->line[1] == 'E')
		ft_sp_utils(u, "WE", &u->c);
	else if ((u)->line[0] == 'E' && (u)->line[1] == 'A')
		ft_sp_utils(u, "EA", &u->d);
	else if ((u)->line[0] == 'F')
		ft_sp_utils(u, "F", &u->e);
	else if ((u)->line[0] == 'C')
		ft_sp_utils(u, "C", &u->f);
	else if ((u)->line[0] != ' ')
	{
		// if ((u)->splited)
			// ft_freesplited((u)->splited);
		printf("There's strange data in the first section of the file ! Abortion\n");
		return (0);
	}
	return (1);
}

void	ft_sum_cond(t_utils *u, int fd)
{
	if ((u)->ca < 5)
	{
		if (u->line)
			free(u->line);
		(u)->line = get_next_line(fd);
	}
	if ((u)->line && (u)->line[0] != '\n')
		(u)->ca++;
}

int	ft_larx(t_utils *u)
{
	if (((u)->line[0] && (u)->line[1]) 
		|| (u)->line[0] == ' ')
	{
		if (ft_sar(u) == 0)
			return (-1);
	}
	return (-2);
}
t_dir *ft_check_first_lines(int fd, int fl)
{
	t_utils u;
	int	total;
	
	ft_init_utils_var_as(&u, fd);
	total = 0;
	if (!(u).line)
		return (NULL);
	while ((u).ca < 6 && (u).line 
		&& ft_only_spaces((u).line) != 0)
	{
		ft_larx(&u);
		ft_sum_cond(&u, fd);
		total = u.a + u.b + u.c + u.d + u.e + u.f;
		if (!u.line || (u.a + u.b + u.c 
					+ u.d + u.e + u.f && (u.a != 0 
						&& u.b != 0 && u.c != 0 && u.d != 0 
						&& u.e != 0 && u.f != 0) && (u.ca) == fl))
		{
			
			ft_freesplited(u.splited);
			free(u.line);
			return (u.dir);
		}
	}
	free(u.line);
	return (u.dir);
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

char **ft_get_map_2d(int fd, char *file)
{
	char **map = NULL;
	int i = 1;

	map = malloc(sizeof(char *) * (ft_count_the_map(file) + 1));
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
	if (i > 0 && map[i - 1][ft_strlen(map[i - 1]) - 1] == '\n')
		return (NULL);
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


int	ft_cond_check(s_ut_check sar, char **map)
{
	if ((sar.size > 0 && sar.main_size > 0 && sar.size < sar.main_size) 
	|| (map[sar.i][sar.j + 1] && map[sar.i][sar.j + 1] == ' ') 
	|| ((map[sar.i + 1] && map[sar.i + 1][sar.j] == ' ') 
	|| (map[sar.i + 1] && map[sar.i + 1][sar.j] == '\n')) 
	|| (sar.i > 0 && (!map[sar.i - 1][sar.j] 
	|| (map[sar.i - 1][sar.j] && map[sar.i - 1][sar.j] == ' ')))
	|| (map[sar.i][sar.j - 1] && map[sar.i][sar.j - 1] == ' ') 
	|| ((map[sar.i - 1] && map[sar.i - 1][sar.j] == ' ') 
	|| (map[sar.i - 1] && map[sar.i - 1][sar.j] == '\n')))
	{
		printf("LKHWA ERROR\n");
		return (1);
	}
	return (0);
}



int ft_check_map_2d(char **map)
{
	s_ut_check sar;
	
	sar.i = 0;
	sar.j = 0;
	sar.size = 0;
	sar.main_size = 0;
	while (map[sar.i])
	{
		sar.j = 0;
		if (map[sar.i + 1])
			sar.size = ft_strlen(map[sar.i + 1]);
		while (map[sar.i][sar.j])
		{
			if (map[sar.i][sar.j] == '0')
			{
				if(ft_cond_check(sar, map) == 1)
					return (1);
			}
			sar.j++;
		}
		sar.i++;
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

int ft_get_idx(char *map)
{
	int i = 0;
	
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'W' 
			|| map[i] == 'E' || map[i] == 'O')
			return (i);
		i++;
	}
	return (0);
}

int	ft_conditions_detect(int i, int j, char **map)
{
	if ((i < ft_count_2d(map) - 1) 
		&& map[i + 1] && (unsigned int) j > ft_strlen(map[i + 1]))
		return (-1);
	if (i > 0 && map[i - 1][j] 
		&& (map[i - 1][j] == ' ' || map[i - 1][j] == '\n'))
		return (-1);
	if (i > 0 && (i < ft_count_2d(map) - 1) 
		&& map[i + 1][j] && (map[i + 1][j] == ' ' 
		|| map[i + 1][j] == '\n'))
		return (-1);
	if (i > 0 && j > 0 && map[i][j - 1] 
		&& (map[i][j - 1] == ' ' || map[i][j - 1] == '\n'))
		return (-1);
	if (i > 0 && map[i][j + 1] 
		&& (map[i][j + 1] == ' ' || map[i][j + 1] == '\n'))
		return (-1);
	return (0);
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
			if (map[i][j] == 'N' || map[i][j] == 'W' 
				|| map[i][j] == 'E' || map[i][j] == 'O')
				if (ft_conditions_detect(i, j, map) == -1)
					return (-1);
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
					|| map[i][j] == 'E' || map[i][j] == 'W' 
					|| map[i][j] == 'S')
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
		if (last_idx > 0 && map[i][0] &&
		((map[i][0] != '1' && map[i][0] != ' ') 
		|| (map[i][last_idx - 1] != '1' && map[i][last_idx - 1] != ' ')))
			return (1);
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
		if (dir->key && dir->value 
			&& (dir->key[0] == 'F' || dir->key[0] == 'C'))
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
int	ft_rbg_util1(t_dir *dir, int i)
{
	if (i > 0 && dir->value[i] == ',' 
		&&( ft_isdigit(dir->value[i + 1]) != 1
		|| ft_isdigit(dir->value[i - 1]) != 1))
			return (-1);
	else if (i == 0 && dir->value[0] == ',')
		return (-1);
	return (0);
}

int ft_rbg_comma(t_dir *dir)
{
	int i;
	int comma;

	i = -1;
	comma = 0;
	while (dir)
	{
		if (dir->key && dir->value 
			&& (dir->key[0] == 'F' || dir->key[0] == 'C'))
		{
			i = -1;
			while (dir->value[++i])
			{
				if (ft_rbg_util1(dir, i) == -1)
					return (-1);
				else if (dir->value[i] == ',')
					comma++;
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
	i = -1;
	while (splited[++i])
		free(splited[i]);
	free(splited);
	return (rg);
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

void	ft_init_var_cub(t_cub3d *cub)
{
	cub->ka = -1;
	cub->sides = -1;
	cub->wrapper = -1;
	cub->weird_ins = -1;
	cub->player_checker = -1;
	cub->dup = -1;
	cub->rgb = -1;
	cub->cm = -1;
	cub->pos = -1;
	cub->player_dir = -1;
	cub->pos = ft_detect_pos_of_player(cub->map);
	cub->dup = ft_check_first_data_section(cub->dir);
	cub->weird_ins = ft_check_for_diff_chars(cub->map);
	cub->wrapper = ft_check_wrapper(cub->map);
	cub->sides = ft_check_sides_map(cub->map);
	cub->cm = ft_rbg_comma(cub->dir);
	cub->player_dir = ft_player_direction(cub->map);
}

int	ft_cond_cub(t_cub3d *cub)
{
	if (cub->ka != 0 || cub->sides != 0 || cub->wrapper != 0
		|| cub->weird_ins != 0 || cub->player_checker != 0
		|| cub->dup != 0 || cub->rgb != 0 || cub->cm != 4
		|| cub->pos != 0 || cub->player_dir ==  0) 
		return (0);
	return (-1);
}
int	args_c(int ac, char *av)
{
	int	i;
	int	c;

	c = 1;
	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			if (av[i] == '.' && i > 0
				&& av[i - 1] != '/' && av[i - 1] != '.')
					c = ft_strncmp(av + i, ".cub", 4);
			i++;
		}
	}
	return (c);
}

unsigned int rgb_to_int(unsigned int r, unsigned int g, unsigned int b) 
{
	int	color;
	
	color = 0;
	if (r > 255 || r < 0 || g > 255 
		|| g < 0 || b > 255 || b < 0)
		return (-404);
	color = (unsigned int)r << 16 | (unsigned int)g << 8 | (unsigned int)b;
    return (color);
}


int	ft_convert_to_rgb(t_dir *dir, t_cub3d *cub)
{
	int	i;
	t_rgb ra;
	
	i = 0;
	while (dir)
	{
		if (dir->key)
		{
			ra = ft_rgb(dir->value);
			if (dir->key[0] == 'F')
				cub->floor = rgb_to_int(ra.r, ra.g, ra.b);
				
			else if (dir->key[0] == 'C')
				cub->ceiling = rgb_to_int(ra.r, ra.g, ra.b);
			if (cub->floor == -404 || cub->ceiling == -404)
			{
				printf("Fix your rgb\n");
				exit(1);
			}
		}
		dir = dir->next;
	}
	return (1);
}


void	ft_free_dir(t_dir *dir)
{
	while (dir)
	{
		free(dir->key);
		free(dir->value);
		dir = dir->next;
	}
	free(dir);
}

void	ft_free_map(char **map)
{
	int	i;
	
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

t_cub3d *ft_parser_cub3d(int ac, char *v)
{
	int fd;
	t_cub3d *cub = NULL;
	int nbr_start = 0;
	(void) ac;
	cub = malloc(sizeof(t_cub3d));
	nbr_start = ft_check_if_map_starts(v);
	fd = open(v, O_RDONLY);
	if (!cub || fd == -1 || args_c(2, v) != 0)
		return (0);
	cub->dir = ft_check_first_lines(fd, nbr_start);
	cub->map = ft_get_map_2d(fd, v);
	if (!cub->map || !cub->dir)
	{
		ft_free_dir(cub->dir);
		// ft_free_map(cub->map);
		free(cub);
		return (0);
	}	
	ft_init_var_cub(cub);
	if (cub->cm == 4)
	{
		cub->rgb = ft_rbg_checker(cub->dir);
		ft_convert_to_rgb(cub->dir, cub);
	}
	if (cub->sides == 0 && cub->wrapper == 0)
		cub->ka = ft_check_map_2d(cub->map);
	cub->player_checker = ft_check_player_dup(cub->map);
	
	if (ft_cond_cub(cub) == 0)
	{
		ft_free_dir(cub->dir);
		// ft_free_map(cub->map);
		free(cub);
		return (0);	
	}
	return (cub);
}



// t_cub3d *ft_parser_cub3d(char *v)
// {
// 	int fd;
// 	t_dir *dir = NULL;
// 	t_cub3d *cub = NULL;
// 	int nbr_start = 0;
// 	// int i = 0;
	
// 	cub = malloc(sizeof(t_cub3d));
// 	nbr_start = ft_check_if_map_starts(v);
// 	fd = open(v, O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	cub->dir = ft_check_first_lines(fd, nbr_start);
// 	cub->map = ft_get_map_2d(fd, v);

// 	if (cub->dir == NULL)
// 	{
// 		printf("The dir array that holds data related to he map is empty ! Check for errors in the data or the file !!\n");
// 		return (0);
// 	}
// 	if (!cub->map)
// 	{
// 		exit(0);
// 		return (0);
// 	}

// 	cub->ka = 0;
// 	cub->sides = 0;
// 	cub->wrapper = 0;
// 	cub->weird_ins = 0;
// 	cub->player_checker = 0;
// 	cub->dup = -1;
// 	cub->rgb = 0;
// 	cub->cm = 0;
// 	cub->pos = 0;
// 	cub->player_dir = 0;
	
// 	cub->pos = ft_detect_pos_of_player(cub->map);
// 	cub->dup = ft_check_first_data_section(cub->dir);
// 	cub->weird_ins = ft_check_for_diff_chars(cub->map);
// 	cub->wrapper = ft_check_wrapper(cub->map);
// 	cub->sides = ft_check_sides_map(cub->map);
// 	cub->cm = ft_rbg_comma(cub->dir);
// 	cub->player_dir = ft_player_direction(cub->map);
// 	if (cub->cm == 4)
// 	{
// 		printf("****** Checking RGB *******\n");
// 		cub->rgb = ft_rbg_checker(dir);
// 	}
	
// 	if (cub->sides == 0 && cub->wrapper == 0)
// 		cub->ka = ft_check_map_2d(cub->map);
// 	cub->player_checker = ft_check_player_dup(cub->map);
// 	printf("\n\n\n\n");
// 	printf("#########################\n");
// 	printf("====== SUMMARY ======\n");
// 	printf("RBG = %d\n", cub->rgb);
// 	printf("cm= %d\n", cub->cm);
// 	printf("dup = %d\n", cub->dup);
// 	printf("weird_ins = %d\n", cub->weird_ins);
// 	printf("sides = %d\n", cub->sides);
// 	printf("check for khwa = %d\n", cub->ka);
// 	printf("wrapper = %d\n", cub->wrapper);
// 	printf("player_checker = %d\n", cub->player_checker);
// 	printf("player position checker = %d\n", cub->pos);
// 	printf("player dir = %d\n", cub->player_dir);
// 	printf("#########################\n");
// 	if (cub->ka != 0 || cub->sides != 0 || cub->wrapper != 0
// 		|| cub->weird_ins != 0 || cub->player_checker != 0
// 		|| cub->dup != 0 || cub->rgb != 0 || cub->cm != 4
// 		|| cub->pos != 0 || cub->player_dir ==  0)
// 		{
// 			printf("asdasdas\n");
// 			return (0);
// 		}
// 	int i =0;
// 	printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAP\n");
// 	while (cub->map[i])
// 	{
// 		printf("%s", cub->map[i]);
// 		i++;
// 	}
// 	printf("END MAAAAAAAAAAAP\n");
// 	printf("\n\n\n\n");
// 	printf("#########################\n");
// 	printf("====== SUMMARY ======\n");
// 	printf("RBG = %d\n", cub->rgb);
// 	printf("cm= %d\n", cub->cm);
// 	printf("dup = %d\n", cub->dup);
// 	printf("weird_ins = %d\n", cub->weird_ins);
// 	printf("sides = %d\n", cub->sides);
// 	printf("check for khwa = %d\n", cub->ka);
// 	printf("wrapper = %d\n", cub->wrapper);
// 	printf("player_checker = %d\n", cub->player_checker);
// 	printf("player position checker = %d\n", cub->pos);
// 	printf("player dir = %d\n", cub->player_dir);
// 	printf("#########################\n");
// 	return (cub);
// }
