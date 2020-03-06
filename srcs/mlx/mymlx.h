/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:46 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/06 11:57:03 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include "../../cube3d.h"

# define KEYPRESS 2
# define KEYPRESSMASK 1
# define DESTROYNOTIFY 17
# define LEAVEWINDOWMASK 32

# define PI 3.14159265359

typedef struct	s_data
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	int			bonus;
}				t_data;

/*
** Initialization functions
*/
t_mlx		start_mlx(t_map map);
t_data		main_mlx_loop(t_data data);
t_player	initial_player_position(char **map);
t_player	get_player(char c, int i, int j);
void		free_mlx(t_mlx window);

/*
*** Control functions
*/
int			key_hook(int key, t_data *data);
int			mouse_hook(int key, t_mlx *param);

char		*fill_new_image(t_data data);

/*
** Raycasting functiuns
*/
t_data	raycasting(t_data data);
float		get_distance(t_data data, float *direction, int x, float angle);
float		vertical_wall(t_data *data, float *direction);
float		horizontal_wall(t_data *data, float *direction);
float		*new_direction(t_data data, float direction_x, float direction_y, int angle);
void	rendering(t_data data, float distance);

#endif
