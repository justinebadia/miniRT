/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:34:02 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/14 09:01:47 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_3d.h"

// reçoit le pointeur du vecteur v et modifie ses composantes (x;y;z) 
// afin de le normaliser ainsi simplifier les prochains calculs
t_vec3	mod_vec_normalize(t_vec3 v)
{
	double		grandeur;

	grandeur = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= grandeur;
	v.y /= grandeur;
	v.z /= grandeur;

	return (v);
}

// retourne la grandeur/longueur d'un vecteur
double	get_vector_squared(t_vec3 v)
{
	double	grandeur;

	grandeur = (v.x * v.x + v.y * v.y + v.z * v.z);
	return (grandeur);
}

double	get_vector_length(t_vec3 v)
{
	double	grandeur;

	grandeur = (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	return (grandeur);
}

// retourne le produit croisé de deux vecteurs qui est une 
// distance/nombre par rapport au point d'origine d'un vecteur 
double	get_dot_product(t_vec3 u, t_vec3 v)
{
	double	distance;

	distance = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return (distance);
}