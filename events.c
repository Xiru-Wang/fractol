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
	double x_before；
	double y_before；
	double x_after；
	double y_after；
	
	x_before = x / RATIO * fractal->zoom + fractal->offset_x;
	y_before = y / RATIO * fractal->zoom + fractal->offset_y;	
	if (keycode == ZOOM_IN)
		fractal->zoom *= 0.98;
	else if (keycode == ZOOM_OUT)
		fractal->zoom *= 1.02;
	else
		return (1);
	x_after = x / RATIO * fractal->zoom + fractal->offset_x;
	y_after = y / RATIO * fractal->zoom + fractal->offset_y;
	fractal->offset_x += x_before - x_after;
	fractal->offset_y += y_before - y_after;
	call_fractal(fractal, fractal->name);
	return (0);
}
