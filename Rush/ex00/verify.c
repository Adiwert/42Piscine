/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:54:17 by jthiew            #+#    #+#             */
/*   Updated: 2024/09/01 15:32:06 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		ft_len(char *str);
extern int	g_set;

int	ft_valid_number(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 2 || argv[i] == '\0')
	{
		ft_putstr("Error. Please input 1 argument.\n");
		return (0);
	}
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ' && !(argv[i] >= '1' && argv[i] <= (g_set + '0')))
		{
			ft_putstr("Error. Argument value invalid.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_valid_grid(int argc, char *argv)
{
	int	len;
	int	i;

	len = ft_len(argv);
	i = 0;
	while (argv[i] != '\0')
	{
		if (g_set <= 3)
		{
			ft_putstr("Error. Grid smaller than 4x4.\n");
			return (0);
		}
		if (g_set > 9)
		{
			ft_putstr("Error. Grid larger than 9x9.\n");
			return (0);
		}
		if (len % 4 != 0)
		{
			ft_putstr("Error. Argument does not define square grid.\n");
			return (0);
		}
		i++;
	}
	return (ft_valid_number(argc, argv));
}
