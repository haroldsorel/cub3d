/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:29:21 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/07 14:47:43 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	mlx_get_color(t_img *img, int x, int y)
{
	char	*dst;
	int		color;

	dst = img->pixel_ptr + (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixel_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
