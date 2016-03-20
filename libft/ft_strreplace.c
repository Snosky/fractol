/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:14:05 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/18 18:31:51 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strreplace(char *search, char *replace, char *s)
{
	char	*ret;
	char	*str;
	char	*tmp;

	tmp = ft_strdup(s);
	ret = NULL;
	if ((str = ft_strstr(tmp, search)) == NULL)
		return (NULL);
	str[0] = 0;
	ret = ft_strdup(tmp);
	ret = ft_strjoin(ret, replace);
	ret = ft_strjoin(ret, str + ft_strlen(search));
	if (ft_strstr(ret, search))
		ret = ft_strreplace(search, replace, ret);
	return (ret);
}
