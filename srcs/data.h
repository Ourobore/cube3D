/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:54:05 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/19 14:25:09 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct  s_data
{
        t_mlx           mlx;
        t_map           map;
        t_player        player;
        t_ray           ray;
        int                     bonus;
}                               t_data;

#endif
