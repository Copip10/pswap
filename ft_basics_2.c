/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 10:40:49 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 17:33:41 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_putdouble(double n, int fd)
{
	int	digit;

	digit = n * 10000 + 0.0000001;
	ft_putnbr(digit / 100, fd);
	write(fd, ".", 1);
	if (digit % 100 < 10)
		write(fd, "0", 1);
	ft_putnbr(digit % 100, fd);
	write(fd, "%", 1);
}
