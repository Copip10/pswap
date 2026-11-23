#include "push_swap.h"

static	int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == sep)
			i++;
		if (str[i] != sep && str[i] != '\0')
		{
			count++;
			while (str[i] != sep && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*ft_strncpy(char *src, char *dest, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	free_dests(char **dest, int j)
{
	while (j >= 0)
	{
		free(dest[j]);
		j--;
	}
	free(dest);
}

static int	fill_dest(char **dest, char const *s, int count, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < count)
	{
		k = 0;
		while (s[i] == c && s[i + k] != '\0')
			i++;
		while (s[i + k] != c && s[i + k] != '\0')
			k++;
		dest[j] = malloc(sizeof(char) * (k + 1));
		if (dest[j] == NULL)
		{
			free_dests(dest, j);
			return (0);
		}
		dest[j] = ft_strncpy((char *)&s[i], dest[j], k);
		i += k;
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**dest;

	count = count_word((char *)s, c);
	dest = malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	if (!fill_dest(dest, s, count, c))
		return (NULL);
	dest[count] = NULL;
	return (dest);
}