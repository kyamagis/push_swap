/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:26:49 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/17 17:30:34 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lens1 + lens2 + 1 );
	return (str);
}

/*#include <stdio.h>
int main(void)
{
    char const prefix[] = "omaeha";
	char const suffix[] = "moushindeiru";
  
    printf("[presuf]%s\n\n", ft_strjoin(prefix, suffix));

	//printf("[nullsuf]%s\n", ft_strjoin(0, suffix));
	// printf("%s\n", ft_strjoin(prefix, 0));
	// printf("%s\n\n", ft_strjoin(0, 0));

	printf("[spesuf]%s\n", ft_strjoin("", suffix));
	printf("[presuf]%s\n", ft_strjoin(prefix, ""));
	printf("[spespe]%s\n\n", ft_strjoin("", ""));
}*/