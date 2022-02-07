/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:44:38 by tshimoda          #+#    #+#             */
/*   Updated: 2022/02/07 16:10:12 by tshimoda         ###   ########.fr       */
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
	circle->x = 1080/2;
	circle->y = 1920/2;
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
		mlx.width = 1920;
		mlx.height = 1080;
      	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
		mlx.adr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.w_len, &mlx.endian);
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "TEST MINILIBX");
        mlx.init = 1;
    }
    return (&mlx);
}

int	ft_print_circle(t_circle *circle)
{
	int	i = 0;
	int	j;
	int sq = 0;
	t_mlx *mlx;

	mlx = get_mlx();
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			sq = sqrtf(powf(i - circle->y, 2.0) + powf(j - circle->x, 2.0));
			if (sq < circle->radius)
				my_mlx_pixel_put(mlx, i, j, 0x0000ff);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

int main(void)
{
	t_mlx *mlx;
	t_circle *circle = calloc(1, sizeof(t_circle));

	init_circle(circle);
	mlx = get_mlx();
	hook_collection(mlx);
	mlx_loop_hook(mlx->mlx, ft_print_circle, circle);
	mlx_loop(mlx->mlx);

}
