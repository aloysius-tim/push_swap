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

int 	ft_ceil(float nb)
{
	int integer;

	integer = (int)nb;
	if (nb == (float)integer)
		return (nb);
	else
		return (nb + 1);
}
