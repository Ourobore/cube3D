/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:33:03 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 11:13:06 by lchapren         ###   ########.fr       */
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
}				t_mlx;

#endif
