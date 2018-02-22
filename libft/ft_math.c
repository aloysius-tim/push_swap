/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:28:12 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:19:05 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

double		ft_ceil(double x)
{
	if (x < 0)
		return ((int)x);
	return (((int)x) + 1);
}

double		ft_floor(double x)
{
	if (x > 0)
		return ((int)x);
	return (((int)x) - 1);
}