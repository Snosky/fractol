/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:30:36 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 18:19:34 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_mandelbrot(t_env *env)
{
	t_frac	frac;

	frac.x1 = -2.1;
	frac.y1 = -1.2;
	frac.px.x = 0;
	while (frac.px.x < WIN_SX)
	{
		frac.px.y = 0;
		while (frac.px.y < WIN_SY)
		{
			frac.cr = (frac.px.x + env->off.x) / env->zoom + frac.x1;
			frac.ci = (frac.px.y + env->off.y) / env->zoom + frac.y1;
			frac.zr = 0;
			frac.zi = 0;
			frac.i = 0;
			frac_calc(&frac, frac.cr, frac.ci);
			if (frac.i == MAXITE)
				ft_put_px_img(env, frac.px.x, frac.px.y, 0x00000000);
			else
				ft_put_px_img(env, frac.px.x, frac.px.y, rgba(0, 0, frac.i * 255 / MAXITE, 0));
			frac.px.y++;
		}
		frac.px.x++;
	}
}
