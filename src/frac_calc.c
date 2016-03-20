/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:55:29 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 18:09:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_calc(t_frac *frac, double cr, double ci)
{
	double		rzr;
	double		rzi;

	rzr = frac->zr * frac->zr;
	rzi = frac->zi * frac->zi;
	frac->i = 0;
	while ((rzr + rzi) < 4 && frac->i < MAXITE)
	{
		frac->zi = 2 * frac->zi * frac->zr + ci;
		frac->zr = rzr - rzi + cr;
		rzr = frac->zr * frac->zr;
		rzi = frac->zi * frac->zi;
		frac->i++;
	}
}
