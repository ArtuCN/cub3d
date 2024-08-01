/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:20:23 by aconti            #+#    #+#             */
/*   Updated: 2023/10/20 17:21:29 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static char	**free_everything(char **result, int g)
{
	while (--g >= 0)
		free(result[g]);
	free(result);
	return (NULL);
}

static char	**riempi_stringa(int n, const char *s, char c, char **result)
{
	int	g;
	int	i;
	int	len;

	g = -1;
	i = 0;
	len = 0;
	while (++g < n)
	{
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		result[g] = malloc(sizeof(char) * (len + 1));
		if (result[g] == NULL)
			return (free_everything(result, g));
		result[g][len++] = '\0';
		i = len - 1;
		while (--len > 0)
			result[g][len - 1] = s[len - 1];
		s += i;
	}
	return (result);
}

char	**ft_split(const char *s, char c)
{
	int		n_parole;
	int		i;
	char	**result;

	if (s == NULL || *s == '\0')
	{
		result = ft_calloc(sizeof(char *), 1);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	i = -1;
	n_parole = 0;
	if (s[0] != c && s[0] != '\0')
		n_parole++;
	while (s[++i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			n_parole++;
	}
	result = malloc(sizeof(char *) * (n_parole + 1));
	if (result == NULL)
		return (NULL);
	result[n_parole] = 0;
	return (riempi_stringa(n_parole, s, c, result));
}

/*
int main() {
    char const *input_string = "  il comunismo  .  fa   cagare  ";
    char separator = ' ';

    char **result = ft_split(input_string, separator);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
        }

        // Liberare la memoria allocata
        for (int i = 0; result[i] != NULL; i++) {
            free(result[i]);
        }
        free(result);
    } else {
        printf("Errore durante la divisione della stringa.\n");
    }

    return 0;
}*/
