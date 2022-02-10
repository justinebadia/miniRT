/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:14 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 15:26:13 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_3d.h"

// retourne un nouveau vecteur (x;y;z)
t_vec3	new_vector(double x, double y, double z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

// retourne un nouveau vecteur résultant de l'addition
t_vec3	new_vec_add(t_vec3 u, t_vec3 v)
{
	t_vec3	resultante;

	resultante.x = u.x + v.x;
	resultante.y = u.y + v.y;
	resultante.z = u.z + v.z;
	return (resultante);
}

// retourne un nouveau vecteur résultant de la soustraction.
// Utile par exemple pour calculer le Point d'intersection sur 
// une sphère (x;y;z) moins le Centre du cercle (x;y;z)
t_vec3	new_vec_substract(t_vec3 u, t_vec3 v)
{
	t_vec3	resultante;

	resultante.x = u.x - v.x;
	resultante.y = u.y - v.y;
	resultante.z = u.z - v.z;
	return (resultante);
}

//  retourne un nouveau vecteur résultant d'un vecteur multiplié par un scalaire
//  en ses composantes (x;y;z)
t_vec3	new_vec_multiply(t_vec3 u, double scalar)
{
	t_vec3	resultante;

	resultante.x = u.x * scalar;
	resultante.y = u.y * scalar;
	resultante.z = u.z * scalar;
	return (resultante);
}

// retourne un nouveau vecteur résultant du produit croisé des vecteurs u et v.
t_vec3	new_vec_crossproduct(t_vec3 u, t_vec3 v)
{
	t_vec3	resultante;

	resultante.x = (u.y * v.z) - (u.z * v.y);
	resultante.y = (u.z * v.x) - (u.x * v.z);
	resultante.z = (u.x * v.y) - (u.y * v.x);
	return (resultante);
}
