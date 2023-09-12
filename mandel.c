#include "fractol.h"

static void calculate_mandel(int x, int y, t_fractal *fractal);

void draw_mandel(t_fractal *fractal)
{
	int x;
	int y;

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

static void	calculate_mandel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp_x;
	int i;

	z.x = 0.0;
	z.y = 0.0;
	c.x = x / RATIO * fractal->zoom + fractal->offset_x;
	c.y = y / RATIO * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i++ < fractal->max_iter)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
		if (z.x * z.x + z.y * z.y > ESCAPE)
		{
			put_color_to_pix(x, y, fractal, fractal->color * (i % 256));//i % 256?
			return ;
		}
	}
	put_color_to_pix(x, y, fractal, BLACK);
}

