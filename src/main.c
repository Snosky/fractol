/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:17:50 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/20 23:35:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

static void	do_help(void)
{
	char	**fractals;
	int		i;
	int		color;

	fractals = get_valid_fractals();
	i = 0;
	color = 30;
	ft_putendl_fd("usage: ./fractol [fractal name].", 2);
	ft_putstr_fd("Valid fractal name: ", 2);
	while (fractals[i])
	{
		if (color > 37)
			color = 30;
		ft_putstr_fd(ft_strreplace("_C_", ft_itoa(color++), "\e[1;_C_m"), 2);
		ft_putstr_fd(fractals[i], 2);
		ft_putstr_fd("\e[0m", 2);
		if (fractals[i + 1])
			ft_putstr_fd(", ", 2);
		free(fractals[i]);
		i++;
	}
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

static int	is_valid_fractal(char *fractal)
{
	char	**fractals;
	int		i;

	fractals = get_valid_fractals();
	i = 0;
	while (fractals[i])
	{
		if (ft_strcmp(fractals[i], fractal) == 0)
		{
			free(fractals[i]);
			return (1);
		}
		free(fractals[i]);
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	if (ac == 2 && is_valid_fractal(av[1]))
	{
		if (!(env = init_env(av[1])))
			return (0);
		frac_init(env, av[1]);
		mlx_key_hook(env->win, key_hook, env);
		mlx_loop_hook(env->mlx, loop_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_hook(env->win, MotionNotify, PointerMotionMask, mouse_move, env);
		mlx_loop(env->mlx);
		return (0);

	}
	else
		do_help();
	
}
