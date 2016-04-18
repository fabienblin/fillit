/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:52:41 by fblin             #+#    #+#             */
/*   Updated: 2015/11/25 12:52:58 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int isalpha;
	int islower;
	int isupper;

	islower = (c >= 'a' && c <= 'z');
	isupper = (c >= 'A' && c <= 'Z');
	isalpha = (isupper || islower);
	return (isalpha);
}
