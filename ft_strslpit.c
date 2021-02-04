#include "bankomat.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] != '\0') && (i < start))
		i++;
	if (i != start)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((s[i] != '\0') && (j < len))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (j != len)
		return (NULL);
	return (str);
}

static void	*ft_cleanstr(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

static char	**ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;
	char	**str;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			if ((s[i + 1] == c) || (s[i + 1] == '\0'))
				w++;
			i++;
		}
	}
	str = malloc(sizeof(char *) * (w + 1));
	if (str == NULL)
		return (NULL);
	str[w] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	mas;
	size_t	wlen;
	size_t	i;
	char	**str;

	if (s == NULL)
		return (NULL);
	mas = 0;
	wlen = 0;
	i = 0;
	if (!(str = ft_count_words(s, c)))
		return (NULL);
	while (s[mas] != '\0')
	{
		if (s[mas] != c)
			wlen++;
		mas++;
		if (wlen > 0 && (s[mas] == c || s[mas] == '\0'))
		{
			if (!(str[i++] = ft_strsub(s, ((unsigned int)(mas - wlen)), wlen)))
				return (ft_cleanstr(str, i));
			wlen = 0;
		}
	}
	return (str);
}