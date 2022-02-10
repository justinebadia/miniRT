/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:56:38 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/08 10:31:21 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
#define T_MLX_H

#include "t_vec3.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		width;
	int		height;
	int		init;

	int		bpp;   // bits per pixel
	int		endian;
	int		w_len;
} t_mlx;

typedef	struct s_circle
{
	int x;
	int	y;
	int	z;
	float radius;
	int	init;
	int color;
}				t_circle;

typedef struct s_sphere
{
	t_vec3	origin;
	double rayon;
}				t_sphere;


typedef struct s_main
{
	t_circle *circle;
	int		nb;
}				t_main;


# define KEY_ESC 53 //ESCAPE
# define KEY_Q 12 // Q

#endif