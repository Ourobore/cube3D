/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:46 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/18 14:48:38 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H

# include "../../cube3d.h"

# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define LEAVEWINDOWMASK (1L<<5)

/*
**Initialization functions
*/
t_mlx	start_mlx(t_map map);
t_mlx	main_mlx_loop(t_mlx window, t_map map);
void	free_mlx(t_mlx window);

/*
***Control functions
*/
int		key_hook(int key, t_mlx *param);
int		mouse_hook(int key, t_mlx *param);

char *fill_new_image(t_mlx window, t_map map);

#endif