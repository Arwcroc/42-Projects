/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:20:26 by tefroiss          #+#    #+#             */
/*   Updated: 2020/08/18 15:22:22 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	CUB3D_H
# define	CUB3D_H

# define	GAME_NAME	"cub3d"
# define	RIGHT		123
# define	LEFT		124
# define	DOWN		125
# define	UP			126
# define	KEY_A		0
# define	KEY_D		2
# define	ESCAPE		53
# define	STEP		0.15
# define	ROTATION	7
# define	LIGHT_RATIO	0.1
# define	FOV			66
# define	FPS			60
# define	IDMAP		" 012NEWS"

# include	<math.h>
# include	<stdio.h>
# include	<errno.h>
# include	<fcntl.h>
# include	<time.h>
# include	<mlx.h>
//# include	"../libs/minilibx_opengl_20191021/mlx.h"
# include	"../libs/cubvector/includes/cubvector.h"
# include	"../libs/libft/includes/libft.h"

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

t_color				ft_color(int r, int g, int b);

typedef struct		s_image
{
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	t_image			img;
}					t_window;

t_window			ft_window(double *width, double *height, char *name);
t_image				ft_image(t_window window, int width, int height);
void				ft_put_pixel(t_vector *vector, t_color color, t_image dataimg);
// void				ft_clear_image(t_window *window);

typedef struct		s_map
{
	int				width;
	int				height;
	int				**map;
	t_color			color;
	t_window		window;
	t_vector		coordinate;
}					t_map;

t_map				ft_minimap(int **map, int width, int height);
// void				ft_clear_map(t_map *map);

typedef struct 		s_draw
{
	int				draw_s;
	int				draw_e;
	double			dist;
}					t_draw;


typedef struct		s_player
{
	t_vector		coordinate;
	t_map			map;
	t_color			color;
	t_vector		plane;
	t_vector		orientation;
	double			fov;
}					t_player;

typedef struct		s_texture
{
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_texture;

t_texture			ft_texture(void *mlx_ptr, char *path);

typedef struct		s_sprite
{
	t_vector		player_pos;
	t_vector		sprite_pos;
	t_texture		text;
	double			dist;
	double			order;
	double			x;
	double			y;
}					t_sprite;


typedef struct		s_game
{
	t_window		window;
	t_map			map;
	t_player		player;
	t_texture		wall_no;
	t_texture		wall_so;
	t_texture		wall_we;
	t_texture		wall_ea;
	t_texture		good_text;
	t_texture		s1;
	t_texture		s2;
	t_texture		good_sp;
	t_color			ceil_color;
	t_color			floor_color;
	t_draw			line;
	int				key[6];
	t_sprite		*allsprite;
	int				*sprite_order;
	double			*sprite_dist;
	int				**buf;
	double			*sbuffer;
	int				count_s;
}					t_game;

t_game				ft_game(char *path);
void				draw_map(t_game *game);
int					player_move(t_game *game);
int					player_turn(t_game *game);

typedef struct		s_ray
{
	t_vector		point; //mpos
	t_vector		direction; //dir
	t_vector		sidedist; //sdist
	t_vector		deltadist; //dist
	t_vector		step; //step
	int				side; //side
	double			cam_coordinate; //cam
}					t_ray;

typedef struct		s_bmp_header
{
	int				file_size;
	int				pixel_offset;
	int				img_width;
	int				img_height;
	int				header_size;
	int				nothing;
	short int		bpp;
	short int		plane;
}					t_bmp_header;


int					ft_ray(t_game *game);
int					check_resolution(char *path);
int					ft_check_extension(char *filename, char *extension);
int					check_alpha_in_line(char *line);
int					ft_str_isequal(char *str1, char *str2);
int					ft_isexist(char *path);
int					get_map(char *path, t_game *game);
int					is_wall(int x, int y, t_game *game);
int					ft_handle_events(int keycode, t_game *game);
int					ft_handle_release(int keycode, t_game *game);

double				ft_deg_rad(double angle);

void				check_texture(char *path);
void				check_color(char *path);
void				draw(t_game *game, t_ray *ray, int x);
void				ft_player(t_vector coordinate, double orientation,\
					t_game *game);
void				write_bmp_header(t_game *game);
void				bmp_init(t_game *game, t_bmp_header *bpm);
void				tag_sprite(t_ray *ray, t_game *game, int sprite);
void				drawbuff(t_game *game);
void				sprite_casting(t_game *game);

char				*ft_move_until(char *str, char *bool, int (*f)(int));
char				*searchLine(char *path, char *charcode);

t_vector			get_resolution(char *path);
t_color				get_color(char *path, char *code);
t_texture			get_texture(char *path, char *code, t_window *window);
t_color				show_texture(t_ray *ray, t_game *game, double i);

#	endif
