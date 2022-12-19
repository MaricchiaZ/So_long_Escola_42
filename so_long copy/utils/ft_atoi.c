/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:05:43 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 12:05:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//man atoi:
//A função atoi() converte a porção inicial da string apontado por nptr para int.

//esta função tranforma uma string de char numérico em um inteiro
int	ft_atoi(const char *nptr)
{
	int	i; // índice para percorrer a string
	int	signal; // vai ser multipicar o nb no final, e vai armazenar o valor de -1 se a string começar com '-'
	int	nb; //será o número que vamos retornar

	i = 0; // índice da string começa na posição 0, ou seja a primeira posição da string
	signal = 1; // o sinal é iniciado em 1, e se o númeri for positivo ele não será modificado
	nb = 0; // o int nb começa sem valer nada
	if (!nptr[i]) //se a string estiver vazia
		return (0); //retornamos zero
	while ((nptr[i] == '\t') || (nptr[i] == '\v') || (nptr[i] == '\f') || \
	(nptr[i] == '\n') || (nptr[i] == '\r') || (nptr[i] == ' ')) // se o início da string for espaço, ou qualquer
	//caracter de tabulação, simplesmente seguimos em frente
		i = i + 1; // vamos andando o índice de 1 em 1 enquanto for caracter de tabulação
	if (nptr[i] == '+' || nptr[i] == '-') // se for caracter de sinal, vai entrar nesse if
	{
		if (nptr[i] == '-') //caso nptr[i] seja o sinal de -
			signal *= -1; //signal passa a valer -1
		i++; //passamos para a próxima casa
	}
	while (nptr[i] >= 48 && nptr[i] <= 57) // enquanto o nptr[i] for um caracter entre 0 e 9, isto é, for numérico
	{
		// nb recebe o (nb anterior x 10) + (o número atual em valor númerico, não em valor ASCII)
		nb = (nb * 10) + (nptr[i] - 48);
		i++; // e vamos para a próxima casa
	}
	return (nb * signal); // multiplicamos o nb pelo sinal, para ficar negativo se a string tivesseo - no início
}

