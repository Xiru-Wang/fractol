# Fract-ol
Fascinating Fractals!!
We will learn about manipulating a low-level graphic library: MinilibX, advanced math, and handling the events.

Both the Mandelbrot and Julia sets are visual representations of complex mathematical formulas, and they produce stunningly intricate patterns and designs.

# Mandelbrot VS Julia
Use the same mathematical formula

![12](https://github.com/Xiru-Wang/fractol/assets/79924696/2ed31bf8-61ae-4ca4-a398-41073abc6605)

# What is a complex number?
![13](https://github.com/Xiru-Wang/fractol/assets/79924696/340fba85-27cb-4891-8d57-3463c9ffe9f1)

# Calculation Process
![14](https://github.com/Xiru-Wang/fractol/assets/79924696/997f3a7d-556c-4ddf-a12f-e99a0f9d6b27)

**Mandelbrot Set:**
- Z= Z*Z + C, Z(0) = 0, C = each point on the plane
- applying the mathematical formula repeatedly to each point(C) on the plane. 
- After i iteration, if Z escaped or stayed bounded
- Black: bounded complex numbers.
- Colored: escaped complex numbers.
- Color depths: iterations or escape speed
- if z.x * z.x + z.y * z.y > 4, escaped

**Julia Set:**
- Z= Z*Z + C, C = a fixed complex number, Z = each point on the plane(THE MAIN DIFFERENCE)
- applying a mathematical formula repeatedly to each point(Z) on the plane.
- After i iteration, if Z escaped or stayed bounded
- The shape and detail of the Julia set looks different, based on that fixed number(C).

#Compile flags on Linux
cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol

-L: path to the library 

-l: link

#Rescale the image to fit the coordinate axis
````
//Unfortunately we cannot use this scale method because of 42's norm rules
(new_max - new_min) / (old_max - old_new) * (value_to_calculate - old_min) + new_min
````
However, we can do a simple calculation: 1. scale down the image into a 4*4 plane (x:-2~2, y: 2~-2), 2. add the offset values to move the scaled image to the middle of the plane.
````
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

t_complex z;

//eg. if the image_before:800 * 800, image_after: 4 * 4, scale_ratio = 800.0/4
z.x = x / scale_ratio + fractal->offset_x;
z.y = -y / scale_ratio + fractal->offset_y;

````
![11](https://github.com/Xiru-Wang/fractol/assets/79924696/276d83fd-98ad-4272-878f-deea51f1ebd8)
![10](https://github.com/Xiru-Wang/fractol/assets/79924696/e34c0660-3c68-49c2-bb78-45b9554e4b71)

# How image displayed on the screen
````
pos = (y * fractal->img.size_line) + ((fractal->img.bpp / 8) * x); 
````
It tells you how to find the pixel data corresponding to that coordinate in memory.
size_line: how many bytes each line, so y will move down so many lines.
bpp/8: to get how many bytes per pixel, eg. 1 pixel requires 3 bytes, then x moves to right x*3 bytes
<img width="1136" alt="Screenshot 2023-09-04 at 20 17 28" src="https://github.com/Xiru-Wang/fractol/assets/79924696/1ba8ab0d-ab36-46a3-a0c9-f80c12f03d48">
screenshot from https://www.youtube.com/watch?v=ANLW1zYbLcs&t=6502s
He has an excellent explanation(THANK YOU), check it out!


# Endianess/Byte Order
The number 0x12345678 
-Big Endian: 12 34 56 78 
-Little Endian:78 56 34 12

https://www.youtube.com/watch?v=LxvFb63OOs8
https://www.youtube.com/watch?v=CounrFEsOeA
Endianess refers to the ordering of bytes in multi-byte data types (like int, float, etc.) as they are stored in memory.
In Big Endian, the most significant byte is stored at the lowest memory address, and the least significant byte at the highest memory address.
In Little Endian, the least significant byte is stored at the lowest memory address, and the most significant byte at the highest.

#Use MinilibX
````
//STEP 1: Establish the connection with X window server
void *mlx = mlx_init();

//STEP 2: Create a window
void *window = mlx_destroy_window(mlx, WIDTH, HEIGHT, "fractol");

//STEP 3: Events
mlx_mouse_hook(window, function, data);
mlx_key_hook(window, function, data);
mlx_hook(window, 17, 0, exit_function, data);//17: exit, close window

//STEP 4: keeps the program alive & listening events
mlx_loop(mlx);
//As long as the program is running, this loop continues to execute

//CLEAN UP
mlx_destroy_window(mlx, window);
mlx_destroy_display(mlx);
free(connection);

````
# Understand mlx_get_data_addr(): Get mem address to write pixels

````
#include <mlx.h>

typedef struct s_img
{
 void *img_ptr;
 char *img_pixels;//pointer to the first byte of the image
 int  bpp;
 int  size_line;
 int  endian;
}    t_img;

int main(void)
{
 void *mlx;
 t_img img;

 mlx = mlx_init();
 img.img_ptr = mlx_new_image(mlx, 1920, 1080);

/*
You're telling mlx_get_data_addr(): "Please provide me with the data parameters for this image and store the bits per pixel, the size of each line, and the endian in the addresses I've provided."
*/
 img.img_pixels = mlx_get_data_addr(img.img_ptr,
                                    &img.bpp,
                                    &img.size_line,
                                    &img.endian);
}

````

#Resources: Images, RGB, Pixels
https://www.youtube.com/watch?v=15aqFQQVBWU
#Resouces: Events_key
https://github.com/ilkou/minilibx/blob/master/key_linux.h
