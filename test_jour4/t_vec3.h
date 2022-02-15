/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:52:44 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/14 09:09:55 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC3_H
#define T_VEC3_H

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;


typedef struct s_ray
{
	t_vec3 origin;
	t_vec3 direction;	
}				t_ray;

#endif