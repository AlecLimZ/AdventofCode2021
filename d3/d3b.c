/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d3b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:42:56 by leng-chu          #+#    #+#             */
/*   Updated: 2022/05/22 21:10:11 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_tablen(char **v)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (v[++i])
		c++;
	return (c);
}

void	ft_printf(char	**str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		printf("%d: %s\n", i, str[i]);
}

void	ft_get1(char **box, int j)
{
	char	**tmp;
	int		t;
	int		i;

	i = -1;
	tmp = box;
	while (box[++i])
	{
		if (box[i][j] == '0')
		{
			t = i;
			while (tmp[++t])
				box[t - 1] = tmp[t];
			box[t - 1] = NULL;
			i--;
		}
	}
}

void	ft_get0(char **box, int j)
{
	char	**tmp;
	int		t;
	int		i;

	i = -1;
	tmp = box;
	while (box[++i])
	{
		if (box[i][j] == '1')
		{
			t = i;
			while (tmp[++t])
				box[t - 1] = tmp[t];
			box[t - 1] = NULL;
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		one;
	int		zero;
	char	**oxy;
	char	**co3;
	int		flag;
	int		which;
	int		len;

	flag = 1;
	which = 3;
	if (argc <= 1)
		return (0);
	oxy = (char **)malloc(sizeof(char) * ft_tablen(argv) + 1);
	co3 = NULL;
	i = 0;
	k = 0;
	while (argv[++i])
	{
		len = strlen(argv[i]);
		oxy[k] = malloc(sizeof(char) * (len + 1));
		oxy[k] = argv[i];
		oxy[k][len] = '\0';
		k++;
	}
	oxy[k] = NULL;
	j = 0;
	while (flag)
	{
		i = -1;
		one = 0;
		zero = 0;
		while (oxy[++i])
		{
			if (oxy[i][j] == '1')
				one++;
			if (oxy[i][j] == '0')
				zero++;
		}
		if (one >= zero)
			ft_get1(oxy, j);
		else
			ft_get0(oxy, j);
		if (ft_tablen(oxy) == 1)
			break ;
		j++;
	}
	printf("==final oxy==\n");
	ft_printf(oxy);
	co3 = (char **)malloc(sizeof(char) * ft_tablen(argv) + 1);
	i = 0;
	k = 0;
	while (argv[++i])
	{
		len = strlen(argv[i]);
		co3[k] = malloc(sizeof(char) * (len + 1));
		co3[k] = argv[i];
		co3[k][len] = '\0';
		k++;
	}
	co3[k] = NULL;
	j = 0;
	while (flag)
	{
		i = -1;
		one = 0;
		zero = 0;
		while (co3[++i])
		{
			if (co3[i][j] == '1')
				one++;
			if (co3[i][j] == '0')
				zero++;
		}
		if (one >= zero)
			ft_get0(co3, j);
		else
			ft_get1(co3, j);
		if (ft_tablen(co3) == 1)
			break ;
		j++;
	}
	printf("==final co3==\n");
	ft_printf(co3);
	i = 0;
	j = 0;
	k = 0;
	while (oxy[0][i] && co3[0][i])
	{
		if (oxy[0][i] == '1')
			j = j * 2 + 1;
		else
			j *= 2;
		if (co3[0][i] == '1')
			k = k * 2 + 1;
		else
			k *= 2;
		i++;
	}
	printf("oxy: %d\n", j);
	printf("co3: %d\n", k);
	printf("oxy x co3: %d\n", j * k);
}
