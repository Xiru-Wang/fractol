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


//The zoom follows the actual mouse position
/*
int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	// Calculate the offset of the mouse from the center of the view
	double offsetx = (x / RATIO - 2.0);//? z.x?
	double offsety = (y / RATIO - 2.0);

	if (keycode == ZOOM_IN)
	{
		fractal->zoom *= 0.9;
		
		// Adjust the view offset based on the mouse position
		fractal->offset_x += offsetx * (1.0 - 0.9);
		fractal->offset_y += offsety * (1.0 - 0.9);
	}
	else if (keycode == ZOOM_OUT)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x -= offsetx * (1.1 - 1.0);
		fractal->offset_y -= offsety * (1.1 - 1.0);
	}
	call_fractal(fractal, fractal->name);
	return (0);
}
*/

/*
 * TRACK the mouse
*/

#define MOUSEMOVE 6

// Julia evolves when moving the mouse around
mlx_hook(window, 6, PointerMotionMask, julia_track, fractal);
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_cx = x/RATIO * fractal->zoom) + fractal->shift_x;
		fractal->julia_cy = y/RATIO * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return 0;
}
