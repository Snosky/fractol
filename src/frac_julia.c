/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:19:55 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 15:57:10 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_julia(t_env *env)
{
	t_frac	frac;

	frac.x1 = -1;
	frac.y1 = -1.2;
	frac.px.x = 0;
	env->off.x = WIN_SX / 4 * -1;
	while (frac.px.x < WIN_SX)
	{
		frac.px.y = 0;
		while (frac.px.y < WIN_SY)
		{
			frac.zr = (frac.px.x + env->off.x) / env->zoom + frac.x1;
			frac.zi = (frac.px.y + env->off.y) / env->zoom + frac.y1;
			frac_calc(&frac, env->cr, env->ci);
			frac_put_px(env, frac);
			frac.px.y++;
		}
		frac.px.x++;
	}
}
