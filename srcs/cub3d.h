/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:20:46 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 16:56:58 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"

# define X 0
# define Y 1
# define TEXTURE_NUM 6
# define MAP_CHARS "012345NSEW"

typedef struct		s_bmh {
	unsigned int	file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short			planes;
	short			bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	used_colors;
	unsigned int	important_colors;
}					t_bmh;

typedef struct		s_bmp {
	t_bmh			bmh;
	unsigned char	*img;
}					t_bmp;

typedef	struct		s_pars {
	int		w;
	int		h;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
	char	**map;
}					t_pars;

typedef struct		s_key {
	unsigned char	up;
	unsigned char	down;
	unsigned char	left;
	unsigned char	right;
	unsigned char	r_left;
	unsigned char	r_right;
	unsigned char	l_up;
	unsigned char	l_down;
	unsigned char	crouch;
	unsigned char	jump;
	unsigned char	use;
}					t_key;

typedef	struct		s_pos {
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	angle;
	double	horizon;
}					t_pos;

typedef	struct		s_img {
	void	*img;
	void	*addr;
	int		bpp;
	int		ll;
	int		endian;
}					t_img;

typedef	struct		s_text {
	t_img	img;
	int		h;
	int		w;
}					t_text;

typedef	struct		s_sprite {
	int				pos_x;
	int				pos_y;
	int				h;
	int				w;
	int				screen;
	int				drawstart;
	int				drawend;
	struct s_sprite	*next;
}					t_sprite;

typedef	struct		s_render {
	double		invdet;
	double		raydir[2];
	double		dist[2];
	double		delta[2];
	int			map[2];
	int			step[2];
	int			side;
	t_sprite	*s;
}					t_render;

typedef struct		s_draw	{
	double		wall;
	int			n;
	int			lineh;
	int			x;
}					t_draw;

typedef struct		s_info	{
	int		hp;
	double	speed;
}					t_info;

typedef	struct		s_game	{
	void	*mlx;
	void	*win;
	t_pars	pars;
	t_img	img;
	t_pos	pos;
	t_key	key;
	t_text	tex[TEXTURE_NUM];
	t_info	info;
	int		save;
	double	jump;
}					t_game;

int					parsing(t_pars *pars, char *path);
void				free_ar(void **ar);
int					get_color(char *rgb);
int					get_map(t_list *lst, t_pars *pars);
void				get_values(char **ar, t_pars *pars);
int					quit(t_game *g);
void				rotate (int key, t_pos *p);
void				move (int key, t_game *g);
int					keypress(int key, t_game *g);
int					keyrelease(int key, t_game *g);
void				pixel_put(t_img *img, int x, int y, int color);
int					pixel_find(t_img *d, int x, int y);
int					sprite_list(t_sprite **alst, int pos_x, int pos_y);
void				calc_sprite(t_render *r, t_game *g);
void				calc_door(t_render *r, t_game *g);
void				draw_walls(t_draw *d, t_game *g, int v);
void				draw_sprites(t_render *r, t_game *g, int v);
void				draw(t_render *r, t_game *g, int v);
void				get_delta(t_game *g, t_render *r, int v);
void				get_dist(t_game *g, t_render *r);
int					render(t_game *g);
void				get_text(t_game *g);
void				def_position(t_pos *p, char c);
void				get_position(t_pos *p, t_pars *pars);
void				bmp_init(int width, int height, int bpp, t_bmp *bmp);
void				bmp_write(char *path, t_bmp *bmp);
void				save_screen(t_game *g);
int					error_msg(int code);
void				verify_map (char **map);
void				new_position(t_game *g);
void				new_position2(t_game *g);
void				draw_hp(t_game *g);
void				jump(t_game *g);
void				use(t_game *g);
#endif
