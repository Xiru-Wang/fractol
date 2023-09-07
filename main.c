/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:05:03 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/07 17:28:35 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		//fractol.name = av[1];
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		fractal.julia_x = atoi_double(av[2]);//todo
		fractal.julia_y = atoi_double(av[3]);//todo
	}
	else
	{
		write(STDERR_FILENO, "Please Enter: \"./fractol mandelbrot\" ", 37);
		write(STDERR_FILENO, "or \"./fractol julia value_1 value_2\"\n",37);
		exit(EXIT_FAILURE);
	}
	fractal.name = av[1];
	init_fractal(&fractal);
	render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

//mlx connections + window
static void	init_fractal(t_fractal *fractal)
{
	t_img	img;

	// 1. connection
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		handle_err();
	// 2. window
	fractal->window = mlx_new_window(fractal->mlx,
									 WIDTH, HEIGHT, fractal->name);
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		handle_err();
	}
	// 3. image
	img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (img.img_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		free(fractal->window);//no need??
		handle_err();
	}
	//first pixel address
	img.pixel = mlx_get_data_addr(img.img_ptr, img.bpp, img.size_len, img.endian);

	init_event(fractal);//?
	init_data(fractal);//?
}

static void	init_data(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void init_event(t_fractal *fractal)
{
	mlx_hook();
	mlx_hook();
	mlx_hook();
}
