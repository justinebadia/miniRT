/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:34:02 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 15:26:52 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_3d.h"

// reçoit le pointeur du vecteur v et modifie ses composantes (x;y;z) 
// afin de le normaliser ainsi simplifier les prochains calculs
void	mod_vec_normalize(t_vector *v)
{
	double		grandeur;

	grandeur = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x /= grandeur;
	v->y /= grandeur;
	v->z /= grandeur;
}

// retourne la grandeur/longueur d'un vecteur
double	get_vector_length(t_vector v)
{
	double	grandeur;

	grandeur = (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	return (grandeur);
}

// retourne le produit croisé de deux vecteurs qui est une 
// distance/nombre par rapport au point d'origine d'un vecteur 
double	get_dot_product(t_vector u, t_vector v)
{
	double	distance;

	distance = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return (distance);
}
