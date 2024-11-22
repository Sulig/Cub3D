/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3Dgame.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:42:58 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/22 12:58:48 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

/*	libraries	*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../New_Libft/inc/libft.h"

/*add mlx h*/
# include "keys.h"

/*	defines	*/
# define MLX_ERROR		0

# define HEIGHT 		1080
# define WIDTH			1080

# define MOVESPEED		0.07
# define ROTSPEED		0.05

# define NORTH			0
# define SOUTH			1
# define WEST			2
# define EAST			3

# define TEX_SIZE		64

// falta un int mapX, mapY que no se si hace falta
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_h;
	int		draw_start;
	int		draw_end;
}		t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		rotate;
	int		move_x;
	int		move_y;
	int		has_moved;
}		t_player;

typedef struct s_map
{
	char		**file;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			f_rgb[3];
	int			c_rgb[3];
	char		**map;
	int			height;
	int			width;
	t_player	*p;
}				t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_data
{
	t_player	*p;
	t_map		*m;
	void		*mlx;
	void		*win;
	t_ray		r;
	t_img		img;
	t_img		text_img[4];
	int			height;
	int			width;
	int			tex_x;
	double		tex_pos;
	double		tex_step;
}		t_data;

/*	INIT	*/
/*	init_data.c	*/
void	ft_init_player(t_player *p);
void	ft_init_map(t_data *data, t_map *m);
void	ft_init_tray(t_ray *r);
void	ft_init_tdata(t_data *data);
/*	init_mlx.c	*/
void	ft_init_start_img(t_img *img);
void	ft_init_img(t_data *data, t_img *img);
void	ft_init_mlx(t_data *data);

/*	MOVEMENT	*/
/*	input_handler.c	*/
int		ft_key_pressed(int key, t_data *data);
int		ft_key_released(int key, t_data *data);
void	ft_listen_for_input(t_data *data);
/*	player_direction.c	*/
void	ft_init_player_pos(t_player *p, int x, int y, char c);
void	ft_init_player_dir_ns(t_player *p);
void	ft_init_player_dir(t_player *p);
/*	player_movement.c	*/
int		ft_move_player_up(t_data *data);
int		ft_move_player_down(t_data *data);
int		ft_move_player_left(t_data *data);
int		ft_move_player_right(t_data *data);
int		ft_move_player(t_data *data);
/*	player_position.c	*/
int		ft_valid_pos(t_data *data, double newX, double newY);
int		ft_validate_move(t_data *data, double newX, double newY);
/*	player_rotate.c	*/
int		ft_rotate_lr(t_data *data, double rotspeed);
int		ft_rotate_player(t_data *data, double rotate);

/*	PARSE	*/
/*	parse_info.c	*/
void	ft_readfile(t_data *data, int fd, t_map *m, int j);
void	ft_check_file(t_data *data, char *map, t_map *m);
char	*ft_get_fc(t_data *data, char *dir, char *str, char c);
int		ft_find_info(t_data *data, t_map *m, int j, int line_len);
void	ft_parse_info(t_data *data, t_map *m);
/*	parse_info2.c	*/
char	*ft_save_info(t_data *data, char *dir, char *info, int line_len);
int		ft_is_valid_line(char *line);
int		ft_check_rgb(t_data *data, t_map *m);
char	*ft_get_map_line(char	*str, int width, int i, int j);
/*	parse_map.c	*/
void	ft_find_map_limits(t_data *data, t_map *m, int i);
void	ft_get_map(t_data *data, t_map *m, int *i, int aux);
int		ft_check_map_spaces(t_map *m, int i, int j);
int		ft_check_map_chars(t_map *m, int i, int j, int *player);
void	ft_check_valid_map(t_data *data, t_map *m, int i, int j);
/*	parse_map2.c	*/
void	ft_more_boards(t_data *data, t_map *m, int i);
/*	parse_textures.c	*/
int		ft_check_texts(t_data *data, t_map *m);
char	*ft_clean_paths(char *src);

/*	RENDER	*/
/*	raycast.c	*/
void	ft_init_raycast(t_ray *r, t_player *p, int x);
void	ft_set_dda(t_ray *r, t_player *p);
void	ft_perform_dda(t_map *m, t_ray *r, int hit);
void	ft_calculate_length(t_data *data, t_ray *r);
int		ft_raycasting(t_data *data);
/*	render.c	*/
void	ft_set_tex_coord(t_data *data, t_ray *r, t_img *tex);
void	ft_draw_line(t_data *data, t_ray *r, t_img *tex, int x);
int		ft_render(t_data *data);
/*	textures.c	*/
int		ft_convert_rgb_to_hex(int *rgb);
void	ft_put_pixel(t_img *data, int x, int y, int color);
int		ft_get_tex_color(t_img *tex, int texX, int texY);
void	init_texture_img(t_data *data, t_img *image, char *path);

/*	UTILS	*/
/*	errors.c	*/
void	ft_free_array(void **array);
void	ft_free_tmap(t_map *m);
void	ft_error(t_data *data, char *msg);
void	ft_exit(t_data *data);
/*	get_next_line_utils.c	*/
char	*ft_substr_l(char *s, unsigned int start, size_t len);
char	*ft_strchr_l(const char *s, int c);
char	*ft_strjoin_l(char *ret, char *s2);
/*	get_next_line.c	*/
char	*ft_free(char **buffer);
char	*ft_fill_data(char *data, int fd, int flag);
char	*ft_clean_buffer(char *data);
char	*ft_else(char **data, char **ret);
char	*get_next_line(int fd);
/*	print_utils.c	*/
void	ft_print_array(char **array, int i);
void	ft_print_map_data(t_map *m);
/*	utils_line.c	*/
int		ft_count_lines(int fd);
char	*ft_put_spaces(int width);
char	*ft_trim_final_spaces(t_data *data, char *str, int j, int k);
char	*ft_clean_line(char *str);
/*	utils_tabs.c	*/
int		ft_count_tabs(char *line);
char	*ft_return_tabs_expanded(char *line, char *n_line);
char	*ft_expand_tabs(char *line);

#endif