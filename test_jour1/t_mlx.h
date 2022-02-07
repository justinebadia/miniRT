/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:56:38 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/07 16:12:23 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
#define T_MLX_H

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		width;
	int		height;

	int		bpp;   // bits per pixel
	int		endian;
	int		w_len;
} t_mlx;

# define KEY_ESC 53 //ESCAPE
# define KEY_Q 12 // Q

#endif