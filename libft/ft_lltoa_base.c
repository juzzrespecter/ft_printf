/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:43:43 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/23 13:55:19 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_alen(long int i, int bsize)
{
	int isize;

	isize = 0;
	if (i < 0)
	{
		isize++;
		i *= -1;
	}
	while (i)
	{
		i /= bsize;
		isize++;
	}
	return (isize);
}

static int	fillintheblanks(long long int i, int a_pos, int b_len)
{
	int	count;

	if (i < 0)
		return ('-');
	count = 0;
	while (count < a_pos)
	{
		count++;
		i /= b_len;
	}
	return (i % b_len);
}

static int	check_base(char *base)
{
	int count;

	count = 0;
	if (!base || ft_strlen(base) == 1)
		return (0);
	while (base[count])
	{
		if (ft_strchr(base + count + 1, base[count]))
			return (0);
		count++;
	}
	return (1);
}

char		*ft_lltoa_base(long long int i, char *base)
{
	char	*a;
	int		a_len;
	int		count;
	int		b_len;

	if (!check_base(base))
		return (NULL);
	b_len = ft_strlen(base);
	a_len = get_alen(i, b_len);
	if (!(a = malloc(sizeof(char) * (a_len + 1))))
		return (NULL);
	count = 0;
	if (i < 0)
	{
		a[a_len - 1] = '-';
		i *= -1;
	}
	while (i)
	{
		a[count] = base[fillintheblanks(i, count, b_len)];
		i /= b_len;
		count++;
	}
	a[a_len] = 0;
	return (a);
}
