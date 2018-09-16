/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:43:11 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/20 20:06:38 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_moveforjulia(int x, int y, t_matrix *matrix)
{
	if (matrix->julia_motion == 1)
	{
		if ((x > 0 && x <= 1000) && (y > 0 && y <= 1000) && matrix->id == 2)
		{
			matrix->julia_x = (double)x / (double)(matrix->zoom / 2);
			matrix->julia_y = (double)y / (double)(matrix->zoom / 2);
		}
		screen_fill(matrix);
	}
	return (0);
}
