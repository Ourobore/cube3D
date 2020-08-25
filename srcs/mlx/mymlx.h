/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:46 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 12:54:41 by lchapren         ###   ########.fr       */
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
# define STRUCTNOTIFYMASK 131072

# define FOWARD 13/*119*/
# define BACKWARD 1/*115*/
# define LEFT 0/*97*/
# define RIGHT 2/*100*/
# define SHIFT 257/*65505*/
# define SPACE 49
# define ESC 53/*65307*/
# define T 17
# define TURNLEFT 123/*65361*/
# define TURNRIGHT 124/*65363*/

# define PI 3.14159265359

/*
** Initialization functions
*/
t_mlx		start_mlx(t_map map);
t_player	init_player(t_player player);
t_player	initial_player_position(t_map map);
t_player	get_player(char c, int i, int j);
int			destroy_window(t_data *data);
void		clean_exit(t_data *data, int exit_code);
void		clean_map(t_data *data);
void		clean_texture(t_data *data);
void		free_double_array(char **double_array);

/*
*** Control functions
*/
int			key_press_hook(int key, t_data *data);
int			key_release_hook(int key, t_data *data);
void		bonus_key_press(int key, t_data *data);
void		bonus_key_release(int key, t_data *data);
int			mouse_hook(int key, t_mlx *param);
int			player_control(t_data *data);
void		move_player(t_player *player, t_map map, float angle);
void		rotate_player(t_player *player, float angle);
float		*rotate_direction(float direction_x, float direction_y, \
				float angle);

/*
** Raycasting functions
*/
t_data		new_image(t_data data);

void		raycasting(t_data *data, t_player *player, t_ray *ray, t_map map);

t_player	get_plane(t_player player, char spawn_dir);
void		get_steps(t_player *player, t_ray *ray);
double		get_distance(t_ray ray, t_player player);
void		get_sprite(t_ray *ray, t_player player, t_map map);
void		get_wall(t_data data, t_ray *ray, t_map map, t_player player);
void		select_texture(t_ray *ray, t_player player);
void		textured_loop(t_mlx *mlx, t_ray ray, t_player player, t_map map);
void		draw_untextured(t_mlx *mlx, t_ray ray, t_player player, t_map map);
void		draw_textured(t_mlx *mlx, t_ray ray, t_player player, t_map map);
void		get_textures(t_data *data, t_ray *ray, t_map map);
void		texture_error(t_data *data, t_ray *ray);
int			*get_img_addr(void *ptr);
void		get_sprite_list(t_ray *ray, t_player player, t_map map);
int			get_sprite_index(t_sp *list, t_map map, int map_x, int map_y);
int			get_farest_visible_sprite(t_sp *list, t_map map);
void		get_sprite_position(t_ray *ray, t_map map, t_player player, int i);
void		draw_sprite(t_mlx *mlx, t_ray *ray, t_player player, t_map map);

#endif
