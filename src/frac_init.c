/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:18:17 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 18:41:04 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	frac_init(t_env *env, char *frac)
{
	if (ft_strcmp(frac, "julia") == 0)
		frac_julia(env);
	else if (ft_strcmp(frac, "mandelbrot") == 0)
		frac_mandelbrot(env);
	else if (ft_strcmp(frac, "douady") == 0)
		frac_douady(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);	
}
