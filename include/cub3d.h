/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:00:11 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/20 16:32:46 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include "../mlx/mlx.h"

// UNALLOWED TEMPORARY INCLUDES
#include <stdio.h>
#include <time.h>

// MACROS
#define W 1024
#define H 512
#define KEY_PRESS 2
#define KEY_RELEASE 3
#define FRAMES 0.012
#define A_KEY 0
#define D_KEY 2
#define W_KEY 13
#define S_KEY 1
#define LEFT_KEY 123
#define RIGHT_KEY 124

// MOVEMENT
#define MOVE_SPEED 0.039 * 3
#define ROT_SPEED 0.033 * 3
#define CORNER_DISTANCE 0.25
#define WALL_DISTANCE 0.3
// #define KEY_UP 125
// #define  125

// STRUCTS
typedef struct s_img
{
    void *mlx;
    void *mlx_win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;


typedef struct s_rc_data
{
    double dir_x;
    double dir_y;
    int hit;
    int ray_map_coor_x;
    int ray_map_coor_y;
    int **map;
    int **texture;
    int wall_height;
    int draw_start;
    int draw_end;
    double wall_x;
    int step_x;
    int step_y;
    int side;
    double pos_x;
    double pos_y;
    double camera_plane_x;
    double camera_plane_y;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    double time;      // time of current frame
    double old_time;  // time of previous frame
    double moveMOVE_SPEED; // the constant value is in squares/second
    double rotMOVE_SPEED;
} t_rc_data;

typedef struct s_map
{
    int width;
    int height;
    int **arr;
}   t_map;

typedef struct s_tex
{
    t_img img;
    int width;
    int height;
    int **arr;
}   t_tex;

typedef struct s_keys
{
    int up;
    int down;
    int left;
    int right;
    int rotate_left;
    int rotate_right;
}   t_keys;

typedef struct s_data
{

    t_rc_data rc;
    t_map map;
    t_img img;
    t_keys keys;
    t_img front_img_buffer;
    t_img back_img_buffer;
    t_tex tex[4];
} t_data;

// FUNCTIONS

// EVENTS
int ft_key_down(int keycode, t_data *d);
// INIT
void ft_init_vars(t_data *d);
void ft_init_img(t_img *img, void *mlx);
int **ft_fill_texture(t_tex tex);
void ft_init_textures(t_data *d);
// RENDER
int ft_render_frame(t_data *d);
void ft_put_image(t_data *d);
void ft_cast_rays(t_data *d);
void	ft_draw_buffer(t_data *d, int buffer[1080][1920]);
void ft_draw_vertical_line(int x, int draw_start, int draw_end, int color, t_img *img);
void ft_draw_ceiling_and_floor(t_data *d);
// PARSE
int ft_parse_map(t_data *d, char *path);
// UTILS
void ft_my_mlx_pixel_put(t_img *data, int x, int y, int color);
int ft_create_trgb(int t, int r, int g, int b);
unsigned char	ft_get_t(int trgb);
unsigned char	ft_get_r(int trgb);
unsigned char	ft_get_g(int trgb);
unsigned char	ft_get_b(int trgb);
int     ft_key_down_check(int keycode, t_data *d);
int     ft_key_up_check(int keycode, t_data *d);
int ft_my_pixel_get(t_img *img, int x, int y);
// MOVEMENT
void ft_move_forward(t_data *d);
void ft_move_backward(t_data *d);
void ft_move_left(t_data *d);
void ft_move_right(t_data *d);
void ft_rotate_left(t_data *d);
void ft_rotate_right(t_data *d);


#endif