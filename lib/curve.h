/* Source : http://www.antigrain.com/research/adaptive_bezier/index.html */

#ifndef CURVE__H
#define CURVE__H 1

#include "point.h"

class curve
{
public:
  curve(const Point& p1, const Point& p2, const Point& p3);
  void init(double, double, double, double, double, double);
  void recursive_bezier(double, double, double, double, double, double, unsigned);
  void bezier(double, double, double, double, double, double);
};

curve::curve(const Point& p1, const Point& p2, const Point& p3) 
{
  init(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

//------------------------------------------------------------------------
void curve::init(double x1, double y1, 
                double x2, double y2, 
                double x3, double y3)
{
  m_points.remove_all();
  m_distance_tolerance = 0.5 / m_approximation_scale;
  m_distance_tolerance *= m_distance_tolerance;
  bezier(x1, y1, x2, y2, x3, y3);
  m_count = 0;
}


//------------------------------------------------------------------------
void curve::recursive_bezier(double x1, double y1, 
                            double x2, double y2, 
                            double x3, double y3,
                            unsigned level)
{
  if(level > curve_recursion_limit) 
  {
    return;
  }

  // Calculate all the mid-points of the line segments
  //----------------------
  double x12   = (x1 + x2) / 2;                
  double y12   = (y1 + y2) / 2;
  double x23   = (x2 + x3) / 2;
  double y23   = (y2 + y3) / 2;
  double x123  = (x12 + x23) / 2;
  double y123  = (y12 + y23) / 2;

  double dx = x3-x1;
  double dy = y3-y1;
  double d = fabs(((x2 - x3) * dy - (y2 - y3) * dx));

  if(d > curve_collinearity_epsilon)
  { 
    // Regular care
    //-----------------
    if(d * d <= m_distance_tolerance * (dx*dx + dy*dy))
    {
      // If the curvature doesn't exceed the distance_tolerance value
      // we tend to finish subdivisions.
      //----------------------
      if(m_angle_tolerance < curve_angle_tolerance_epsilon)
      {
        m_points.add(point_type(x123, y123));
        return;
      }

      // Angle & Cusp Condition
      //----------------------
      double da = fabs(atan2(y3 - y2, x3 - x2) - atan2(y2 - y1, x2 - x1));
      if(da >= pi) da = 2*pi - da;

      if(da < m_angle_tolerance)
      {
        // Finally we can stop the recursion
        //----------------------
        m_points.add(point_type(x123, y123));
        return;                 
      }
    }
  }
  else
  {
    // Collinear case
    //-----------------
    dx = x123 - (x1 + x3) / 2;
    dy = y123 - (y1 + y3) / 2;
    if(dx*dx + dy*dy <= m_distance_tolerance)
    {
      m_points.add(point_type(x123, y123));
      return;
    }
  }

  // Continue subdivision
  //----------------------
  recursive_bezier(x1, y1, x12, y12, x123, y123, level + 1); 
  recursive_bezier(x123, y123, x23, y23, x3, y3, level + 1); 
}

//------------------------------------------------------------------------
void curve::bezier(double x1, double y1, 
                  double x2, double y2, 
                  double x3, double y3)
{
  m_points.add(point_type(x1, y1));
  recursive_bezier(x1, y1, x2, y2, x3, y3, 0);
  m_points.add(point_type(x3, y3));
}

#endif