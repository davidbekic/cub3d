#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "./mlx/mlx.h"


// typedef struct	s_img {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_img;



// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

typedef struct s_data
{
    // int dir_x = 0;
    // int dir_y = 1;
    // double pos_x = 12;
    // double pos_y = 22;
    // double camera_plane_x = 0;
    // double camera_plane_y = .66;
    // int hit = 0;
    // int x;
    // double camera_x = 0;
    // double ray_dir_x = 0;
    // double ray_dir_y = 0;
    // int map_x = 0;
    // int map_y = 0;
    // char step_x = 0;
    // char step_y = 0;
    // char side = 0;
    // double side_dist_x = 0;
    // double side_dist_y = 0;
    // double delta_dist_x = 0;
    // double delta_dist_y = 0;
    // double perp_wall_dist = 0;
    // double time = clock(); //time of current frame
    // double old_time = 0; //time of previous frame
    // t_vars	vars;
    // t_img	img;
    int dir_x;
    int dir_y;
    double pos_x;
    double pos_y;
    double camera_plane_x;
    double camera_plane_y;
    int hit;
    int x;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    char step_x;
    char step_y;
    char side;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    double time; //time of current frame
    double old_time; //time of previous frame
    double moveSpeed; //the constant value is in squares/second
    double rotSpeed; //the constant value is in radians/second
}   t_data;

#endif