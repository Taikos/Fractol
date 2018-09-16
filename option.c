/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:42:53 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 18:57:13 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int keycode, int x, int y, t_matrix *matrix)
{
	double	x_init;
	double	y_init;

	x_init = (x / matrix->zoom) + matrix->x_min;
	y_init = (y / matrix->zoom) + matrix->y_min;
	if (keycode == 2 || keycode == 4)
	{
		matrix->zoom = matrix->zoom / 1.3;
		matrix->x_min = x_init - (x / matrix->zoom);
		matrix->y_min = y_init - (y / matrix->zoom);
	}
	if (keycode == 1 || keycode == 5)
	{
		matrix->zoom = matrix->zoom * 1.3;
		matrix->x_min = x_init - (x / matrix->zoom);
		matrix->y_min = y_init - (y / matrix->zoom);
	}
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	screen_fill(matrix);
	return (0);
}

int		key_funct_cl(int keycode, t_matrix *matrix)
{
	if (keycode == 29 || keycode == 82)
		matrix->colour_change = 0;
	if (keycode == 18 || keycode == 83)
		matrix->colour_change = 1;
	if (keycode == 19 || keycode == 84)
		matrix->colour_change = 2;
	if (keycode == 20 || keycode == 85)
		matrix->colour_change = 3;
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	screen_fill(matrix);
	return (0);
}

int		key_funct_2(int keycode, t_matrix *matrix)
{
	if (keycode == 53)
	{
		mlx_destroy_window(matrix->mlx_ptr, matrix->win_ptr);
		exit(0);
	}
	if (keycode == 49)
		matrix->julia_motion = 0;
	if (keycode == 259)
		matrix->julia_motion = 1;
	if (keycode == 126)
		matrix->y_min += 40 / matrix->zoom;
	if (keycode == 123)
		matrix->x_min += 40 / matrix->zoom;
	if (keycode == 125)
		matrix->y_min -= 40 / matrix->zoom;
	if (keycode == 124)
		matrix->x_min -= 40 / matrix->zoom;
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	screen_fill(matrix);
	return (0);
}

int		key_funct_1(int keycode, t_matrix *matrix)
{
	if (keycode == 12)
	{
		matrix->id = 1;
		mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
		screen_display(matrix);
	}
	if (keycode == 13)
	{
		matrix->id = 2;
		mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
		screen_display(matrix);
	}
	if (keycode == 14)
	{
		matrix->id = 3;
		mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
		screen_display(matrix);
	}
	key_funct_2(keycode, matrix);
	key_funct_cl(keycode, matrix);
	return (0);
}

void	screen_option(t_matrix *matrix)
{
	mlx_key_hook(matrix->win_ptr, key_funct_1, matrix);
	mlx_mouse_hook(matrix->win_ptr, mouse_hook, matrix);
	mlx_hook(matrix->win_ptr, 6, 0, mouse_moveforjulia, matrix);
	mlx_loop(matrix->mlx_ptr);
}
