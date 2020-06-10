/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:33:03 by lchapren          #+#    #+#             */
/*   Updated: 2020/06/10 11:39:51 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*image;
	int		*image_data;
	int		rendered;
}				t_mlx;

#endif
