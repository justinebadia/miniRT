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

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	new_vector(double x, double y, double z);
t_vector	new_vec_add(t_vector u, t_vector v);
t_vector	new_vec_substract(t_vector u, t_vector v);
t_vector	new_vec_multiply(t_vector u, double scalar);
t_vector	vector_normalize(t_vector u);
t_vector	new_vec_crossproduct(t_vector u, t_vector v);
void		mod_vec_normalize(t_vector *v);
double		get_vector_length(t_vector v);
double		get_dot_product(t_vector u, t_vector v);

#endif