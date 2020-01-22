/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:43:43 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/20 12:09:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int ft_get_isize(long int i, int bsize)
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

static char *ft_rev_a(char *a)
{
	int a_len;
	int i;
	char aux;

	a_len = ft_strlen(a);
	i = 0;
	while (i < a_len / 2)
		{
			aux = a[i];
			a[i] = a[a_len - (i + 1)];
			a[a_len - (i + 1)] = aux;
			i++;
		}
	return (a);
}

static int ft_check_base(char *base)
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

char	*ft_lltoa_base(long long int i, char *base)
{
	char *a;
	int count;
	int b_len;
	int neg;

	neg = 0;
	if (!ft_check_base(base))
		return (NULL);
	b_len = ft_strlen(base);
	if (!(a = malloc(sizeof(char) * (ft_get_isize(i, b_len) + 1))))
		return (NULL);
	count = 0;
	if (i < 0)
		{
			neg = 1;
			i *= -1;
		}
	while (i)
		{
			a[count] = base[i % b_len];
			i /= b_len;
			count++;
		}
	if (neg)
		{
			a[count] = '-';
			count++;
		}
	a[count] = 0;
	ft_rev_a(a);
	return (a);
}