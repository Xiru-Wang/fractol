/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:43:52 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/12 11:50:42 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_color_to_pix(int x, int y, t_fractal *fractal, int color)
{
	int		pos;
	char	*temp;

	pos = y * fractal->size_len + x * (fractal->bpp / 8);
	temp = fractal->pixel + pos;
	*(unsigned int *)temp = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (1);
}

void	call_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "mandel", 7) == 0)
		draw_mandel(fractal);
	else if (ft_strncmp(name, "julia", 6) == 0)
		draw_julia(fractal);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	atoi_db(char *s)
{
	double	int_part;
	double	double_part;
	int		sign;

	int_part = 0;
	double_part = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
		double_part = double_part + (*s++ - '0') * 0.1;
	return (sign * (int_part + double_part));
}
// void	ft_putstr_fd(char *s, int fd)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }


