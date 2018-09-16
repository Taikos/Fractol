/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:42:00 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 19:27:34 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_2(t_matrix *matrix, double x, double y)
{
	int		input;

	if (matrix->colour_change == 1)
		input = (0 << 16) + (0 << 8) + (0);
	else if (matrix->colour_change == 2)
		input = (238 << 16) + (65 << 8) + (244);
	else if (matrix->colour_change == 3)
		input = (255 << 16) + (255 << 8) + (0);
	else
		input = (0 << 16) + (0 << 8) + (0);
	matrix->img_data[((int)x * 4) + ((int)y * 4 * 1000)] = input >> 16 & 0xff;
	matrix->img_data[((int)x * 4)
		+ ((int)y * 4 * 1000) + 1] = input >> 8 & 0xff;
	matrix->img_data[((int)x * 4) + ((int)y * 4 * 1000) + 2] = input & 0xff;
}

void		draw_1(t_fractol *mandel, t_matrix *matrix, double x, double y)
{
	int		input;

	if (matrix->colour_change == 1)
		input = mandel->i * ((0 << 16) + (100 << 8) + (0))
			/ matrix->iteration_max;
	else if (matrix->colour_change == 2)
		input = mandel->i * ((65 << 16) + (244 << 8) + (196))
			/ matrix->iteration_max;
	else if (matrix->colour_change == 3)
		input = mandel->i * ((133 << 16) + (65 << 8) + (244))
			/ matrix->iteration_max;
	else
		input = mandel->i * ((255 << 16) + (170 << 8) + (255))
			/ matrix->iteration_max;
	matrix->img_data[((int)x * 4) + ((int)y * 4 * 1000)] = input >> 16 & 0xff;
	matrix->img_data[((int)x * 4)
		+ ((int)y * 4 * 1000) + 1] = input >> 8 & 0xff;
	matrix->img_data[((int)x * 4) + ((int)y * 4 * 1000) + 2] = input & 0xff;
}

void		fractal_mandelbar(double x, double y, t_matrix *matrix)
{
	t_fractol	*tri;
	double		tmp;

	if (!(tri = malloc(sizeof(t_fractol) + 1)))
		bug_display("No action-struct with not enough memory alloc\n");
	tri->z_r = 0;
	tri->z_i = 0;
	tri->c_r = x / matrix->zoom + matrix->x_min;
	tri->c_i = y / matrix->zoom + matrix->y_min;
	tri->i = 0;
	while (tri->i < matrix->iteration_max
			&& (pow(tri->z_r, 2) + pow(tri->z_i, 2) < 4))
	{
		tmp = tri->z_r;
		tri->z_r = pow(tri->z_r, 2) - pow(tri->z_i, 2) + tri->c_r;
		tri->z_i = -2 * tmp * tri->z_i + tri->c_i;
		tri->i++;
	}
	if (tri->i != matrix->iteration_max)
		draw_1(tri, matrix, x, y);
	else
		draw_2(matrix, x, y);
	free(tri);
}

void		fractal_julia(double x, double y, t_matrix *matrix)
{
	t_fractol	*julia;
	double		tmp;

	if (!(julia = malloc(sizeof(t_fractol) + 1)))
		bug_display("No action-struct with not enough memory alloc\n");
	julia->z_r = x / matrix->zoom + matrix->x_min;
	julia->z_i = y / matrix->zoom + matrix->y_min;
	julia->c_r = matrix->julia_x - 1;
	julia->c_i = matrix->julia_y - 1;
	julia->i = 0;
	while (julia->i < matrix->iteration_max
			&& (pow(julia->z_r, 2) + pow(julia->z_i, 2) < 4))
	{
		tmp = julia->z_r;
		julia->z_r = pow(julia->z_r, 2) - pow(julia->z_i, 2) + julia->c_r;
		julia->z_i = 2 * tmp * julia->z_i + julia->c_i;
		julia->i++;
	}
	if (julia->i != matrix->iteration_max)
		draw_1(julia, matrix, x, y);
	else
		draw_2(matrix, x, y);
	free(julia);
}

void		fractal_mandelbrot(double x, double y, t_matrix *matrix)
{
	t_fractol	*mandel;
	double		tmp;

	if (!(mandel = malloc(sizeof(t_fractol) + 1)))
		bug_display("No action-struct with not enough memory alloc\n");
	mandel->z_r = 0;
	mandel->z_i = 0;
	mandel->c_r = x / matrix->zoom + matrix->x_min;
	mandel->c_i = y / matrix->zoom + matrix->y_min;
	mandel->i = 0;
	while (mandel->i < matrix->iteration_max
			&& (pow(mandel->z_r, 2) + pow(mandel->z_i, 2) < 4))
	{
		tmp = mandel->z_r;
		mandel->z_r = pow(mandel->z_r, 2) - pow(mandel->z_i, 2) + mandel->c_r;
		mandel->z_i = 2 * tmp * mandel->z_i + mandel->c_i;
		mandel->i++;
	}
	if (mandel->i != matrix->iteration_max)
		draw_1(mandel, matrix, x, y);
	else
		draw_2(matrix, x, y);
	free(mandel);
}
