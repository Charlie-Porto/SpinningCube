#ifndef static_variables_cpp
#define static_variables_cpp


/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
purpose: to store static consts used in the project
-----------------------------------------------------------------*/

namespace global_const {

const int screen_x = 1000;
const int screen_y = 672;

const double meter_to_pixel_ratio = 0.5/8.4;
const double screen_height_meters = double(screen_y) * meter_to_pixel_ratio;
const double screen_width_meters = double(screen_x) * meter_to_pixel_ratio;

const double screen_zoom_ratio = 1.0;
const double pixel_angle_in_3space = .01;
const double pixel_stretch_ratio = 2.0;
const double distance_camera_to_viewplane = 1.0;
const double camera_inward_zoom_barrier = 40.0;

const double movement_speed = 20.0;
const double hop_angle = 1.0;

}


#endif /* static_variables_cpp */
