/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:08:15 by ade-beco          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:36 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling_floor(t_data *data, t_ray *ray, int slice)
{
	int	i;

	i = 0;
	while (i < ray->draw_start)
	{
		my_mlx_pixel_put(&(data->img2), slice, i, data->map->ceiling_color);
		i++;
	}
	i = ray->draw_end;
	while (i < HEIGHT - 1)
	{
		my_mlx_pixel_put(&(data->img2), slice, i, data->map->floor_color);
		i++;
	}
}

int	apply_shading(int color, double factor)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	a = (color >> 24) & 0xFF;
	r = (int)(r * factor);
	g = (int)(g * factor);
	b = (int)(b * factor);
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

void	draw_slice(t_data *data, t_ray *ray, int slice)
{
	int		i;
	int		color;
	double	ratio;
	int		offset;

	i = ray->draw_start;
	ratio = 1.0 * ray->text.width / ray->wall_height;
	offset = 0;
	if (ray->wall_height > HEIGHT - 1)
		offset = (ray->wall_height - (HEIGHT - 1)) / 2;
	draw_ceiling_floor(data, ray, slice);
	while (i < ray->draw_end)
	{
		ray->text_y = (i + offset - ray->draw_start) * ratio;
		color = ray->text.pixel_array[ray->text_y + \
			(ray->text.width * ray->text_x)];
		if (ray->wall == 1)
			color = apply_shading(color, 0.8);
		my_mlx_pixel_put(&(data->img2), slice, i, color);
		i++;
	}
}
