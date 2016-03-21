/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 15:24:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 16:13:43 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	move_y(int i, t_env *env)
{
	env->off.y += i;
	env->status = MLX_REFRESH;
}

void	move_x(int i, t_env *env)
{
	env->off.x += i;
	env->status = MLX_REFRESH;
}

int			key_hook(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	if (keycode == 65307 || keycode == 53)
		env->status = MLX_EXIT;
	else if (keycode == 65362 || keycode == 126)
		move_y(5, env);
	else if (keycode == 65361 || keycode == 123)
		move_x(5, env);
	else if (keycode == 65363 || keycode == 124)
		move_x(-5, env);
	else if (keycode == 65364 || keycode == 125)
		move_y(-5, env);
	else if (keycode == 8)
		env->mouse_status = (env->mouse_status == MOUSE_LOCK) \
							? MOUSE_UNLOCK : MOUSE_LOCK;
	return (0);
}
