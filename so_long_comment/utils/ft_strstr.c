/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:59:52 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 12:59:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//man strnstr:
//A função strntr()  encontra a primeira ocorrência da substring agulha (terminada 
//por '\0' na string. Os caracteres que 
//aparecem após um caractere `\0' não são pesquisados. Esta função devolve um ponteiro
// da posição da string palheiro onde o início da substring foi  localizado, ou NULL se 
//a substring não for encontrada. Se a agulha for uma string vazia, o valor de retorno é 
//sempre o próprio palheiro.

//essa função procura se o conteúdo da string s2 aparece na strinh s1
char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*str; //criamos um ponteiro auxiliar para receber s1 (palheiro)
	const char	*to_find; // criamos um ponteiro auxiliar para receber s2 (agulha)
	size_t		i; //criamos um índice para percorrer a string s1 (palheiro)
	size_t		p; //criamos um índice para percorrer a string s2 (agulha - pin)

	i = 0; // o índice inicia em zero
	str = s1; // str recebe a string si
	to_find = s2; // to_find recebe a string s2 
	if (to_find[i] == '\0') // se to_find na posição zero já for nula, ela está vazia
		return ((char *)str); // então não temos o que encontrar e retornamos um ponteiro para o 
		//palheiro. Esse ponteiro é convertido para char* antes de ser enviado
	p = 0; // o índice que vai percorrer a to_find é iniciado zerado
	while (str[i] != '\0') //enquanto str[i] não for nula
	{
		p = 0; // o índice que vai percorrer a to_find é iniciado zerado
		while (str[i + p] == to_find[p] && str[i + p] != '\0' && i + p) // enquanto
		//str for idêntica a to_find, paramos de andar o índice i e acrescentamos apenas o índice p
		//a vantagem desse método é que se a comparação encontrar a to_find completa dentro da str
		// o índice i está guardando a posição do início do pareamento, e se não for identica
		// apenas zeramos o índice p e avançamos o i para a próxima comparação
		//então equanto str[i + p] for idêntica a to_find[p] e str[i + p] não for o byte nulo e
		{
			if (to_find[p + 1] == '\0') //se o próximo byte do to_find for o byte nulo
			// quer dizer que enontramos a to_find inteira dentro da src
				return (&((char *)str)[i]); // então retornamos a posição do início do pareamento str[i]
				// já convertida para um ponteiro de char
			p++; // caso o próximo byte do to_find não for o byte nulo ela não, o
			// contador p recebe uma unidade
		}
		// se saiu do while é por que o pareamento não foi perfeito
		i++; // avançamos para o próximo ítem da string str (o índice da to_find será zerado na linha 48)
		//assim tentaremos encaixar  de novo a to_find iniciando no 0 com a str iniciando em i
	}
	return (NULL); // se não econtrarmos a to_find na str, retornamos null
}