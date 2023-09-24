#include "../cub3d.h"

void	horz_ray_casting(t_src *src, int stripid)
{
	horz_var_init(src);
	looking_direction(src);
	horz_setup(src);
	while (is_horz_wall_(src))
	{
		src->x_to_check = src->next_h_touch_x;
		src->y_to_check = src->next_h_touch_y;
		if (src->irfu)
			src->y_to_check -= 1;
		if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
			src->horz_wall_hit_x = src->next_h_touch_x;
			src->horz_wall_hit_y = src->next_h_touch_y;
			src->found_h_wall_hit = 1;
			break ;
		}
		else
		{
			src->next_h_touch_x += src->xstep;
			src->next_h_touch_y += src->ystep;
		}
	}
}

void	vert_ray_casting(t_src *src, int stripid)
{
	vert_var_init(src);
	vert_setup(src);
	while (is_vert_wall_(src))
	{
		src->x_to_check = src->next_v_touch_x;
		src->y_to_check = src->next_v_touch_y;
		if (src->irfl)
			src->x_to_check -= 1;
		if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
			src->vert_wall_hit_x = src->next_v_touch_x;
			src->vert_wall_hit_y = src->next_v_touch_y;
			src->found_v_wall_hit = 1;
			break ;
		}
		else
		{
			src->next_v_touch_x += src->xstep;
			src->next_v_touch_y += src->ystep;
		}
	}
}
