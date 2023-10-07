/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:50:16 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 15:18:40 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint8_t	*ft_return_pixels(t_src *src, 
		mlx_texture_t *txt, t_int_vue_ports p1, t_vue_ports pa)
{
	(void)src;
	return (&txt->pixels[(((int)pa.yy * txt->width)
				+ p1.x) * txt->bytes_per_pixel]);
}

uint8_t	*ft_rp2(t_src *src, mlx_texture_t *txt, t_int_vue_ports p2)
{
	(void)src;
	return (&src->img->pixels[((p2.y * (src->img->width))
				+ p2.x) * txt->bytes_per_pixel]);
}

void	ft_textures(t_src *src, t_vue_ports pa, float h, mlx_texture_t *txt)
{
	t_int_vue_ports	p1;
	t_int_vue_ports	p2;
	uint8_t			*px_1;
	uint8_t			*pi_1;

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

void	ft_skyndfloor_drawer(t_src *src)
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

void	ft_coldrawer(t_src *src, t_vue_ports p, t_ray *r, t_load t)
{
	t_vue_ports		tp;
	mlx_texture_t	*txt;
	float			wr;

	tp.x = p.x;
	tp.y = p.y;
	if (!r->hit_vertical)
	{
		txt = t.e;
		if (r->irfu)
			txt = t.w;
		wr = (float) txt->width / 50;
		tp.xx = fmod(r->wall_hitx, 50) * wr;
	}
	else
	{
		txt = t.n;
		if (r->irfl)
			txt = t.s;
		wr = (float) txt->width / 50;
		tp.xx = fmod(r->wall_hity, 50) * wr;
	}
	ft_textures(src, tp, src->img->height - (p.y * 2), txt);
}
