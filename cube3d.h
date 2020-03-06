/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:39:44 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/06 11:27:39 by lchapren         ###   ########.fr       */
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

/*
*** .h project files
*/
# include "./libft/libft.h"
# include "srcs/parsing/parsing.h"
# include "srcs/mlx/mymlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>

# define NB_ELEMENTS 8
# define FOV 90
# define BONUS 0


#endif
