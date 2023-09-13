/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:59:10 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/13 20:15:38 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// C = each pixel position (constant), calculate if z escaped;
static void	calculate_newton(int x, int y, t_fractal *fractal);

void	draw_newton(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_newton(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

static void calculate_newton(int x, int y, t_fractal *fractal)
{
    t_complex z, z_next;
    t_complex z_temp;
    t_complex z_prime;
    int i;

    z.x = x / RATIO * fractal->zoom + fractal->offset_x;
    z.y = -y / RATIO * fractal->zoom + fractal->offset_y;
    i = 0;
    while (i++ < fractal->max_iter) {
        // Polynomial: P(z) = z^3 - z - 1
        z_temp.x = z.x * z.x * z.x - 3 * z.x * z.y * z.y - z.x - 1;
        z_temp.y = 3 * z.x * z.x * z.y - z.y * z.y * z.y - z.y;

        // Derivative: P'(z) = 3z^2 - 1
        z_prime.x = 3 * z.x * z.x - 3 * z.y * z.y - 1;
        z_prime.y = 6 * z.x * z.y;

        // Newton's iteration step
        double denom = z_prime.x * z_prime.x + z_prime.y * z_prime.y;
        z_next.x = z.x - (z_temp.x * z_prime.x + z_temp.y * z_prime.y) / denom;
        z_next.y = z.y - (z_temp.y * z_prime.x - z_temp.x * z_prime.y) / denom;

        // Check for convergence (if z doesn't change much)
        if ((z_next.x - z.x) * (z_next.x - z.x) + (z_next.y - z.y) * (z_next.y - z.y) < 0.000001) {
            put_color_to_pix(x, y, fractal, fractal->color * (i % 256));
            return;
        }

        z = z_next;
    }
    put_color_to_pix(x, y, fractal, BLACK);
}

