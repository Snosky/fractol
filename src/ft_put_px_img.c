/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_px_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:29:30 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 16:30:40 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_put_px_img(t_env *env, int x, int y, int color)
{
	ft_memcpy(&env->img.data[(x * 4) + (y * env->img.sizeline)], \
		&color, (size_t)(sizeof(int)));
}
