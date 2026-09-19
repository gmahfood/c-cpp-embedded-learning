// Point2D struct, warm-up
// Define struct Point2D { double x; double y; };
// Write make_point(double x, double y) -> Point2D
// Write distance(Point2D a, Point2D b) -> double   (straight-line distance)
// Write midpoint(Point2D a, Point2D b) -> Point2D
// Write print_point(Point2D p) -> void             (prints like "(1.00, 2.00)")
// In main: make two points, print both, print distance, print midpoint
// No pointers required for this one — pass structs by value

#include <iostream>
#include <cmath>

struct Point2D {
  double x;
  double y;
};

Point2D make_point(double x, double y) {
  Point2D p;
  p.x = x;
  p.y = y;
  return p;
}

double distance(Point2D a, Point2D b) {
  return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

double midpoint(Point2D a, Point2D b);

void print_point(Point2D p) {

}

int main() {
  
  return 0;
}
