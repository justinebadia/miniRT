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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int	ft_print_circle(t_main *main)
{
	int	i = 0;
	int	j;
	int sq = 0;
	int k = 0;
	int back = 0;
	t_mlx *mlx;

	mlx = get_mlx();
	while (k < main->nb)
	{
		i = 0;
		while (i < mlx->height)
		{
			j = 0;
			while (j < mlx->width)
			{
				sq = sqrtf(powf(i - main->circle[k].y, 2.0) + powf(j - main->circle[k].x, 2.0));
				if (sq < main->circle[k].radius)
				{
					if (k == 0)
						my_mlx_pixel_put(mlx, i, j, main->circle[0].color); // colore le rond en bleu
					if (k == 1)
						my_mlx_pixel_put(mlx, i, j, main->circle[1].color); // colore le rond en bleu

				}
				else if (back == 0)
					my_mlx_pixel_put(mlx, i, j, 0xff00ff); // colore le fonds en rose
				j++;
			}
			i++;
		}
		k++;
		back = 1;
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
	t_circle *circle = calloc(1, sizeof(t_circle));

	main = calloc(1, sizeof(t_main));
	//init_circle(circle);
	init_main(main);
	mlx = get_mlx();
	hook_collection(mlx);
	mlx_loop_hook(mlx->mlx, ft_print_circle, main);
	mlx_loop(mlx->mlx);

}
