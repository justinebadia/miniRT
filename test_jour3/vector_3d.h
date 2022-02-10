/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:30:59 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 15:35:09 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_3D_H
# define VECTOR_3D_H

# include <math.h>
# include "t_vec3.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vec3	new_vector(double x, double y, double z);
t_vec3	new_vec_add(t_vec3 u, t_vec3 v);
t_vec3	new_vec_substract(t_vec3 u, t_vec3 v);
t_vec3	new_vec_multiply(t_vec3 u, double scalar);
t_vec3	new_vec_crossproduct(t_vec3 u, t_vec3 v);
void		mod_vec_normalize(t_vec3 v);
double		get_vector_length(t_vec3 v);
double		get_dot_product(t_vec3 u, t_vec3 v);
double	get_vector_squared(t_vec3 v);


#endif