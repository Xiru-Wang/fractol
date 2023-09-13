/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:30:07 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:58:22 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// C = each pixel position (constant), calculate if z escaped;
void	calculate_julia(int x, int y, t_fractal *fractal);

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_julia(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

// Z = each pixel point C = a fix number / actual mouse position
void	calculate_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	double		temp_x;
	int			i;

	z.x = x / RATIO * fractal->zoom + fractal->offset_x;
	z.y = -y / RATIO * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i++ < fractal->max_iter)
	{
		temp_x = z.x * z.x - z.y * z.y + fractal->julia_cx;
		z.y = 2 * z.x * z.y + fractal->julia_cy;
		z.x = temp_x;
		if ((z.x * z.x + z.y * z.y) > ESCAPE)
		{
			put_color_to_pix(x, y, fractal, fractal->color * (i % 42));
			return ;
		}
	}
	put_color_to_pix(x, y, fractal, BLACK);
}
