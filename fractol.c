/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:44:01 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 20:20:05 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_actions(int *id)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(t_matrix) + 1)))
		bug_display("No action-struct with not enough memory alloc\n");
	matrix->mlx_ptr = mlx_init();
	matrix->win_ptr = mlx_new_window(matrix->mlx_ptr, 1000, 1000, "fractol");
	matrix->id = id[0];
	screen_display(matrix);
	free(matrix);
}

int		main(int n, char **file)
{
	int		*fractal_id;

	if (n == 2)
	{
		if ((!ft_strcmp(file[1], "1"))
			|| (!ft_strcmp(file[1], "2")) || (!ft_strcmp(file[1], "3")))
		{
			if (!(fractal_id = malloc(sizeof(int) * 1 + 1)))
				bug_display("No action-struct with not enough memory alloc\n");
			fractal_id[0] = ft_atoi(file[1]);
			fractol_actions(fractal_id);
			free(fractal_id);
		}
		else
			bug_display("Wrong entry - add a unique digit between 1 and 3\n");
	}
	else
		bug_display("Wrong init - add a unique digit between 1 and 3\n");
	return (0);
}
