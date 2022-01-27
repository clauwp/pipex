/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:39:59 by clau              #+#    #+#             */
/*   Updated: 2021/09/26 22:12:52 by clau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static char	*ft_strnew(char *start, char *end);
static int	ft_strs_count(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**retarray;
	char	*start;
	char	*end;
	int		len;

	len = ft_strs_count(s, c);
	retarray = (char **)malloc(sizeof(char *) * (len + 1));
	if (retarray == NULL)
		return (NULL);
	len = 0;
	while (*s != 0)
	{	
		start = (char *) s;
		while (*s != c && *s)
			s++;
		end = (char *) s;
		if (start != end)
			retarray[len++] = ft_strnew(start, end);
		if (*end == 0)
			break ;
		s++;
	}
	retarray[len] = NULL;
	return (retarray);
}

static int	ft_strs_count(const char *s, char c)
{
	char	*start;
	char	*end;
	int		count;

	count = 0;
	while (*s)
	{
		start = (char *) s;
		while (*s != c && *s)
			s++;
		end = (char *) s;
		if (start != end)
			count++;
		if (*end == 0)
			break ;
		s++;
	}
	return (count);
}

static char	*ft_strnew(char *start, char *end)
{
	char	*retstr;
	int		len;

	len = 0;
	while (&start[len] != end)
		len++;
	retstr = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	if (retstr != NULL)
	{
		while (start != end)
		{
			retstr[len++] = *start++;
		}
		retstr[len] = 0;
		return (retstr);
	}
	else
		return (NULL);
}
