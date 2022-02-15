/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:30:59 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/14 09:11:58 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_3D_H
# define VECTOR_3D_H

# include <math.h>
# include "t_vec3.h"

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

// typedef struct s_rgb
// {
// 	int	r;
// 	int	g;
// 	int	b;
// }	t_vec3;

t_vec3	new_vector(double x, double y, double z);
t_vec3	new_vec_add(t_vec3 u, t_vec3 v);
t_vec3	new_vec_substract(t_vec3 u, t_vec3 v);
t_vec3	new_vec_multiply(t_vec3 u, double scalar);
t_vec3	new_vec_crossproduct(t_vec3 u, t_vec3 v);
t_vec3		mod_vec_normalize(t_vec3 v);
double		get_vector_length(t_vec3 v);
double		get_dot_product(t_vec3 u, t_vec3 v);
double	get_vector_squared(t_vec3 v);
t_vec3 multiply_2_vec(t_vec3 u, t_vec3 v);


#endif