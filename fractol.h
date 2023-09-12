/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:34 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/12 20:14:50 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
//#include <mlx.h>//?
//#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 1000
#define RATIO 250.0//800/4
//color
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define ELECTRIC_BLUE 0x0066FF  // A radiant blue
#define AQUA_DREAM 0x33CCCC  // A bright turquoise
#define MAGENTA_BURST 0xFF00FF  // A vibrant magenta
//RED FF0000
//GRE 00FF00
//BLU 0000FF

#define ESCAPE 4

//https://github.com/ilkou/minilibx/blob/master/key_linux.h
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define INCREASE 105 //i
#define DECREASE 100 //d
#define CHANGE 99 //c:change color
#define ZOOM_IN 4
#define ZOOM_OUT 5
#define MOUSEMOVE 6
#define PSYCHEDELIC 112
#define BACK 98 //b: back to previous color


typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;


typedef struct	S_fractal
{
	char	*name;
	void	*mlx;
	void	*window;
	void	*image;
	char	*pixel;
	int		bpp;
	int		size_len;
	int		endian;
	int		max_iter;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_cx;
	double	julia_cy;
}				t_fractal;

void	put_color_to_pix(int x, int y, t_fractal *fractal, int color);
int		exit_fractal(t_fractal *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	atoi_db(char *s);
void	call_fractal(t_fractal *fractal, char *name);
void	draw_mandel(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
int		julia_track(int x, int y, t_fractal *fractal);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);

#endif
