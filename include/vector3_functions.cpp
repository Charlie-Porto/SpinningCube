#ifndef vector3_functions_cpp
#define vector3_functions_cpp


/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions for vector3s, straight out the math book
-----------------------------------------------------------------*/

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/geometric.hpp>
#include <cmath>
#include <iostream>

#include "math_objects/Plane.cpp"
#include "math_objects/LineParamEq.cpp"
#include "math_objects/LineVectorForm.cpp"


namespace vfunc {

const double PI = 3.14159265;

double calculateMagnitude(glm::dvec3 v) {
  const double sq_x = pow(v.x, 2.0);
  const double sq_y = pow(v.y, 2.0);
  const double sq_z = pow(v.z, 2.0);
  const double sq_magnitude = sq_x + sq_y + sq_z;
  const double magnitude = sqrt(sq_magnitude);
  return magnitude;
}

double calculateDistanceBetweenPosition3Vectors(glm::dvec3 A, glm::dvec3 B) {
  const glm::dvec3 D = A - B;
  double distance = calculateMagnitude(D);
  return distance;
}

pce::math_objs::LineParametricEquation getLineThrough3dVectors(glm::dvec3 A, glm::dvec3 B) {
  const glm::dvec3 D = B - A;

  auto const line = pce::math_objs::LineParametricEquation{
    .x_coefficient=D.x,
    .y_coefficient=D.y,
    .z_coefficient=D.z,
    .x_constant=A.x,
    .y_constant=A.y,
    .z_constant=A.z,
  }; 
  return line;
}

pce::math_objs::LineVectorForm getVector3ThroughVector3s(glm::dvec3 A, glm::dvec3 B) {
  const glm::dvec3 line_direction = normalize(B - A);
  const glm::dvec3 line_origin = A;
  pce::math_objs::LineVectorForm vect;
  vect.origin = line_origin;
  vect.direction = line_direction;
  return vect;
}

glm::dvec3 getPointAtWhichLineIntersectsPlane(pce::math_objs::LineParametricEquation line, 
                                              pce::math_objs::Plane plane) {

  // first: find t
  const double xt = line.x_coefficient * plane.x;
  const double yt = line.y_coefficient * plane.y;
  const double zt = line.z_coefficient * plane.z;
  const double t_coefficient = xt + yt + zt;


  const double constant = -(
    line.x_constant * plane.x + 
    line.y_constant * plane.y + 
    line.z_constant * plane.z -
    plane.c
  );

  const double t = constant / t_coefficient;

  // find x, y, and z values using this t
  const double vx = line.x_coefficient * t + line.x_constant;
  const double vy = line.y_coefficient * t + line.y_constant;
  const double vz = line.z_coefficient * t + line.z_constant;

  return glm::dvec3(vx, vy, vz);
}

glm::dvec3 getPointWhereLineVFormIntersectsPlane(pce::math_objs::LineVectorForm line,
                                                 pce::math_objs::Plane plane) {
  const double t_coefficient = line.direction.x * plane.x
                             + line.direction.y * plane.y
                             + line.direction.z * plane.z;
  const double t_constant = -(line.origin.x * plane.x
                            + line.origin.y * plane.y
                            + line.origin.z * plane.z);
  const double t = t_constant / t_coefficient;
  return glm::dvec3(line.direction.x * t + line.origin.x,
                    line.direction.y * t + line.origin.y,
                    line.direction.z * t + line.origin.z);
}

std::vector<double> movePointAroundXZCircleByAngle(double new_angle,
                                                   double circle_radius) {
  const double new_z = circle_radius * cos(PI * new_angle/180.0);
  const double new_x = circle_radius * sin(PI * new_angle/180.0);

  std::vector<double> new_2d_pos = {new_z, new_x};
  return new_2d_pos;
}

double movePointAroundYCircleByAngle(double new_angle,
                                     double circle_radius) {
  const double new_y = circle_radius * sin(PI * new_angle/180.0);
  return new_y;
}


}




#endif /* vector3_functions_cpp */
