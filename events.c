/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:57 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/09 12:31:33 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//type xev to find the keycodes??
//https://github.com/leogaudin/fract-ol/blob/main/src/mouse_and_keys.c
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	if (key_code == UP)
		fractal->offset_y -= 0.2;
	if (key_code == DOWN)
		fractal->offset_y += 0.2;
	if (key_code == LEFT)
		fractal->offset_x -= 0.2;
	if (key_code == RIGHT)
		fractal->offset_x += 0.2;
	if (key_code == INCREASE)
	{
		if (fractal->max_iter < 1500)
			fractal->max_iter += 42;// double interation speed
	}
	else if (key_code == DECREASE)
	{
		if (fractal->max_iter > 42)
			fractal->max_iter -= 42;
	}
	else if (key_code == CHANGE)
		fractal->color += 0xFFFFFF / 100;
	call_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == ZOOM_IN)
		fractal->zoom *= 0.9;
	else if (keycode == ZOOM_OUT)
		fractal->zoom *= 1.1;
	call_fractal(fractal, fractal->name);
	return (0);
}

/*
 * TRACK the mouse
*/ The zoom follows the actual mouse position.

#define MOUSEMOVE 6

mlx_hook(window, 6, PointerMotionMask, mouse_track, fractal);

int	mouse_track(int x, int y, t_fractal *fractal)
{
	fractal->x = x/200.0 * fractal->zoom) + fractal->shift_x;
	fractal->y = y/200.0 * fractal->zoom) + fractal->shift_y;
	call_fractal(fractal);
	
}
