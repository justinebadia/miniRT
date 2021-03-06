/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:04:47 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 14:21:46 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_array.h"

void	vector_init_array(t_vector *v)
{
	v->elements = malloc(sizeof(void *) * VECTOR_INIT_CAPACITY);
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
}

void	vector_add_back_element(t_vector *v, void *new_element)
{
	if (v->capacity == v->total)
		vector_resize_capacity(v, v->capacity * 2);
	v->elements[v->total] = new_element;
	v->total++;
}

void	vector_replace_element(t_vector *v, void *new, size_t index)
{
	if (index >= 0 && index < v->total)
		v->elements[index] = new;
}

void	vector_delete_element(t_vector *v, size_t index)
{
	if (index < 0 || index >= v->total)
		return ;
	v->elements[index] = NULL;
	while (index < v->total - 1)
	{
		v->elements[index] = v->elements[index + 1];
		v->elements[index + 1] = NULL;
		index++;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize_capacity(v, v->capacity / 2);
}

void	vector_resize_capacity(t_vector *v, size_t new_capacity)
{
	void	**temp;

	temp = v->elements;
	vector_free_elements(v);
	v->elements = malloc(sizeof(void *) * new_capacity);
	v->elements = temp;
	v->capacity = new_capacity;
}
