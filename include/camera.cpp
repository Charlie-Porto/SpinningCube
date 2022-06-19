#ifndef camera_cpp
#define camera_cpp

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp> 

struct Camera {
  glm::dvec3 location_vec3;
  glm::dvec3 pov_unitvec3;
  glm::dvec3 dov_unitvec3;
  glm::dvec3 focus_point; // in origin-focus mode, always the origin
  double pov_scalar;
  double xz_angle;
  double xz_circle_radius;
  double y_angle;
  double focus_distance;
  bool in_free_roam_mode;
  bool in_origin_focus_mode;
  glm::dquat rotation_versor;
};





#endif /* camera_cpp */
