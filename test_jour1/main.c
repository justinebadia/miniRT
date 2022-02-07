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

int main(void)
{
	t_mlx mlx;


	mlx.width = 1920;
	mlx.height = 1080;
	mlx.mlx = mlx_init();
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.adr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.w_len, &mlx.endian);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "TEST MINILIBX");
	hook_collection(&mlx);
	mlx_loop(mlx.mlx);
}
