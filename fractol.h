/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:42:29 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 20:03:38 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_fractol
{
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	i;
}				t_fractol;

typedef struct	s_matrix
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		id;
	void	*img;
	char	*img_data;
	int		bpp;
	int		s_l;
	int		endian;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	double	zoom;
	double	iteration_max;
	double	x_size;
	double	y_size;
	int		colour_change;
	double	julia_x;
	double	julia_y;
	int		julia_motion;
}				t_matrix;

int				mouse_moveforjulia(int x, int y, t_matrix *matrix);
int				mouse_hook(int keycode, int x, int y, t_matrix *matrix);
int				key_funct_cl(int keycode, t_matrix *matrix);
int				key_funct_2(int keycode, t_matrix *matrix);
int				key_funct_1(int keycode, t_matrix *matrix);
void			screen_option(t_matrix *matrix);
void			screen_exp(t_matrix *matrix);
void			draw_2(t_matrix *matrix, double x, double y);
void			draw_1(t_fractol *mandel, t_matrix *matrix, double x, double y);
void			fractal_mandelbar(double x, double y, t_matrix *matrix);
void			fractal_julia(double x, double y, t_matrix *matrix);
void			fractal_mandelbrot(double x, double y, t_matrix *matrix);
t_matrix		screen_fill(t_matrix *matrix);
void			screen_display(t_matrix *matrix);
void			fractol_actions(int *id);
void			bug_display(char *str);
int				main(int n, char **file);

#endif
