/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:00:11 by dbekic            #+#    #+#             */
/*   Updated: 2023/05/18 16:17:22 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../mlx/mlx.h"

// UNALLOWED TEMPORARY INCLUDES
#include <stdio.h>
#include <time.h>

// MACROS
#define W 1920
#define H 1080
#define KEY_PRESS 2
#define KEY_RELEASE 3
#define FRAMES 0.012
#define MOVE_SPEED 0.039 * 10
#define ROT_SPEED 0.033 * 10

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

typedef struct s_map
{
    int x;
    int y;
    int value;
} t_map;

typedef struct s_rc_data
{
    double dir_x;
    double dir_y;
    int hit;
    int map_x;
    int map_y;
    char step_x;
    int **map;
    int **texture;
    char step_y;
    char side;
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

typedef struct s_tex
{
    t_img img;
    int img_width;
    int img_height;
}   t_tex;

typedef struct s_data
{

    t_rc_data rc;
    t_map map;
    t_img img;
    t_img front_img_buffer;
    t_img back_img_buffer;
    t_tex texture_img[4];
} t_data;

// FUNCTIONS

// EVENTS
int ft_key_down(int keycode, t_data *d);
// INIT
void ft_init_vars(t_data *d);
void ft_init_img(t_img *img, void *mlx);
// RENDER
int ft_render_frame(t_data *d);
void ft_put_image(t_data *d);
void ft_cast_rays(t_data *d);
void	ft_draw_buffer(t_data *d, int buffer[1080][1920]);
void ft_draw_vertical_line(int x, int draw_start, int draw_end, int color, t_img *img);
void ft_draw_ceiling_and_floor(t_data *d);
// UTILS
void ft_my_mlx_pixel_put(t_img *data, int x, int y, int color);
int ft_create_trgb(int t, int r, int g, int b);
unsigned char	ft_get_t(int trgb);
unsigned char	ft_get_r(int trgb);
unsigned char	ft_get_g(int trgb);
unsigned char	ft_get_b(int trgb);


#endif