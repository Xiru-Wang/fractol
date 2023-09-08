/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:57 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/08 23:47:32 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//type xev to find the keycodes??
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	if (key_code == UP)
		fractal->shift_y -= 0.5;
	if (key_code == DOWN)
		fractal->shift_y += 0.5;
	if (key_code == LEFT)
		fractal->shift_x -= 0.5;
	if (key_code == RIGHT)
		fractal->shift_x += 0.5;
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
	render(fractal);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == ZOOM_IN)
		fractal->zoom *= 0.9;
	else if (keycode == ZOOM_OUT)
		fractal->zoom *= 1.1;
	render(fractal);
	return (0);
}
