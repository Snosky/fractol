/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:56:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 15:00:21 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

char	**get_valid_fractals(void)
{
	return (ft_strsplit("julia;mandelbrot;douady", ';'));
}
