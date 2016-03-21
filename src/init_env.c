/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:40:36 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 16:11:12 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_env	*init_env(char *name)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(env->mlx = mlx_init()))
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	env->win = mlx_new_window(env->mlx, WIN_SX, WIN_SY, name);
	env->img.img = mlx_new_image(env->mlx, WIN_SX, WIN_SY);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpx, \
		&env->img.sizeline, &env->img.endian);
	env->zoom = 300;
	env->frac_name = ft_strdup(name);
	env->off.x = -100;
	env->off.y = -100;
	env->mouse_status = MOUSE_UNLOCK;
	return (env);
}
