/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_put_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:40:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 15:46:13 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_put_px(t_env *env, t_frac frac)
{
	int	a;
	int	b;

	a = MAXITE * 33 / 100;
	b = MAXITE * 66 / 100;
	if (frac.i <= a)
		ft_put_px_img(env, frac.px.x, frac.px.y, \
				rgba(frac.i * 255 / a, 0, 0, 0));
	else if (frac.i <= b)
		ft_put_px_img(env, frac.px.x, frac.px.y, \
				rgba(0, frac.i * 255 / b, 0, 0));
	else
		ft_put_px_img(env, frac.px.x, frac.px.y, \
				rgba(0, 0, frac.i * 255 / MAXITE, 0));	
}
