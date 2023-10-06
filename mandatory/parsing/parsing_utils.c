/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:47:50 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 10:17:09 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp_cub(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

t_dir	*ft_lstlast_cub(t_dir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_cub(t_dir **lst, t_dir *new)
{
	t_dir	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast_cub(*lst);
		last->next = new;
	}
}

t_dir	*ft_lstnew_cub(char *key, char *value)
{
	t_dir	*ls;

	ls = malloc(sizeof(t_dir));
	if (!ls)
		return (0);
	ls->key = ft_strdup(key);
	ls->value = ft_strdup(value);
	ls->next = NULL;
	return (ls);
}

int	ft_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}
