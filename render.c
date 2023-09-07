/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:04:21 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/07 17:20:37 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void draw_pixel(int x, int y, t_fractal *fractal, t_img *img);
static void put_pix(int x, int y, t_img *img, int color);

void render(t_fractal *fractal, t_img *img)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			draw_pixel(x, y, fractal, img);// draw each pixel
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, img->img_ptr, 0, 0);//img is ready to push to the window
}
// the x, y location of where the image ought to be placed;

static void draw_pixel(int x, int y, t_fractal *fractal, t_img *img)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	z.x = scale(x, -2, 2, 0, WIDTH);
	z.y = scale(y, 2, -2, 0, HEIGHT);
	// mandel or julia
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c.x = fractal->julia_x; // in julia: c is constant
		c.y = fractal->julia_y; // sepreate??
	}
	else
	{
		c.x = z.x;
		c.y = z.y; // in mandel: z = 0
	}
	i = 0;
	while (i < MAX_ITERATION)
	{
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;// z = z*z (x*x - y*y + 2xy) + c
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = color * i; // todo
			// scale(i, BLACK, WHITE, 0, MAX_ITERATION);
			put_pix(x, y, &img, color);
			break; // return??
		}
		i++;
	}
	put_pix(x, y, &img, BLACK);
}

static void put_pix(int x, int y, t_img *img, int color)
{
	int	pos;

	pos = y * img->size_len + x * (img->bpp / 8);
	color = *(unsigned int *)(img->pixel + pos);
}


