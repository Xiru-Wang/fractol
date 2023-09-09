#include "fractol.h"

static void calculate_mandel(int x, int y, t_fractal *fractal);

void draw_mandel(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y++ < SIZE)
	{
		x = 0;
		while (x++ < SIZE)
		{
			//if (ft_strncmp(str, "mandel", 6) == 0) to slow?
			calculate_mandel(x, y, fractal);
			// else if (ft_strncmp(str, "julia", 5) == 0)
			// 	calculate_julia(x, y, fractal, av);
		}
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
	c.x = x / RATIO * fractal->zoom + fractal->offset_x;//-2
	c.y = y / RATIO * fractal->zoom + fractal->offset_y;//-2?
	i = 0;
	while (i++ < fractal->max_iter)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
		if (z.x * z.x + z.y * z.y > ESCAPE)
		{
			put_color_to_pix(x, y, fractal, fractal->color * (i % 10));//i % 256?
			return ;
		}
	}
	put_color_to_pix(x, y, fractal, BLACK);
}
