/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:57 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/08 22:54:58 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


//type xev to find the keycodes??
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	if (key_code == UP)
		fractal->shift_y -= 10;
	if (key_code == DOWN)
		fractal->shift_y += 10;// y: 1.5 ~-1.5
	if (key_code == LEFT)
		fractal->shift_x -= 10;//x: -2~+2
	if (key_code == RIGHT)
		fractal->shift_x += 10;///todo
	if (key_code == INCREASE)
	{
		if (fractal->max_iter < 5000)
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
