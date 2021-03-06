/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:41:23 by gsaynac           #+#    #+#             */
/*   Updated: 2015/01/26 19:41:00 by gsaynac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putnbr_fd(int n, int fd)
{
	char			nb[11];
	unsigned int	i;

	i = 11;
	nb[0] = (n < 0) ? '-' : '+';
	if (n <= 0)
	{
		nb[--i] = '0' - (n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		nb[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (nb[0] == '-')
		nb[--i] = '-';
	write(fd, nb + i, 11 - i);
}
