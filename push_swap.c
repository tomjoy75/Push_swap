/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:14:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/24 17:56:21 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;

	if (argc < 2)
		return (1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	


	return (0);
}
