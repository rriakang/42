/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:05:04 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 21:03:52 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*arr;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:09:59 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 19:44:19 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_change1(long long min, long long max)
{
	int	*arr;
	int	i;
	int	len;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	arr = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int	*ft_range(int min, int max)
{
	int	*arr;

	arr = ft_change1(min, max);
	return (arr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:47:33 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 17:11:07 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_change(int **range, long long min, long long max)
{
	int	i;
	int	len;

	i = 0;
	*range = 0;
	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(len * sizeof(int));
	if (!(*range))
		return (-1);
	while (i < len)
	{
		range[0][i] = min + i;
		i++;
	}
	return (len);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	return (ft_change(range, min, max));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:34:54 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 21:13:37 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		i++;
	}
	return (i);
}

int	malloc_size_cal(int size, char **strs, char *sep)
{
	int	strs_len;
	int	sep_len;
	int	i;

	strs_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		strs_len += ft_strlen(strs[i]);
		strs_len += sep_len;
		++i;
	}
	return (strs_len + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_count;
	int	src_count;
	int	i;

	i = 0;
	dest_count = ft_strlen(dest);
	src_count = ft_strlen(src);
	while (i < src_count)
	{
		dest[dest_count] = src[i];
		dest_count++;
		i++;
	}
	dest[dest_count] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	total_length = malloc_size_cal(size, strs, sep);
	str = (char *)malloc(total_length * sizeof(char));
	i = 0;
	if (!str)
		return (0);
	*str = 0;
	i = 0;
	while (strs[i] && i < size)
	{
		if (i > 0)
			str = ft_strcat(str, sep);
		str = ft_strcat(str, strs[i]);
		++i;
	}
	return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:01:00 by rkang             #+#    #+#             */
/*   Updated: 2022/09/14 10:54:31 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	base_check(char *base);
int	double_check(char *base);

long long	ft_base_to_len(long long nbr, long long base_len)
{
	long long	size;

	size = 0;
	while (nbr != 0)
	{
		nbr = nbr / base_len;
		size++;
	}
	return (size);
}

char	*ft_malloc(long long nbr, char *base,
		long long base_num, long long malloc_len)
{
	int			flag;
	char		*arr;

	flag = 0;
	if (nbr < 0)
	{
		flag = 1;
		malloc_len = malloc_len + 1;
		nbr = -nbr;
	}
	arr = (char *)malloc((malloc_len + 1) * sizeof(char));
	if (!arr)
		return (0);
	arr[malloc_len] = '\0';
	while (--malloc_len >= 0)
	{
		if (flag == 1 && malloc_len == 0)
			arr[0] = '-';
		else
		{
			arr[malloc_len] = base[nbr % base_num];
			nbr = nbr / base_num;
		}
	}
	return (arr);
}

char	*ft_is_num_zero(char *base_to)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * 2);
	p[0] = base_to[0];
	p[1] = '\0';
	return (p);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	long long	base_count;
	long long	malloc_len;

	base_count = 0;
	if (nbr == 0)
		return (0);
	while (base_from[base_count])
		base_count++;
	if (double_check(base_from) == 0
		|| base_check(base_from) == 0 || base_count < 2)
		return (0);
	base_count = 0;
	while (base_to[base_count])
		base_count++;
	if (base_count < 2 || base_check(base_to) == 0
		|| double_check(base_to) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	if (num == 0)
		return (ft_is_num_zero(base_to));
	else
		malloc_len = ft_base_to_len(num, base_count);
	return (ft_malloc(num, base_to, base_count, malloc_len));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:01:17 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 11:42:18 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	double_check(char *base)
{
	char	arr[256];
	int		i;
	int		temp;

	i = 0;
	while (i < 256)
	{
		arr[i] = 0;
		i++;
	}
	while (*base)
	{
		temp = *base;
		if (arr[temp] == 1)
			return (0);
		else
			arr[temp] = 1;
		base++;
	}
	return (1);
}

int	base_check(char *base)
{
	while (*base)
	{
		if ((*base >= 9 && *base <= 13) || *base == 32)
			return (0);
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

long long	check_string(char *str, char *base, int base_len)
{
	long	result;
	int		j;
	int		flag;

	result = 0;
	while (*str)
	{
		flag = 0;
		j = 0;
		while (base[j])
		{
			if (base[j] == *str)
			{
				result = result * base_len + j;
				flag = 1;
			}
			j++;
		}
		str++;
		if (flag == 0)
			return (result);
	}
	return (result);
}

char	*check_error2(char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
	while (*str == '+' || *str == '-' )
	{
		if (*str == '-')
		{
			(*sign)++;
		}
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int			base_count;
	long long	result;
	int			i;
	int			sign;

	sign = 0;
	base_count = 0;
	i = 0;
	while (base[i])
	{
		base_count++;
		i++;
	}
	if (double_check(base) == 0
		|| base_check(base) == 0 || base_count < 2)
		return (0);
	str = check_error2(str, &sign);
	result = check_string(str, base, base_count);
	if (sign % 2 == 1)
		result = -result;
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:58:28 by rkang             #+#    #+#             */
/*   Updated: 2022/09/13 22:53:19 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	find_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *str, char *charset, int i)
{
	int		cnt;
	char	*dest;

	cnt = 0;
	while (str[i] && !(find_charset(str[i], charset)))
	{
		i++;
		cnt++;
	}
	dest = (char *)malloc(sizeof(char) *(cnt + 1));
	i -= cnt;
	cnt = 0;
	while (str[i] && !(find_charset(str[i], charset)))
		dest[cnt++] = str[i++];
	dest[cnt] = '\0';
	return (dest);
}

int	charset_check(char *str, char *charset)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && find_charset(str[i], charset))
		i++;
		if (str[i] && !(find_charset(str[i], charset)))
		{
			while (str[i] && !(find_charset(str[i], charset)))
				i++;
			cnt++;
		}
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	word_count;
	int		i;
	int		j;

	word_count = charset_check(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && find_charset(str[i], charset))
			i++;
		if (str[i] && !(find_charset(str[i], charset)))
		{
			result[j++] = ft_strcpy(str, charset, i);
			while (str[i] && !(find_charset(str[i], charset)))
			i++;
		}
	}
	result[j] = 0;
	return (result);
}