/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:28:23 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 14:59:08 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 4)
	{
		env->zoom *= ZOOM;
		env->off.x = (env->off.x + ((WIN_SX - (WIN_SX / ZOOM)) / 2)
			+ (x - WIN_SX / 2) * (1 - (1 / ZOOM))) * ZOOM;
		env->off.y = (env->off.y + ((WIN_SY - (WIN_SY / ZOOM)) / 2)
			+ (y - WIN_SY / 2) * (1 - (1 / ZOOM))) * ZOOM;
		env->status = MLX_REFRESH;
	}
	else if (button == 5)
	{
		env->zoom /= ZOOM;
		env->off.x = env->off.x / ZOOM - ((WIN_SX - (WIN_SX / ZOOM)) / 2)
			/ ZOOM - (x - WIN_SX / 2) * (1 - (1 / ZOOM)) + ZOOM;
		env->off.y = env->off.y / ZOOM - ((WIN_SY - (WIN_SY / ZOOM)) / 2)
			/ ZOOM - (y - WIN_SX / 2) * (1 - (1 / ZOOM)) + ZOOM;
		env->status = MLX_REFRESH;
	}
	return (0);
}
