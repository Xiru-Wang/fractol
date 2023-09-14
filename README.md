# Fract-ol
Fascinating Fractals!! 
# Mandelbrot VS Julia

![mandelbrot & julia](https://github.com/Xiru-Wang/fractol/assets/79924696/77bb3385-0db2-442a-b850-7f06bf0c6790)
Generated by a simple mathematical formula with complex numbers.

# What is a complex number?
![complex number in mandelbrot](https://github.com/Xiru-Wang/fractol/assets/79924696/340fba85-27cb-4891-8d57-3463c9ffe9f1)
That's how we get our x-axis(real part), and y-axis(imaginary part).

# Calcultion
![calculate mandelbrot](https://github.com/Xiru-Wang/fractol/assets/79924696/997f3a7d-556c-4ddf-a12f-e99a0f9d6b27)

**Mandelbrot Set:**
- Z(0) = 0, C = each point on the plane
- applying the mathematical formula repeatedly to each point(C) on the plane. 
- Black: bounded Z
- Colored: escaped Z
- Color depths: escape speed
  Escaped or not?
- After i iteration, if Z escaped or stayed bounded
- if z.x * z.x + z.y * z.y > 4, escaped

**Julia Set (Difference):**
- C = a fixed complex number, Z = each point on the plane
- The shape and detail of the Julia set looks different, based on that fixed number(C)

# How image displayed on the screen

Calculate each single pixel(x, y), and put color to the pixel's memory address

The headache I had was this part: Julia set appears mirrored. 
I took a reference from a program that was awarded 125 points, however, it was actually incorrect. After one hour of troubleshooting, I realized that the screen image displays in a different way in our coordinate axis(which we will use to do calculations). My drawing below explains better:

![screen image to coordinate axis](https://github.com/Xiru-Wang/fractol/assets/79924696/e34c0660-3c68-49c2-bb78-45b9554e4b71)

Sometimes the simplest issues take the longest to pinpoint.

Next, we'll resize the image and center it on our coordinate axis. With this adjustment, we can proceed with calculations using our familiar (x, y) coordinates, confident that the final image will display correctly on the screen.
![image offset](https://github.com/Xiru-Wang/fractol/assets/79924696/276d83fd-98ad-4272-878f-deea51f1ebd8)

#Rescale & adjust the image to fit the coordinate axis
````
// ✅ Versatile, easy to adjust window size
// ❌ Only 4 parameters allow according to 42's norm
// ❌ More calculation, more workload

(new_max - new_min) / (old_max - old_new) * (value_to_calculate - old_min) + new_min

````
However, we can do a simple calculation: 
1. scale down the image into a 4*4 plane (x: -2 to 2, y: 2 to -2)
2. add the offset values to move the scaled image to the middle of the plane.
   
````
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

t_complex z;

//image_before:800 * 800
//image_after: 4 * 4
//scale_ratio = 800.0/4
z.x = x / scale_ratio + fractal->offset_x;
z.y = -y / scale_ratio + fractal->offset_y;

````
# Pixel position in memory

An image is a 2D grid, we travel through the whole grid from left to right, top to down.
Find the pixel data corresponding to that coordinate in memory.
-size_line: how many bytes each line, so y will move so many bytes to reach its line.
-bpp/8: to get how many bytes per pixel， a color can take 3 or 4 bytes. (read more about Data Alignment)

````
void	put_color_to_pix(int x, int y, t_fractal *fractal, int color)
{
	int		pos;
	char	*temp;

	pos = y * fractal->size_len + x * (fractal->bpp / 8);
	//Pixel position in memory
	temp = fractal->pixel + pos;
	*(unsigned int *)temp = color;// assign color to that location
	//typecast char pointer to unsigned int pointer
}

````

<img width="1136" alt="Screenshot 2023-09-04 at 20 17 28" src="https://github.com/Xiru-Wang/fractol/assets/79924696/1ba8ab0d-ab36-46a3-a0c9-f80c12f03d48">

Screenshot: https://www.youtube.com/watch?v=ANLW1zYbLcs&t=6502s.
He has an excellent explanation of this project(THANK YOU SO MUCH), check it out!

# Data Alignment 
For a 4-byte int, it should be stored at addresses 0, 4, 8, 12,... etc.

For a 3-byte color value, the situation is slightly more complicated. 
Theoretically, it could start at any address. However, for alignment purposes, a padding byte may be added after the 3 bytes, allowing the next data to be 4-byte aligned again. So, even though the color value itself is 3 bytes, 4 bytes of space may actually be allocated to ensure alignment.

# Endianess/Byte Order
The number 0x12345678 
-Big Endian: 12 34 56 78 
-Little Endian:78 56 34 12

https://www.youtube.com/watch?v=LxvFb63OOs8
https://www.youtube.com/watch?v=CounrFEsOeA
Endianess refers to the ordering of bytes in multi-byte data types (like int, float, etc.) as they are stored in memory.
In Big Endian, the most significant byte is stored at the lowest memory address, and the least significant byte at the highest memory address.
In Little Endian, the least significant byte is stored at the lowest memory address, and the most significant byte at the highest.

#Steps to Use MinilibX
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
# Understand mlx_get_data_addr()

Get memory address to write pixels
````
/*
You're telling mlx_get_data_addr(): "Please provide me with the data parameters for this image and store the bits per pixel, the size of each line, and the endian in the addresses I've provided."
*/
 img.img_pixels = mlx_get_data_addr(img.img_ptr,
                                    &img.bpp,
                                    &img.size_line,
                                    &img.endian);

````

#Resources: Images, RGB, Pixels
https://www.youtube.com/watch?v=15aqFQQVBWU
#Resouces: Events_key
https://github.com/ilkou/minilibx/blob/master/key_linux.h
