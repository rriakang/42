/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:25:57 by seonghle          #+#    #+#             */
/*   Updated: 2022/08/27 17:33:52 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c); // 변수 선언

void	print_char(int x, int y, int i, int j)
{
	if (i == 0 && j == 0) 
		ft_putchar('o');
	else if (i == 0 && j == x - 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else if (i == y - 1 && j == 0)
		ft_putchar('o');
	else if (i == y - 1 && j == x - 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else if ((i == 0 || i == y - 1) && j != 0 && j != x - 1)
		ft_putchar('-');
	else if (i != 0 && i != y - 1 && j == 0)
		ft_putchar('|');
	else if (i != 0 && i != y - 1 && j == x - 1)
	{
		ft_putchar('|');
		ft_putchar('\n');
	}
	else
		ft_putchar(' ');
}

void	print_x_equal_1(int y, int i)
{
	if (i == 0 || i == y - 1)
		ft_putchar('o');
	else
		ft_putchar('|');
	ft_putchar('\n');
}

void	print_y_equal_1(int x, int j)
{
	if (j == 0)
		ft_putchar('o');
	else if (j == x - 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else
		ft_putchar('-');
}

void	rush(int x, int y) 
{
	int		i; //가로 설정 
	int		j; //세로 설정

	i = 0; //i 변수 초기화
	while (i < y) // main의 가로 입력값이 만약 i 보다 작다면 멈춰라 그전까진 계속 돌려라
	{
		j = 0;  // j 변수 초기화
		while (j < x) // main의 세로 입력값이 만약 j 보다 작다면 멈춰라 그전까진 계속 돌려라
		{
			if (x == 1 && y == 1) // 만약 가로 입력값이 1이고 세로 입력값이 1 이면 o를 하나만 출력
	{
				ft_putchar('o');
				ft_putchar('\n');
			}
			else if (x == 1) // 만약  가로입력값이 1이라면 세로입력값과 가로값을 넘겨주기
				print_x_equal_1(y, i);
			else if (y == 1) // 만약 세로 입력값이 1이라면 가로 입력값과 세로값 넘겨주기 

//여기서 세로입력값을 넣어주지 않는 이유는 세로입력값이 변해서 대조하기 편하기 때문이다.
				print_y_equal_1(x, j);
				else //나머지
				print_char(x, y, i, j);
			j++;
		}
		i++;
	}
}