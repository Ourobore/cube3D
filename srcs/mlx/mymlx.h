/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:46 by lchapren          #+#    #+#             */
/*   Updated: 2020/06/10 14:18:47 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include "../../cube3d.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 10
# define DESTROYNOTIFY 17
# define LEAVEWINDOWMASK 32

# define FOWARD 119
# define BACKWARD 115
# define LEFT 97
# define RIGHT 100
# define SHIFT 65505
# define ESC 65307
# define M 109
# define TURNLEFT 65361
# define TURNRIGHT 65363

# define PI 3.14159265359

/*
** Initialization functions
*/
t_mlx		start_mlx(t_map map);
t_data		main_mlx_loop(t_data data);
t_data		init_player(t_data data);
t_player	initial_player_position(char **map);
t_player	get_player(char c, int i, int j);
void		free_mlx(t_mlx window);

/*
*** Control functions
*/
int			key_press_hook(int key, t_data *data);
int			key_release_hook(int key, t_data *data);
int			raycasting_loop(t_data *data);
int			mouse_hook(int key, t_mlx *param);
void		player_control(t_data *data);
void		move_player(t_data *data, float angle);
void		rotate_player(t_data *data, float angle);
int			player_moved(t_data *data);
float		*rotate_direction(float direction_x, float direction_y, float angle);


/*
** Raycasting functions
*/
t_data	new_image(t_data data);
//t_data	raycasting(t_data data);
//float		get_distance(t_data *data, float *direction, int x, float angle);
float		vertical_wall(t_data *data, float *direction);
float		horizontal_wall(t_data *data, float *direction);

void raycasting(t_data *data);
void side_calculus(t_data *data, int column);
void wall_hit_calculus(t_data *data, int column);
void draw_wall(t_data *data, int side, int column);

/*
** Tests fumctions
*/

void	my_raycasting(t_data *data);
float	get_distance(t_data *data, float *ray_dir);
float	wall_hit(t_data *data, float distance, float side_x, float side_y);
void	draw_column(t_data data);
#endif
