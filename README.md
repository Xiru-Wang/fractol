# fractol
Minilibx: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

Psychedelic color set: https://www.color-hex.com/color-palette/5784

Video tutorial: https://www.youtube.com/@onaecO/videos
https://medium.com/@jalal92/fractol-22a21a1ad5bd

````
mlx_init(); //Establish the connection with X window server && malloc display

mlx_loop(connection);//keeps the function alive
mlx_destroy_window();
mlx_destroy_display();//free, exit in a clean way, close the connection to the X server
free(connection);

````
#Data Alignment
````
offset = (y * fractal->img.bytes_line) + ((fractal->img.bpp / 8) * x); 
````
This line computes the memory offset corresponding to a given coordinate (x, y) in a 2D image data storage structure. 

In short, it tells you how to find the pixel data corresponding to that coordinate in memory.
bytes_line: how many bytes each line, so y will move down so many lines.
bpp/8: to get how many bytes per pixel, eg. 1 pixel requires 3 bytes, then x moves to right x*3 bytes


#Color Depth / Bits Per Pixel
- 1 bit: Black & White 2^1
- 2 bits: 4 colors. 2^2
- 8 bits: 256 colors. 2^8

- 
