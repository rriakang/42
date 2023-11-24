/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:28:10 by rkang             #+#    #+#             */
/*   Updated: 2022/09/04 09:35:35 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s1 < *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:32:03 by rkang             #+#    #+#             */
/*   Updated: 2022/09/04 09:35:10 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s1 < *s2)
			return (*s1 - *s2);
		else
		{
				s1++;
				s2++;
				n--;
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:00:53 by rkang             #+#    #+#             */
/*   Updated: 2022/09/04 09:40:30 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strle(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_count;
	int	src_count;
	int	i;

	i = 0;
	dest_count = ft_strle(dest);
	src_count = ft_strle(src) - 1;
	while (i <= src_count)
	{
		dest[dest_count] = src[i];
		dest_count++;
		i++;
	}
	dest[dest_count] = '\0';
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:30:01 by rkang             #+#    #+#             */
/*   Updated: 2022/09/03 22:30:46 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int				dest_count;
	unsigned int				src_count;
	unsigned int				i;

	i = 0;
	src_count = ft_strlen(src);
	dest_count = ft_strlen(dest);
	while (i <= src_count && nb > 0)
	{
		dest[dest_count] = src[i];
		dest_count++;
		i++;
		nb--;
	}
	dest[dest_count] = '\0';
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:54:09 by rkang             #+#    #+#             */
/*   Updated: 2022/09/03 12:17:21 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	ft_strln(char *arr)
{
	int	count;

	count = 0;
	while (arr[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strstr(char	*str, char *to_find)
{
	int	j;

	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		if (*str == to_find[0])
		{
			while (j < ft_strln(to_find))
			{
				if (str[j] != to_find[j])
				{
					j = 0;
					break ;
				}
				j++;
			}
		}
		if (j == ft_strln(to_find))
			return (str);
	str++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:01:33 by rkang             #+#    #+#             */
/*   Updated: 2022/09/05 12:41:43 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_stlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		++i;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int				dest_count;
	unsigned int				src_count;
	unsigned int				i;
	unsigned int				sum;

	i = 0;
	dest_count = ft_stlen(dest);
	src_count = ft_stlen(src);
	sum = dest_count + src_count;
	if (dest_count >= size || size == 0)
		return (src_count + size);
	while (src[i] && i < size - dest_count - 1)
	{
		dest[dest_count + i] = src[i];
		i++;
	}
	dest[dest_count + i] = '\0';
	return (sum);
}