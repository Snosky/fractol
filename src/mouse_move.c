/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:10:35 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 18:12:32 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_move(int x, int y, t_env *env)
{
	env->cr = (double)(x - WIN_SX / 2) / env->zoom;
	env->ci = (double)(y - WIN_SY / 2) / env->zoom;
	env->status = MLX_REFRESH;
	return (0);	
}