/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:31:31 by rkang             #+#    #+#             */
/*   Updated: 2022/09/03 20:35:50 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count ++;
	}
	return (count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:37:03 by rkang             #+#    #+#             */
/*   Updated: 2022/09/03 20:39:58 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:57:15 by rkang             #+#    #+#             */
/*   Updated: 2022/09/04 15:34:03 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_number(int b, char *num)
{
	int	a;

	a = 0;
	while (a <= b)
	{
		num[a] = num[a] + '0';
		write(1, &num[a], 1);
		a++;
	}
}

int	number_count(int c)
{
	int	count;

	count = 0;
	while (c > 0)
	{
		while (c != 0)
		{
			c = c / 10;
			count++;
		}
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	int		i;
	int		n;
	char	num[12];

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	i = number_count(nb) - 1;
	n = number_count(nb) - 1;
	while (i >= 0)
	{
		num[i] = nb % 10;
		nb = nb / 10;
		i--;
	}
	print_number (n, num);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:12:33 by rkang             #+#    #+#             */
/*   Updated: 2022/09/10 13:41:49 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen1(char *str)
{
	int	count;

	count = 1;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*check_error(char *str, int *sign)
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

int	ft_atoi(char *str)
{
	int			str_count;
	int			sign;
	long long	result;

	result = 0;
	sign = 0;
	str_count = ft_strlen1(str);
	str = check_error(str, &sign);
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign % 2 == 1)
		result = -result;
	return ((int)(result));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:38:09 by rkang             #+#    #+#             */
/*   Updated: 2022/09/10 16:19:30 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	double_check1(char *base)
{
	char	arr[255];
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = i + 1;
	while (i <= 255)
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

long long	ft_strlen2(char *str)
{
	long long	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	check_error1(char *base)
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

void	ft_putnbr(long long nbr, char *base, long long base_num)
{
	if (nbr == 0)
		return ;
	// ft_putnbr(nbr / base_num, base, base_num);
	write(1, &base[nbr % base_num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	base_num;
	long long	num;

	num = (long long)nbr;
	base_num = ft_strlen2(base);
	if (base_num < 2 || check_error1(base) == 0
		|| double_check1(base) == 0)
		return ;
	if (num == 0)
		write(1, &base[0], 1);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	// ft_putnbr(num, base, base_num);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkang <rkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:38:26 by rkang             #+#    #+#             */
/*   Updated: 2022/09/10 16:21:04 by rkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	double_check(char *base)
{
	char	arr[255];
	int		i;
	int		temp;

	i = 0;
	while (i <= 255)
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