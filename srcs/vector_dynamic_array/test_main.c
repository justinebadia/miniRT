/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:22:06 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/09 14:22:18 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_array.h"

int	main(void)
{
	t_vector	v;

	vector_init_array(&v);
	vector_add_back_element(&v, "1. Hello");
	vector_add_back_element(&v, "2. World");
	vector_add_back_element(&v, "3. The End");
	printf("%s\n", (char *) v.elements[0]);
	printf("%s\n", (char *) v.elements[1]);
	printf("%s\n", (char *) v.elements[2]);
	vector_delete_element(&v, 0);
	printf("%s\n", (char *) v.elements[0]);
	printf("%s\n", (char *) v.elements[1]);
	printf("%s\n", (char *) v.elements[2]);
	vector_replace_element(&v, "Bonjour", 0);
	vector_replace_element(&v, "Bye Bye", 1);
	return (0);
}
