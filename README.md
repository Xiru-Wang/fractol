# Fract-ol
Write a program to generate stunning Fractals.
We will learn about manipulating a low-level graphic library: MinilibX, advanced math, and handling the events.

Both the Mandelbrot and Julia sets are visual representations of complex mathematical formulas, and they produce stunningly intricate patterns and designs.

**Mandelbrot Set:**
- Think of it as a collection of complex numbers. 
- For each point on the plane, you repeatedly apply a simple mathematical formula and watch how the result changes. 
- If, after many iterations, the result remains close to the starting point, then that point is in the Mandelbrot set, and it's typically colored black on images. If it "escapes" or goes far away, it's not in the set, and its color is based on how quickly it escaped.
- Visually, it's a mesmerizing mix of swirling shapes with infinitely repeating patterns.

**Julia Set:**
- Like the Mandelbrot set, it's about applying a mathematical formula repeatedly to each point on the plane. 
- The main difference is that while the Mandelbrot set uses the same formula for every point, the Julia set uses a different, fixed complex number for its formula for each different Julia set.
- The shape and detail of the resulting pattern vary based on that fixed number.
- Each Julia set looks different, but all have intricate, often symmetrical patterns.

# Minilibx - Simple Graphical Interface Library
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

https://github.com/suspectedoceano/fractol/tree/main

Psychedelic color set: https://www.color-hex.com/color-palette/5784

Video tutorial: https://www.youtube.com/@onaecO/videos

https://medium.com/@jalal92/fractol-22a21a1ad5bd

#Usage
cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
L: path to the library 

#Images, RGB, Pixels
https://www.youtube.com/watch?v=15aqFQQVBWU



````
mlx_init(); //Establish the connection with X window server && malloc display

mlx_loop(connection);//keeps the function alive
mlx_destroy_window();
mlx_destroy_display();//free, exit in a clean way, close the connection to the X server
free(connection);

````

Get the memory address to write pixels
````
#include <mlx.h>

typedef struct s_img
{
 void *img_ptr;
 char *img_pixels;
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
 img.img_pixels = mlx_get_data_addr(img.img_ptr,
                                    &img.bpp,
                                    &img.size_line,
                                    &img.endian);
}

````
Passing bpp, size_line, and endian to mlx_get_data_addr() without initializing them:

When you pass the address of a variable to a function, that function has the ability to modify the value at that address. In this case, the function mlx_get_data_addr() is expected to return certain parameters about the image data and will modify the values of bpp, size_line, and endian directly via the addresses you provided.
This approach is often used to return multiple values. Since C functions can only return one value, returning multiple values by modifying them via passed addresses is a common practice.

So, when you do:
````
img.img_pixels = mlx_get_data_addr(img.img_ptr,
                                   &img.bpp,
                                   &img.size_line,
                                   &img.endian);
````
You're essentially telling mlx_get_data_addr(): "Please provide me with the data parameters for this image and store the bits per pixel, the size of each line, and the endianess in the addresses I've provided."

The function then populates these values into the respective variables, so even if you didn't initialize them before passing them, they would hold the appropriate values after the function call.

Endianess/Byte Order:
https://www.youtube.com/watch?v=LxvFb63OOs8
https://www.youtube.com/watch?v=CounrFEsOeA
Endianess refers to the ordering of bytes in multi-byte data types (like int, float, etc.) as they are stored in memory.
In Big Endian, the most significant byte is stored at the lowest memory address, and the least significant byte at the highest memory address.
In Little Endian, the least significant byte is stored at the lowest memory address, and the most significant byte at the highest.
For example, the number 0x12345678 would be stored as 12 34 56 78 in Big Endian and 78 56 34 12 in Little Endian.


#Data Alignment
````
offset = (y * fractal->img.size_line) + ((fractal->img.bpp / 8) * x); 
````
This line computes the memory offset corresponding to a given coordinate (x, y) in a 2D image data storage structure. 

In short, it tells you how to find the pixel data corresponding to that coordinate in memory.
size_line: how many bytes each line, so y will move down so many lines.
bpp/8: to get how many bytes per pixel, eg. 1 pixel requires 3 bytes, then x moves to right x*3 bytes

#Rescale to fit the window
````
(new_max - new_min) / (old_max - old_new) * (value_to_calculate - old_min) + new_min
//new range / old range = ratio
//ratio * old distance + new_min(starting value)
````

#Color Depth / Bits Per Pixel
- 1 bit: Black & White 2^1
- 2 bits: 4 colors. 2^2
- 8 bits: 256 colors. 2^8

