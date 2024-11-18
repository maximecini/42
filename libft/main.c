/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:26 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/15 05:02:32 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if(!s1 && !s2)
		return 1;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
int	t_ascii(int (*f)(int), int (*of)(int), char *ft_name)
{
	char	i;

	i = 0;
	while (i != 127)
	{
		if ((!ft_strcmp(ft_name, "ft_isalnum") || !ft_strcmp(ft_name,
					"ft_isalpha") || !ft_strcmp(ft_name, "ft_isprint")
				|| !ft_strcmp(ft_name, "ft_isdigit")) && (((f(i) == 0)
					&& (of(i) == 0)) || ((f(i) < 0) && (of(i) < 0))
				|| ((f(i) > 0) && (of(i) > 0))))
		{
			i++;
		}
		else if (of(i) == f(i))
			i++;
		else
		{
			printf("%s: 🙈! erreur sur ascii %d valleur attendu:%d valleur:%d \n", ft_name, i, of(i), f(i));
			return (0);
		}
	}
	printf("%s: ✅\n", ft_name);
	return (1);
}

int	t_bzero(void)
{
	size_t	i;
	size_t	l;
	size_t	p;
	char	ft_str_cpy[12][15] = {"bonj", "^derin", "00000", "dd", "00000",
			"querty *", "6lll_", "125lsd17", "l", "1", ""};
	char	of_str_cpy[12][15] = {" bonj", "^derin", "00000", "dd", "00000",
			"querty *", "6lll_", "125lsd17", "l", "1", ""};

	i = 0;
	l = 0;
	while (i < 12)
	{
		l = strlen(ft_str_cpy[i]);
		ft_bzero(ft_str_cpy[i], l);
		bzero(of_str_cpy[i], l);
		p = 0;
		while (p < l)
		{
			if (of_str_cpy[i][p] != ft_str_cpy[i][p])
			{
				printf("bzero: 🙈! erreur sur le mot: %zu letter: %zu \n", i, p);
				return (0);
			}
			p++;
		}
		i++;
	}
	printf("bzero: ✅\n");
	return (1);
}

int	t_fmem(void *(*f_ft)(void *dest, const void *src, size_t n),
		void *(*f_of)(void *dest, const void *src, size_t n), char src[12][15],
		char *name)
{
	char	ft_dest[15];
	char	of_dest[15];
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	while (i < 12)
	{
		l = strlen(src[i]);
		f_ft(ft_dest, src[i], l);
		f_of(of_dest, src[i], l);
		j = 0;
		while (src[i][j])
		{
			if (of_dest[i] != ft_dest[i])
			{
				printf("%s mot: %s valeur attendu: %c valeur: %c  🙈 \n", name,
					src[i], of_dest[i], ft_dest[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("%s: ✅\n", name);
	return (1);
}

int	t_str(size_t (*f_ft)(char *dest, const char *src, size_t n),
		size_t (*f_of)(char *dest, const char *src, size_t n), char src[12][15],
		char *name)
{
	char	of_dest[15] = {};
	char	ft_dest[15] = {};
	int		of = 0;
	int		ft = 0;
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	while (i < 12)
	{
		l = strlen(src[i]);
		ft = f_ft(ft_dest, src[i], l);
		of = f_of(of_dest, src[i], l);
		j = 0;
		while (src[i][j])
		{
			if (of_dest[i] != ft_dest[i] || of != ft)
			{
				printf("%s mot: %s valeur attendu: %s. valeur: %s. 🙈 \n", name,
					src[i], of_dest, ft_dest);
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("%s: ✅\n", name);
	return (1);
}
int	t_memset(void)
{
	char	ft_dest[47];
	char	of_dest[47];
	char	src[12][1] = {"a", "^", ".", "", "0", "*", "!", "1", "l", "1", ""};
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 12)
	{
		j = rand() % 50 + 1;
		ft_memset(ft_dest, src[i][0], j);
		memset(of_dest, src[i][0], j);
		if (of_dest[i] != ft_dest[i])
		{
			printf(" memset mot: %s valeur attendu: %c. valeur: %c. 🙈 \n",
				src[i], of_dest[i], ft_dest[i]);
			return (0);
		}
		i++;
	}
	printf("memset: ✅\n");
	return (1);
}
int	t_strchr(char *(*f_ft)(const char *string, int searchedChar),
		char *(*f_of)(const char *string, int searchedChar), char src[12][15],
		int list_int[11], char *name)
{
	char	*of_dest;
	char	*ft_dest;
	size_t	i;
	size_t	j;
	char	dest_temps[15]={};
	char	of_temps[15]= {};
	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 11)
		{
			strcpy(dest_temps, src[i]);
			strcpy(of_temps, src[i]);
			
			ft_dest = f_ft(dest_temps, list_int[j]);
			of_dest = f_of(of_temps, list_int[j]);

			if (ft_strcmp(ft_dest, of_dest) && (ft_dest !=  NULL && of_dest != NULL ))
			{
				printf("%s mot: %s valeur attendu: %s. valeur: %s. 🙈 \n",name, of_temps, of_dest, ft_dest);
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("%s: ✅\n", name);
	return (1);
}

int t_strncpm(char s1[12][15], char s2[12][15],int *nb)
{
		size_t t;

		t = 0;
		while (t < 11)
		{
			
			if(ft_strncmp(s1[t], s2[t],(size_t)nb[t]) != strncmp(s1[t], s2[t],(size_t)nb[t]))
			{
				printf("strncp mot: %s  et %s valeur attendu: %d. valeur: %d. 🙈 \n", s1[t], s2[t], strncmp(s1[t], s2[t],(size_t)nb[t]),ft_strncmp(s1[t], s2[t],(size_t)nb[t]));
				return (0);
			}
			t++;
		}
			printf("strncmp: ✅\n");
		return 0;
}

int	main(void)
{
	char src[12][15] = {"bonj", "^derin", "00000", "dd", "00000", "qu+erty *",
		"6l#l_", "125ls*d17", "l", "1", "\0", "l"};
	char src2[12][15] = {"0000",  "bonj", "dd", "00000","^derin", "qu+erty *",
		"125ls*d17","6l#l_",  "l", "1", "\0", "l"};
	int list_int[11] = {'a', 'Z', '#', 130, '-', 5, '+', -8, 9, 10};


	t_ascii(&ft_isalnum, &isalnum, "ft_isalnum");
	t_ascii(&ft_isalpha, &isalpha, "ft_isalpha");
	t_ascii(&ft_isdigit, &isdigit, "ft_isdigit");
	t_ascii(&ft_isascii, &isascii, "ft_isascii");
	t_ascii(&ft_isprint, &isprint, "ft_isprint");
	t_ascii(&ft_toupper, &toupper, "toupper");
	t_ascii(&ft_tolower, &tolower, "tolower");

	t_bzero();
	t_fmem(&ft_memcpy, &memcpy, src, "memcpy");
	t_fmem(&ft_memmove, &memmove, src, "memmove");
	t_memset();

	t_str(&ft_strlcat, &strlcat, src, "strlcat");
	t_str(&ft_strlcpy, &strlcpy, src, "strlcpy");

	t_strchr(&ft_strchr, &strchr, src, list_int, "strchr");
	t_strchr(&ft_strrchr, &strrchr, src, list_int, "strrchr");
	t_strncpm(src, src2, list_int); 
	

/*  	char **result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');*/	


 	char **result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	free(result);
	printf("%s",ft_itoa(156));

}