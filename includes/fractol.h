/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:07:14 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/21 15:55:27 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <libft.h>

# define WIN_SX 1280
# define WIN_SY 1024
# define MAXITE 2000

# define MLX_REFRESH 1
# define MLX_EXIT -1
# define MLX_WAIT 0

# define ZOOM 1.01

typedef struct	s_px
{
	int	color;
	int	x;
	int y;
}				t_px;

typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bpx;
	int		sizeline;
	int		endian;
	int		clrline;
}				t_img;

typedef struct	s_frac
{
	double	x1;
	double	y1;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
	int		i;
	t_px	px;
}				t_frac;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	char	*frac_name;
	int		status;
	t_px	off;
	double	cr;
	double	ci;
}				t_env;

t_env	*init_env(char *name);
int		key_hook(int keycode, t_env *env);
int		loop_hook(t_env *env);
int		mouse_hook(int button, int x, int y, t_env *env);
int		mouse_move(int x, int y, t_env *env);
int		expose_hook(t_env *env);
int		rgba(int r, int g, int b, int a);
void	ft_put_px_img(t_env *env, int x, int y, int color);
char	**get_valid_fractals();
void	frac_init(t_env *env, char *frac);
void	frac_calc(t_frac *frac, double cr, double ci);
void	frac_julia(t_env *env);
void	frac_mandelbrot(t_env *env);
void	frac_douady(t_env *env);
void	frac_put_px(t_env *env, t_frac frac);
#endif
