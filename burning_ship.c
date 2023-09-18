/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:12:53 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/18 12:13:25 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_ship(int x, int y, t_fractal *fractal);

void	draw_ship(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_ship(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

// z = z^z + c

static void	calculate_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp_x;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	c.x = x / RATIO * fractal->zoom + fractal->offset_x;
	c.y = -y / RATIO * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i++ < fractal->max_iter)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = fabs(temp_x);
		if (z.x * z.x + z.y * z.y > ESCAPE)
		{
			put_color_to_pix(x, y, fractal, fractal->color * (i % 256));
			return ;
		}
	}
	put_color_to_pix(x, y, fractal, BLACK);
}

// static void calculate_ship(int x, int y, t_fractal *fractal)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	double		temp_x;
// 	int			i;

// 	z.x = 0.0;
// 	z.y = 0.0;
// 	c.x = x / RATIO * fractal->zoom + fractal->offset_x;
// 	c.y = -y / RATIO * fractal->zoom + fractal->offset_y;
// 	i = 0;
// 	while (i++ < fractal->max_iter)
// 	{
// 		temp_x = z.x * z.x - z.y * z.y + c.x;
// 		z.y = fabs(2 * z.x * z.y) + c.y;
// 		z.x = fabs(temp_x);
// 		if (z.x * z.x + z.y * z.y > ESCAPE)
// 		{
// 			// Gradient Coloring
// 			int red = (i * 5) % 256;
// 			int green = (255 - i * 2) % 256;
// 			int blue = (i * 7) % 256;
// 			int color = (red << 16) | (green << 8) | blue;
// 			put_color_to_pix(x, y, fractal, color);
// 			return ;
// 		}
// 	}
// 	put_color_to_pix(x, y, fractal, BLACK);
// }
