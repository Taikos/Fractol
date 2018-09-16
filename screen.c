/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:43:40 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 19:16:50 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		screen_exp(t_matrix *matrix)
{
	if (matrix->id == 1)
		mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 20, 0x0042bff4,
				"Fractol model = Mandelbrot model");
	else if (matrix->id == 2)
	{
		mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 20, 0x0042bff4,
				"Fractol model = Julia model");
		mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 150, 0x00fffff,
				"Fractol variation: move the mouse");
		mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 170, 0x00fffff,
				"Off = Space bar, On = Cmd left");
	}
	else if (matrix->id == 3)
		mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 20, 0x0042bff4,
				"Fractol model = Mandelbar model");
	mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 50, 0x00ffffff,
			"Quit: Press ESC");
	mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 70, 0x00ffffff,
			"Change color: Press 0, 1, 2 or 3");
	mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 90, 0x00ffffff,
			"Zoom: Use the mouse wheel or click");
	mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 110, 0x00ffffff,
			"Moves: Use the arrows");
	mlx_string_put(matrix->mlx_ptr, matrix->win_ptr, 2, 130, 0x00ffffff,
			"Change fractal: Press q, w or e");
}

t_matrix	screen_fill(t_matrix *matrix)
{
	double	x;
	double	y;

	x = 0;
	while (x++ < matrix->x_size)
	{
		y = 0;
		while (y++ < matrix->y_size)
		{
			if (matrix->id == 1)
				fractal_mandelbrot(x, y, matrix);
			if (matrix->id == 2)
				fractal_julia(x, y, matrix);
			if (matrix->id == 3)
				fractal_mandelbar(x, y, matrix);
			if (y >= 1000)
				break ;
		}
		if (x >= 1000)
			break ;
	}
	mlx_put_image_to_window(matrix->mlx_ptr, matrix->win_ptr,
			matrix->img, 0, 0);
	screen_exp(matrix);
	return (*matrix);
}

void		screen_display(t_matrix *matrix)
{
	matrix->bpp = 4 * 8;
	matrix->s_l = 4 * 1000;
	matrix->endian = 0;
	matrix->img = mlx_new_image(matrix->mlx_ptr, 1000, 1000);
	matrix->img_data = mlx_get_data_addr(matrix->img, &matrix->bpp,
			&matrix->s_l, &matrix->endian);
	matrix->x_min = -2.35;
	matrix->y_min = -1.2;
	matrix->x_max = 0.85;
	matrix->y_max = 1.2;
	matrix->zoom = 350;
	matrix->x_size = (matrix->x_max - matrix->x_min) * matrix->zoom;
	matrix->y_size = (matrix->y_max - matrix->y_min) * matrix->zoom;
	matrix->iteration_max = 50;
	matrix->colour_change = 0;
	matrix->julia_motion = 1;
	screen_fill(matrix);
	screen_option(matrix);
}
