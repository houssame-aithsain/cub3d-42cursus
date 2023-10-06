/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:50:16 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

uint8_t	*ft_return_pixels(t_src *src, 
		mlx_texture_t *txt, t_int_point p1, t_point pa)
{
	(void)src;
	return (&txt->pixels[(((int)pa.yy * txt->width)
				+ p1.x) * txt->bytes_per_pixel]);
}

uint8_t	*ft_rp2(t_src *src, mlx_texture_t *txt, t_int_point p2)
{
	(void)src;
	return (&src->img->pixels[((p2.y * (src->img->width))
				+ p2.x) * txt->bytes_per_pixel]);
}

void	ft_draw_texture(t_src *src, t_point pa, float h, mlx_texture_t *txt)
{
	t_int_point	p1;
	t_int_point	p2;
	uint8_t		*px_1;
	uint8_t		*pi_1;

	p1.x = pa.xx;
	p1.y = -1;
	p2.x = pa.x;
	p2.y = pa.y;
	if (h > (src->img->height))
		p1.y = (h - src->img->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int) src->img->height && ++p1.y < h - 1)
	{
		pa.yy = p1.y * (float) txt->height / h;
		if (pa.yy < txt->height
			&& (pa.yy * txt->width + p1.x) < txt->width * txt->height)
		{
			px_1 = ft_return_pixels(src, txt, p1, pa);
			pi_1 = ft_rp2(src, txt, p2);
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

void	draw_col(t_src *src, t_point p, ray *r, t_load t)
{
	t_point			pi;
	mlx_texture_t	*txt;
	float			width_ratio;

	pi.x = p.x;
	pi.y = p.y;
	if (!r->was_hit_vertical)
	{
		txt = t.e;
		if (r->irfu)
			txt = t.w;
		width_ratio = (float) txt->width / 50;
		pi.xx = fmod(r->wall_hitx, 50) * width_ratio;
	}
	else
	{
		txt = t.n;
		if (r->irfl)
			txt = t.s;
		width_ratio = (float) txt->width / 50;
		pi.xx = fmod(r->wall_hity, 50) * width_ratio;
	}
	ft_draw_texture(src, pi, src->img->height - (p.y * 2), txt);
}
