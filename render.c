/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:04:21 by xiwang            #+#    #+#             */
/*   Updated: 2023/09/09 12:25:35 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// each pixel on your screen will execute the whole fractal's calculation(heavy)

// void render(t_fractal *fractal)
// {
// 	int x;
// 	int y;

// 	y = -1;
// 	while (++y < SIZE)
// 	{
// 		x = -1;
// 		while (++x < SIZE)
// 			draw_pixel(x, y, fractal);// draw each pixel
// 	}
// 	mlx_put_image_to_window(fractal->mlx,
// 			fractal->window,
// 			fractal->image, 0, 0);//img is ready to push to the window
// }
// the x, y location of where the image ought to be placed;

// double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
// {
//     return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
// }

// static void draw_pixel(int x, int y, t_fractal *fractal)
// {
// 	t_complex z;
// 	t_complex c;
// 	int i;

// 	z.x = scale(x, -2, 2, 0, SIZE) * fractal->zoom + fractal->shift_x;
// 	z.y = scale(y, 2, -2, 0, SIZE) * fractal->zoom + fractal->shift_y;
// 	// z.x = x / RATIO * fractal->zoom + fractal->offset_x;//-2左移
// 	// z.y = y / RATIO * fractal->zoom + fractal->offset_Y;//-1.35下移
// 	// mandel or julia
// 	if (ft_strncmp(fractal->name, "julia", 5) == 0)
// 	{
// 		c.x = fractal->julia_x; // in julia: c is constant
// 		c.y = fractal->julia_y; // sepreate??
// 	}
// 	else
// 	{
// 		c.x = z.x;
// 		c.y = z.y; // in mandel: z = 0
// 	}
// 	i = 0;
// 	while (i < fractal->max_iter)
// 	{
// 		z.x = z.x * z.x - z.y * z.y + c.x;
// 		z.y = 2 * z.x * z.y + c.y;// z = z*z (x*x - y*y + 2xy) + c
// 		if ((z.x * z.x) + (z.y * z.y) > 4)
// 		{
// 			fractal->color = scale(i, BLACK, WHITE, 0, fractal->max_iter);
// 			put_color_to_pix(x, y, fractal, fractal->color);//what if its too big?
// 			return ;
// 		}
// 		i++;
// 	}
// 	put_color_to_pix(x, y, fractal, BLACK);
// }

// void put_color_to_pix(int x, int y, t_fractal *fractal, int color)
// {
// 	int		pos;
// 	char	*temp;

// 	pos = y * fractal->size_len + x * (fractal->bpp / 8);
// 	temp = fractal->pixel + pos;
// 	*(unsigned int *)temp = color;
// }
/*
1. 指针:相同的大小

2. fractal->pixel是char *类型，当你有一个char *指针，

它指向的每个位置都表示一个字节。但如果你知道这些字节实际上组成了更大的数据结构
（如int，它可能由4个字节组成），那么将指针转换为int *可以使你更容易地操作这些数据。

3. 指针解引用: 一旦你进行了转换，解引用这个指针会得到不同的结果：
对char *解引用会得到一个char。
对unsigned int *解引用会得到一个unsigned int。

4. 所以当做unsigned int类型解引用
*/
