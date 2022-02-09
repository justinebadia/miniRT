/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:04:58 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 14:21:56 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_array.h"

void	vector_free_elements(t_vector *v)
{
	free(v->elements);
	v->elements = NULL;
}
