/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:54:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/05 19:30:07 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	_map_has_wall_at(float x_to_check, float y_to_check, t_src *src)
{
	int i;
 
	i = 0;
	while (src->map[i])
		i++;
	i--;
	if ((y_to_check / M_TILE_SIZE) >= i)
		return (true);
	if ((int)(y_to_check / M_TILE_SIZE) > 1)
		if ((x_to_check / M_TILE_SIZE) >= ft_strlen(src->map[(int)(y_to_check / M_TILE_SIZE)]) - 1)
			return (true);
	if ((x_to_check / M_TILE_SIZE) <= 0 || (y_to_check / M_TILE_SIZE) <= 0)
		return (true);
	if (!_x_y_to_check(y_to_check / M_TILE_SIZE, x_to_check / M_TILE_SIZE, src->map))
		return (true);
	if (src->map[(int)(y_to_check / M_TILE_SIZE)][(int)(x_to_check / M_TILE_SIZE)] == '1')
		return (true);
	return (0);
}

void	dda(t_src *src, int len, float plx, float ply)
{
	int		i;
	int		dx;
	int		dy;
	float	steps;

	i = -1;
	dx = (plx - (cos(src->view_angle) * -1) * (40)) - plx;
	dy = (ply - (sin(src->view_angle) * -1) * (40)) - ply;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	while (++i <= steps)
	{
		if (i && !_x_y_to_check((ply - (dy / steps)) / M_TILE_SIZE,
			(plx) / M_TILE_SIZE, src->map))
			return ;
		if (i && !_x_y_to_check(ply / M_TILE_SIZE,
			(plx - (dx / steps)) / M_TILE_SIZE, src->map))
			return ;
		if (plx > 0 && plx < src->img->width
			&& ply > 0 && ply < src->img->height)
			mlx_put_pixel(src->img, plx, ply, RAY_COLOR);
		plx += dx / steps;
		ply += dy / steps;
	}
}
typedef struct s_point{
	float x;
	float y;
}	t_point;

typedef struct s_int_point{
	int x;
	int y;
}	t_int_point;

void	ft_draw_texture(t_src *src, t_point pi, t_point px, float h, mlx_texture_t *txt)
{
	t_int_point p1;
	t_int_point p2;
	uint8_t		*px_1;
	uint8_t		*pi_1;
	
	p1.x = px.x;
	p1.y = -1;
	p2.x = pi.x;
	p2.y = pi.y;
	if (h > (src->img->height))
		p1.y = (h - src->img->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int) src->img->height - 1 && ++p1.y < h - 1)
	{
		px.y = p1.y * (float) txt->height / h;		
		if (px.y < txt->height
			&& (px.y * txt->width + p1.x) < txt->width * txt->height)
		{
			px_1 = &txt->pixels[(((int)px.y * txt->width) + p1.x) * txt->bytes_per_pixel];
			pi_1 = &src->img->pixels[((p2.y * (src->img->width)) + p2.x) * txt->bytes_per_pixel];
			ft_memmove(pi_1, px_1, txt->bytes_per_pixel);
		}
	}
}
void	draw_sky_floor(t_src *src)
{
	float	i;
	float	j;

	i = 0;
	while (++i < src->img->height)
	{
		j = -1;
		while (++j < src->img->width)
		{
			if (i > src->img->height / 2)
				mlx_put_pixel(src->img, j, i, src->cub->floor);
			else
				mlx_put_pixel(src->img, j, i, src->cub->ceiling);
		}
	}
}
void	draw_col(t_src *src, t_point p, float height, ray *r, s_load t)
{
	t_point px;	
	t_point pi;
	mlx_texture_t *txt;
	float width_ratio;
	
	pi.x = p.x;
	pi.y = p.y;
	
	if (!r->was_hit_vertical)
	{
		txt = t.e;
		if (r->irfu)
			txt = t.w;
		width_ratio = (float) txt->width / 50;
		px.x = fmod(r->wall_hitx, 50) * width_ratio;
	}
	else
	{
		txt = t.n;
		if (r->irfl)
			txt = t.s;
		width_ratio = (float) txt->width / 50;
		px.x = fmod(r->wall_hity, 50) * width_ratio;
	}
	ft_draw_texture(src, pi, px, height, txt);
}

void draw_3d_wall(t_src *src, int i,ray *ray, s_load txt)
{
	t_point	p;
	
	p.x = i;
	p.y = ((src->img->height / 2) - (((src->img->height / 2) * 50) / src->correct_distance));
	draw_col(src, p, src->img->height - (p.y * 2), ray, txt);
}


int	ft_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_capa(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (s[start] != 0)
	{
		arr = malloc(len + 1);
		if (!arr)
			return (0);
		i = 0;
		while (len)
		{
			arr[i++] = s[j++];
			len--;
		}
		arr[i] = 0;
		free((char *)s);
		return (arr);
	}
	return (0);
}
char	*ft_strtrim_caba(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (s1 == 0)
		return (0);
	j = ft_strlen(s1) - 1;
	if (set == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (!ft_check(set, s1[i]))
			break ;
		i++;
	}
	while (j >= i)
	{
		if (!ft_check(set, s1[j]))
			break ;
		j--;
	}
	return (ft_substr_capa(s1, i, j - i + 1));
}
char	*ft_return_value(t_dir *dir, char *key)
{
	while (dir)
	{
		if (ft_strncmp(dir->key, key, 2) == 0)
		{
			dir->value = ft_strtrim_caba(dir->value, "\n");
			return (dir->value);
		}
		dir = dir->next;
	}
	return (NULL);
}
int	ft_fill_textures(t_dir *dir, s_load *texture)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;
	
	a = ft_return_value(dir, "EA");
	b = ft_return_value(dir, "NO");
	c = ft_return_value(dir, "SO");
	d = ft_return_value(dir, "WE");
	
	if (!a || !b || !c || !d)
		return (-1);
	(*texture).e = mlx_load_png(a);
	(*texture).w = mlx_load_png(b);
	(*texture).n = mlx_load_png(c);
	(*texture).s = mlx_load_png(d);
	if (!(*texture).e || !(*texture).w 
		|| !(*texture).s || !(*texture).n)
		return (-1);
	
	return (0);
}


void	_rays(t_src *src, s_load	texture)
{
	int		i;
	int		num_rays;
	float	ray_angle_increment;
	
	
	i = -1;
	num_rays = src->img->width;
	ray_angle_increment = 60.0 / num_rays;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	draw_sky_floor(src);
	while (++i < num_rays)
	{
		src->view_angle = normalize_angle(src->view_angle);
		horz_ray_casting(src, i);
		vert_ray_casting(src, i);
		get_distance_x_y(src, i);
		saving_distance(src, i);
		draw_3d_wall(src, i, &src->rays[i], texture);
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
	i = -1;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	_map(src);
	while (++i < num_rays)
	{
		dda(src, i, src->mplx, src->mply);
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
}

void	_player(t_src *src, s_load txt)
{
	// _rays(src, txt);
}
