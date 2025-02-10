/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:53:38 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/10 14:12:56 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_tex_info(t_data *data, t_ray *ray)
{
	double	ratio;

	ratio = fmod(ray->wall_intercept, data->map->grid_size) / \
		data->map->grid_size;
	ray->text_x = (int)(ratio * ray->text.width);
	//you may want to flip. look at vicode get_text_coord function
}

void	fill_ray_info(t_data *data, t_ray *ray)
{
	ray->wall_height = (data->map->grid_size * HEIGHT) / ray->perp_len;
	ray->draw_start = HEIGHT / 2 - (ray->wall_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->wall_height + ray->draw_start;
	if (ray->draw_end > HEIGHT - 1)
		ray->draw_end = HEIGHT - 1;
	if (ray->wall == 1)
	{
		if (ray->dir.x > 0.0f)
			ray->text = data->map->we_text;
		else
			ray->text = data->map->ea_text;
		ray->wall_intercept = data->player->pos.y + (ray->len * ray->dir.y);
	}
	else
	{
		if (ray->dir.y > 0.0f)
			ray->text = data->map->no_text;
		else
			ray->text = data->map->so_text;
		ray->wall_intercept = data->player->pos.x + (ray->len * ray->dir.x);
	}
}

void	raycaster(t_data *data)
{
	t_ray	ray;
	double	angle;
	double	step;
	int		i;

	i = 0;
	step = FOV / WIDTH;
	angle = -M_PI / 6;
	while (angle < M_PI / 6)
	{
		ray.dir.x = data->player->dir.x * cos(angle) - data->player->dir.y \
			* sin(angle);
		ray.dir.y = data->player->dir.x * sin(angle) + data->player->dir.y \
			* cos(angle);
		dda(data, &ray);
		fill_ray_info(data, &ray);
		fill_tex_info(data, &ray);
		draw_slice(data, &ray, i);
		i++;
		angle += step;
	}
}
