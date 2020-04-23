/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snapshot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:21:32 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/14 17:40:03 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_init(int width, int height, int bpp, t_bmp *bmp)
{
	int	row_size;
	int	padding;

	row_size = width * bpp;
	padding = (4 - (row_size % 4)) % 4;
	bmp->bmh = (t_bmh) { 0 };
	bmp->bmh.width = width;
	bmp->bmh.height = height;
	bmp->bmh.bits_per_pixel = bpp;
	bmp->bmh.image_size = height * ((row_size / 8) + padding);
	bmp->bmh.file_size = 54 + bmp->bmh.image_size;
	bmp->img = ft_calloc(1, bmp->bmh.image_size);
}

void	bmp_write(char *path, t_bmp *bmp)
{
	int	fd;

	bmp->bmh.offset = 54;
	bmp->bmh.header_size = 40;
	bmp->bmh.planes = 1;
	fd = open(path, O_RDWR | O_CREAT, 0666);
	write(fd, "BM", 2);
	write(fd, &bmp->bmh, sizeof(t_bmh));
	write(fd, bmp->img, bmp->bmh.image_size);
	close(fd);
	free(bmp->img);
}

void	save_screen(t_game *g)
{
	t_bmp			bmp;
	unsigned int	i;
	unsigned int	width;
	unsigned char	*img;

	img = g->img.addr;
	bmp_init(g->pars.w, g->pars.h, 32, &bmp);
	i = bmp.bmh.image_size;
	width = bmp.bmh.width * 4;
	while (i > 0)
	{
		ft_memcpy(bmp.img + (i -= width), img, width);
		img += width;
	}
	bmp_write("screenshot.bmp", &bmp);
	quit(g);
}
