/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:34 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/08 22:28:46 by xiwang           ###   ########.fr       */
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
#define RATIO 800/4//-2~+2/ -1.5~1.5
//color
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
//RED FF0000
//GRE 00FF00
//BLU 0000FF

#define ESCAPE 4 // 2*2
//complex number = x(real) + y*i(imaginary)

//https://github.com/ilkou/minilibx/blob/master/key_linux.h
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define INCREASE 105//i
#define DECREASE 100//d
#define CHANGE 99//c
#define ZOOM_IN 4
#define ZOOM_OUT 5


typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

//create a buffer
// typedef struct	s_img
// {
// 	void	*img_ptr;//pointer to img struct
// 	char	*pixel;//point to the actual pixels
// 	int		bpp;//bits per pixel
// 	int		size_len;
// 	int		endian;//byteorder
// }				t_img;

typedef struct	S_fractal
{
	char	*name;
	void	*mlx;//void *mlx_init()
	void	*window;//mlx_new_window
	void	*image; //mlx_new_image
	char	*pixel;//mlx_get_data_addr
	int		bpp;//bits per pixel
	int		size_len;
	int		endian;
	int		max_iter;
	int		color;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

void	handle_err(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	render(t_fractal *fractal);
int		exit_fractal(t_fractal *fractal);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);


#endif
