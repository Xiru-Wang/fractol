# Fract-ol
Write a program to generate stunning Fractals.
We will learn about manipulating a low-level graphic library: MinilibX, advanced math, and handling the events.

Both the Mandelbrot and Julia sets are visual representations of complex mathematical formulas, and they produce stunningly intricate patterns and designs.

**Mandelbrot Set:**
- Z= Z*Z + C, Z(0) = 0, C = each point on the plane
- applying a mathematical formula repeatedly to each point(C) on the plane. 
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


# Minilibx - Simple Graphical Interface Library built upon x library speak to X-server
- allow us to draw things on the screen
- X-server: an invisible middleman between your program and the device(keyboard, mouse, and screen)
- man mlx(terminal)

#Usage
cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol

-L: path to the library 

-l: link

#Images, RGB, Pixels
https://www.youtube.com/watch?v=15aqFQQVBWU



````
//STEP 1: Establish the connection with X window server
void *mlx = mlx_init(); // function includes malloc
//if failed mlx_destroy_display(mlx);// free the resources

//STEP 2: Create a window
void *window = mlx_destroy_window(mlx, WIDTH, HEIGHT, "name of the window");

//STEP 3: Events...
mlx_mouse_hook(window, function, data);
mlx_key_hook(window, function, data);
mlx_hook(window, 17, 0, exit_function, data);//17: exit, close window

//STEP 4: keeps the function alive
mlx_loop(mlx);
//Without this loop, the process will stop immediately
//Keeps the program/application running
//As long as the program is running, this loop continues to execute

//LAST SETP:clean up
mlx_destroy_window(mlx, window);
mlx_destroy_display(mlx);
free(connection);
//exit in a clean way, close the connection to the X server

````

Get the memory address to write pixels
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

