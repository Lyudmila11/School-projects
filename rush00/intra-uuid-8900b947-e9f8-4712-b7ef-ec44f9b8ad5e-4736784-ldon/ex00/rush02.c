/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:08:44 by ldon              #+#    #+#             */
/*   Updated: 2023/03/05 18:59:54 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	gs_cool(char letter1, char letter2, char letter3, int col)
{
	int	c_col;

	c_col = 1;
	while (c_col <= col)
	{
		if (c_col == 1)
		{
			ft_putchar(letter1);
		}
		else if (c_col == col)
		{
			ft_putchar(letter2);
		}
		else
		{
			ft_putchar(letter3);
		}
		c_col++;
	}
}

void	rush(int x, int y)
{
	int	c_row;

	c_row = 1;
	while (c_row <= y)
	{	
		if (c_row == 1)
		{
			gs_cool('A', 'A', 'B', x);
		}
		else if (c_row == y)
		{
			gs_cool('C', 'C', 'B', x);
		}
		else
		{
			gs_cool('B', 'B', ' ', x);
		}
		ft_putchar('\n');
		c_row ++;
	}
}
