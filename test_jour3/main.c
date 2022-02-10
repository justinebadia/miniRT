/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:44:38 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/08 10:34:29 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl/mlx.h"
#include "t_vec3.h"
#include "t_mlx.h"
#include "vector_3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define M_PI 3.1415926535897932


t_vec3 P; // point P qui touche le cercle
t_vec3 N; // N vecteur de la normale

int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	click_close_window(void)
{
//	mlx_destroy_image(mlx, img);
//	mlx_destroy_window(mlx, win);
	printf("clicked the red (x)\n");
	exit(0);
}

void	hook_collection(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_event, mlx);

	// HOOK EVENT to close the window
	// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	mlx_hook(mlx->win, 17, 0, click_close_window, mlx);

}

void	init_circle(t_circle *circle)
{
	circle->radius = 100;
	circle->x = 600/2;
	circle->y = 600/2;
	circle->z = 0;
}

void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
    {
        dst = mlx->adr + (y * mlx->w_len + x * (mlx->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

t_mlx    *get_mlx(void)
{
    static t_mlx    mlx;

    if (mlx.init != 1)
    {
        mlx.mlx = mlx_init();
		mlx.width = 600;
		mlx.height = 600;
      	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
		mlx.adr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.w_len, &mlx.endian);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "TEST MINILIBX");
        mlx.init = 1;
    }
    return (&mlx);
}

// bool intersection(t_ray r, t_sphere s)
// {
// 	double a = 1;
// 	double b = 2*(get_dot_product(r.direction, new_vec_substract(r.origin, s.origin)));
// 	double c = get_vector_squared(new_vec_substract(r.origin, s.origin)) - (s.rayon * s.rayon);
// 	/* si le discriminant est plus petit que 0 alors il n'y a pas d'intersection
// 	Si le discriminant est plus grand que 0, il n'y a pas forcément d'intersection non plus,
// 	il se peut qu'elle soit derrière la caméra, donc il faut tester le signe de deux solutions:
// 		t2 et t2
// 	t2 est forcément plus loin que t2, donc si t2 est plus grand que 0, alors il y a une intersection
// 	puisque pour calculer t2, on fait -b + sqrt(delta), donc t2 est forcément plus grand que t2, 
// 	donc si t2 est plus grand que 0, il y a une intersection.*/
	
// 	double delta = b * b - 4*a*c; 

// 	if (delta < 0)
// 		return (false);
// 	double t2 = (-b - sqrt(delta)) / (2*a); 
// 	double t2 = (-b + sqrt(delta)) / (2*a);
// 	if (t2 > 0)
// 		return (true);
// 	return(false);
// }

int	solve_quadra(double a, double b, double c, double *t1, double *t2)
{
	double delta;
	double q;
	double buffer;

	delta = b * b - 4*a*c;
	if (delta < 0)
		return (0);
	else if (delta == 0)
	{
		*t1 = -0.5 * b / a;
		*t2 = -0.5 * b / a;
	}
	else
	{
		if (b > 0)
			q = -1 * (b + sqrt(delta)) / 2;
		else
		q = -1 * (b - sqrt(delta)) / 2;
		*t1 = q / a;
		*t2 = c / q;
	}
	if (*t1 > *t2)
	{
		buffer = *t1;
		*t1 = *t2;
		*t2 = buffer;
	}
	return (1);
}

int get_roots(double *t1, double *t2, t_ray r, t_sphere s)
{
	t_vec3	v;
	double a;
	double b;
	double c;

	v = new_vec_substract(r.origin, s.origin);
	a = get_dot_product(r.direction, r.direction);
	b = 2.0 * get_dot_product(r.direction, v);
	c = get_dot_product(v, v) - (s.rayon * s.rayon);
	if (solve_quadra(a, b, c, t1, t2) == 0)
		return (0);
	return (1);
}

int	intersect_sphere(t_ray r, t_sphere s, double *t)
{
	double t1;
	double t2;

	if (get_roots(&t1, &t2, r, s) == 0)
		return (0);
	if (t1 < 0)
	{
		t1 = t2;
		if (t1 < 0)
			return (0);
	}
	*t = t1;
	P = new_vec_add(new_vec_multiply(r.direction, *t), r.origin);
	N = new_vec_substract(P, s.origin);
	get_vector_squared(N);
	return (1);
}


int	ft_print_circle(t_main *main)
{
	int	i = 0;
	int	j;
	t_mlx *mlx;
	t_ray r;
	double fov = 60 * M_PI / 180;
	t_sphere sphere;
	double t = 0;
	t_vec3 light;
	double intensity = 10000;
	double intensity_pix;
	

	light.x = 0;
	light.y = 300;
	light.z = -40;

	r.origin.x = 600 /2;
	r.origin.y = 300;
	r.origin.z = 300;

	sphere.origin.x = 300;
	sphere.origin.y = 300;
	sphere.origin.z = -55;
	sphere.rayon = 50;

	mlx = get_mlx();
		while (i < mlx->height)
		{
			j = 0;
			while (j < mlx->width)
			{
				r.direction.x = j- mlx->width/2;
				r.direction.y = i - mlx->height /2;
				r.direction.z = -mlx->width / (2 * tan(fov / 2));
				new_vector(r.direction.x, r.direction.y, r.direction.z);
				mod_vec_normalize(r.direction);
				intensity_pix = 0;
				if (intersect_sphere(r, sphere, &t))
				{
					// revoir la normalisation du vector
					intensity_pix = intensity * get_dot_product(light, N) / get_vector_squared(new_vec_substract(light, P));
					my_mlx_pixel_put(mlx, i, j, intensity_pix); // colore le rond en orange

				}
				else
					my_mlx_pixel_put(mlx, i, j, 0xff00ff); // colore le fonds en rose

				j++;
			}
			i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

void	init_main(t_main *main)
{

	main->nb = 2;
	main->circle = calloc(main->nb, sizeof(t_circle));
	main->circle[0].radius = 100;
	main->circle[0].x = 50;
	main->circle[0].y = 50;
	main->circle[0].color = 255;
	main->circle[1].radius = 150;
	main->circle[1].x = 600/2;
	main->circle[1].y = 600/2;
	main->circle[1].color = 14651212;

}

int main(void)
{
	t_mlx *mlx;
	t_main *main;

	main = calloc(1, sizeof(t_main));
	//init_circle(circle);
	init_main(main);
	mlx = get_mlx();
	hook_collection(mlx);
	mlx_loop_hook(mlx->mlx, ft_print_circle, main);
	mlx_loop(mlx->mlx);

}
