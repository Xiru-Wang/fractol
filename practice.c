/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:43:11 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/07 17:18:24 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
1. virtual tool:  https://www.geogebra.org/m/mfewjrek
2. video tutorial: https://www.youtube.com/watch?v=ANLW1zYbLcs
*/

typedef struct s_complex
{
	double	x;//x-axis  real nmber
	double	y;//y-axis imaginary number
}				t_complex;

//manderbrot: z = z^2 + c
int	main()
{
	t_complex	z;//point/position eg.(5, 2i)
	t_complex	c;//z = z*z + c
	double		temp_real;

	z.x = 0;
	z.y = 0;// z0 = 0 + c

	c.x = 5;
	c.y = 2;

	int i = 0;
	while (i < 42)
	{
		//real: x*x - y*y imaginary: 2xyi
		temp_real = z.x * z.x - z.y * z.y;

		z.y = 2 * z.x * z.y;
		z.x = temp_real;
		//add value
		z.x = z.x + c.x;
		z.y = z.y + c.y;

		printf("iteration n: %d real: %f, imaginary: %f.\n", i, z.x, z.y);
		i++;
	}
}
