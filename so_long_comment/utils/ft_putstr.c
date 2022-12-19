/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:33:17 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 14:32:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//descrição da função nas diretrizes da tarefa:
//Reproduz a string 's' no terminal.

void	ft_putstr(char *s)
{
	int	i; // criamos um índice para percorrer a string.

	i = 0; // o índice se inicia zerado
	while (s[i] != '\0') // enquanto o conteúdo de s[i] for diferente de nulo
	{
		write (1, &s[i], 1); // colocamos o  conteúdo de s[i] no terminal
		i++; // i ganha uma unidade
	}
}