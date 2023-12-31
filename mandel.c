/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:29:33 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/18 12:13:49 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandel(int x, int y, t_fractal *fractal);

void	draw_mandel(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_mandel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

// z(0) = 0; C = pixel point
static void	calculate_mandel(int x, int y, t_fractal *fractal)
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
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
		if (z.x * z.x + z.y * z.y > ESCAPE)
		{
			put_color_to_pix(x, y, fractal, fractal->color * (i % 256));
			return ;
		}
	}
	put_color_to_pix(x, y, fractal, BLACK);
}

// static void calculate_mandel(int x, int y, t_fractal *fractal)
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
// 		z.y = 2 * z.x * z.y + c.y;
// 		z.x = temp_x;
// 		if (z.x * z.x + z.y * z.y > ESCAPE)
// 		{
// 			// Gradient Coloring
// 			int blue = 255 - (i * 3 % 256);  // Reducing blue as i increases
// 			int green = (i * 3) % 256;       // Increasing green as i increases
// 			int red = green;              

// 			int color = (red << 16) | (green << 8) | blue;
// 			put_color_to_pix(x, y, fractal, color);
// 			return ;
// 		}
// 	}
// 	put_color_to_pix(x, y, fractal, BLACK);
// }
