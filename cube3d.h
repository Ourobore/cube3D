/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:39:44 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 10:42:36 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/*
*** Typedef struct .h files
*/
# include "srcs/map.h"
# include "srcs/window.h"
# include "srcs/player.h"
# include "srcs/ray.h"
# include "srcs/data.h"

/*
*** .h project files
*/
# include "./libft/libft.h"
# include "srcs/parsing/parsing.h"
# include "srcs/mlx/mymlx.h"

/*
** Standard libraries
*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"

# define NB_ELEMENTS 8
# define PLAYER_HEIGHT 2
# define FOV 60
# define TEXTURES 0
# define ROTATION_ANGLE 3
# define BASE_SPEED 1
# define SPRINT 3
# define BONUS 1



#endif
