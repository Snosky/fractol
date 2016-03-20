/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:56:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 18:40:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

char	**get_valid_fractals(void)
{
	char	valid[] = {"julia,mandelbrot,douady"};

	return (ft_strsplit(valid, ','));
}
