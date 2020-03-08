/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:46 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/08 16:07:42 by lchapren         ###   ########.fr       */
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
	t_ray		ray;
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
t_data		move_player(t_data data, float angle);
float		*rotate_direction(float direction_x, float direction_y, float angle);

char		*fill_new_image(t_data data);

/*
** Raycasting functions
*/
t_data	new_image(t_data data);
//t_data	raycasting(t_data data);
float		get_distance(t_data *data, float *direction, int x, float angle);
float		vertical_wall(t_data *data, float *direction);
float		horizontal_wall(t_data *data, float *direction);
void	rendering(t_data data, float distance);

void raycasting(t_data data);
void side_calculus(t_data *data, int column);
void wall_hit_calculus(t_data *data, int column);
void draw_wall(t_data *data, int side, int column);



#endif
