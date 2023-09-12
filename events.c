/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:57 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/12 13:14:10 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//type xev to find the keycodes??
//https://github.com/leogaudin/fract-ol/blob/main/src/mouse_and_keys.c
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == UP)
		fractal->offset_y -= 0.2 * fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 0.2 * fractal->zoom;
	else if (key_code == LEFT)
		fractal->offset_x -= 0.2 * fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 0.2 * fractal->zoom;
	else if (key_code == INCREASE)
	{
		//if (fractal->max_iter < 420000)
			fractal->max_iter += 10;
	}
	else if (key_code == DECREASE)
	{
		//if (fractal->max_iter > 42)
			fractal->max_iter -= 10;
	}
	else if (key_code == CHANGE)
		fractal->color += 0xFFFFFF / 100;//TODO
	call_fractal(fractal, fractal->name);
	return (0);
}

// Julia evolves when moving the mouse around
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		fractal->julia_cx = x/RATIO * fractal->zoom + fractal->offset_x;
		fractal->julia_cy = y/RATIO * fractal->zoom + fractal->offset_y;
		draw_julia(fractal);
	}
	return 0;
}

//The zoom follows the actual mouse position
int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	// Calculate the offset of the mouse from the center of the view
	double offsetx = (x / RATIO - 2.0);//? z.x?
	double offsety = (y / RATIO - 2.0);

	if (keycode == ZOOM_IN)
	{
		fractal->zoom *= 0.98;

		// Adjust the view offset based on the mouse position
		fractal->offset_x += offsetx * (1.0 - fractal->zoom);
		fractal->offset_y += offsety * (1.0 - fractal->zoom);
	}
	else if (keycode == ZOOM_OUT)
	{
		fractal->zoom *= 1.02;
		fractal->offset_x -= offsetx * (fractal->zoom - 1.0);
		fractal->offset_y -= offsety * (fractal->zoom - 1.0);
	}
	call_fractal(fractal, fractal->name);
	return (0);
}
