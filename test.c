/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fablin <fablin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:08:14 by fablin            #+#    #+#             */
/*   Updated: 2017/11/17 11:09:00 by fablin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int fd = open("file", O_RDONLY);
	char buffer[10];
	read(fd, buffer, 10);
	write(1, buffer, 11);
	buffer[1] = 0;
	write(1, buffer, 2);
	return 0;
}