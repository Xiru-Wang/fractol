/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:43:52 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/09 12:24:39 by xiruwang         ###   ########.fr       */
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
// void	handle_err(void)
// {
// 	perror("Malloc failed");
// 	exit(EXIT_FAILURE);
// }

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (1);
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

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}


