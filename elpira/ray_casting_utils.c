#include "cub3d.h"

int is_horz_wall(t_src *src)
{
	if (src->next_h_touch_x >= 0 && src->next_h_touch_x < src->img->width &&
           src->next_h_touch_y >= 0 && src->next_h_touch_y < src->img->height)
		   return (true);
	return (false);
}
