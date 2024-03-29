/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:00:11 by dbekic            #+#    #+#             */
/*   Updated: 2023/06/23 09:21:06 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdio.h>

// MACROS
# define W 1300
# define H 650
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define FRAMES 0.012
# define A_KEY 0
# define D_KEY 2
# define W_KEY 13
# define S_KEY 1
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define EXIT_KEY 53
# define MAX_ROWS 100
# define MAX_COLS 100
# define NORTH_TEX_INDEX 0
# define EAST_TEX_INDEX 1
# define SOUTH_TEX_INDEX 2
# define WEST_TEX_INDEX 3

// MOVEMENT
# define MOVE_SPEED 0.049
# define ROT_SPEED 0.043
# define CORNER_DISTANCE 0.125
# define WALL_DISTANCE 0

// STRUCTS

typedef struct s_i_love_norminette
{
	int		dir;
	int		tex_y;
	int		tex_x;
	int		color;
	int		y;
	double	step;
	double	tex_pos;
}	t_i_love_norminette;

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_rc_data
{
	int		hit;
	int		ray_map_coor_x;
	int		ray_map_coor_y;
	int		**map;
	int		wall_height;
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	int		side;
	int		**texture;
	double	wall_x;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	camera_plane_x;
	double	camera_plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	time;
	double	old_time;
}	t_rc_data;

typedef struct s_map
{
	int		start_line;
	int		width;
	int		height;
	char	**arr;
}	t_map;

typedef struct s_tex
{
	t_img	img;
	char	*path;
	int		**arr;
	int		width;
	int		height;
	int		ready;
}	t_tex;

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		exit_key;
}	t_keys;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	t_rc_data	rc;
	t_map		map;
	t_img		img;
	t_keys		keys;
	t_img		front_img_buffer;
	t_img		back_img_buffer;
	t_tex		tex[4];
	t_color		floor;
	t_color		ceiling;
}	t_data;

// FUNCTIONS

// EVENTS
int		ft_key_down(t_data *d);
// INIT
void	ft_init_vars(t_data *d);
void	ft_init_img(t_img *img, void *mlx);
void	ft_init_rc_vars(t_data *d, int x);
// int **ft_fill_texture(t_tex tex);
void	ft_fill_texture(t_data *d, int i);
void	ft_init_textures(t_data *d);
void	ft_init_pos(t_data *d, int i, int j, char pos);
// RENDER
int		ft_render_frame(t_data *d);
void	ft_put_image(t_data *d);
void	ft_cast_rays(t_data *d);
void	ft_draw_ceiling_and_floor(t_data *d);
// PARSE
int		ft_parse_cub(t_data *d, char *path);
char	*get_next_line(int fd);
void	ft_parse_map(t_data *d, int fd);
void	ft_check_if_first_and_last_line_is_one_or_point(t_data *d);
void	ft_check_if_first_and_last_columns_is_one_or_point(t_data *d);
void	ft_check_if_map_has_player_pos_and_dir(t_data *d);
void	ft_check_allowed_chars(t_data *d);
void	ft_check_if_surrounded_by_walls(t_data *d);
void	ft_remove_isspace_from_end_of_str(char *str);
int		ft_get_map_height(t_data *d, char *path);
void	ft_check_extension(char *str);
void	ft_parse_color(char *line, t_color *color);
int		ft_open_file_for_reading(char *path);

// UTILS
char	*ft_strdup(const char *src);
void	ft_my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_create_trgb(int t, int r, int g, int b);
int		ft_key_down_check(int keycode, t_data *d);
int		ft_key_up_check(int keycode, t_data *d);
int		ft_my_pixel_get(t_img *img, int x, int y);
int		ft_is_digit(char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_get_t(int trgb);
int		ft_get_r(int trgb);
int		ft_get_g(int trgb);
int		ft_get_b(int trgb);
// MOVEMENT
void	ft_move_forward(t_data *d);
void	ft_move_backward(t_data *d);
void	ft_move_left(t_data *d);
void	ft_move_right(t_data *d);
void	ft_rotate_left(t_data *d);
void	ft_rotate_right(t_data *d);
// EXIT
void	ft_exit(char *message, int flag);

#endif
