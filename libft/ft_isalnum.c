/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:44:49 by mannouao          #+#    #+#             */
/*   Updated: 2021/11/11 18:29:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x >= 'A' && x <= 'Z' )
		|| (x >= 'a' && x <= 'z')
		|| (x >= '0' && x <= '9'))
		return (1);
	else
		return (0);
}
