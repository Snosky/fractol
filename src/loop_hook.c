/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 15:29:30 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 17:39:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			loop_hook(t_env *env)
{
	if (env->status == MLX_REFRESH)
	{
		frac_init(env, env->frac_name);
		env->status = MLX_WAIT;
	}
	else if (env->status == MLX_EXIT)
	{
		mlx_destroy_image(env->mlx, env->img.img);
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
