/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:34 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/07 17:22:39 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <mlx.h>//?
#include <math.h>
#include <unistd.h>
#include <stdlib.h>//malloc

//window
#define WIDTH 800
#define HEIGHT 600
//color
#define BLACK 0x000000
#define WHITE 0xFFFFFF
//RED FF0000
//GRE 00FF00
//BLU 0000FF

#define ESCAPE 4
#define MAX_ITERATION 42
//complex number = x(real) + y*i(imaginary)

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

//create a buffer
typedef struct	s_img
{
	void	*img_ptr;//pointer to img struct
	char	*pixel;//point to the actual pixels
	int		bpp;//bits per pixel
	int		size_len;
	int		endian;//byteorder
}				t_img;

typedef struct	S_fractal
{
	char	*name;
	void	*mlx;//void *mlx_init()
	void	*window;//mlx_new_window
	//t_img	img;//??
	//int		max_iteration;//? or just define it?
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

void	handle_err(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif
