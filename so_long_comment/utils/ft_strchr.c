/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:23:32 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 14:34:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//man strrchar
//A função strrchr() retorna um ponteiro para a última ocorrência do caractere c na 
//string s. Aqui "caracter" significa "byte"; estas funções não funcionam com caracteres
// largos ou multibyte. A função strrchr() retorna um ponteiro para o caractere 
//correspondente ou NULL se o caractere não for encontrado. O byte nulo terminante é 
//considerado parte da string, de modo que se c for especificado como "\0", estas funções 
//retornam um ponteiro ao terminador.

// retorna um ponteiro para a última ocorrência do char c na string s
char	*ft_strrchr(const char *s, int c)
{
	int	i; // criamos um índice para percorrer a string s

	i = 0; // iniciamos o índice em zero
	while (s[i] != '\0') // enquanto a string s na posição i não for nulo
		i++; //adicionamos uma unidade em i, assim chegamos no fim da string s
	if (s[i] == '\0' && c == '\0') //se chegamos no fim da string s e agora ela vale '\0'
	// e o valor que procuramos em c é o byte nulo '\0'
		return ((char *)s + i); // retornamos o ponteiro s adicionado de i, para termos
		// um ponteiro para o byte final, esse ponteiro é convertido para um ponteiro char
	while (i >= 0) // enquanto i for maior ou igual a 0
	{
		// começamos a olhar de trás para frente, por que queremos a útima ocorrência
		if (s[i] == (unsigned char)c) // se o conteúdo da string s na posição i for idêntico ao
		// valor de c já conferido para unsigned char
			return ((char *)s + i); // retornamos o ponteiro s adicionado de i, para termos
		// um ponteiro apontando para a última ocorrência de C na string s
		i--; // nosso i retorna 1
	}
	return (NULL); // se nada for encontrado, retornamos NULL
}