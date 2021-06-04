#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <rice/rice.hpp>

using namespace Rice;
using namespace boost::geometry;
using namespace std;

double area_of_intersection(Object self, String wkt_poly1, String wkt_poly2) {
    typedef model::polygon<model::d2::point_xy<double> > polygon;

    string std_str_poly1 = wkt_poly1.str();
    string std_str_poly2 = wkt_poly2.str();
    double intersection_area;
    deque<polygon> intersection_deque;

    polygon poly1, poly2;

    read_wkt(std_str_poly1, poly1);
    read_wkt(std_str_poly2, poly2);

    intersection(poly1, poly2, intersection_deque);

    for (int i = 0; i < intersection_deque.size(); i++) {
        intersection_area += area(intersection_deque[i]);
    }

    return intersection_area;
}

extern "C"

void Init_vtslv()
{
  Class rb_cTest =
    define_class("VTSLV")
    .define_singleton_method("area_of_intersection", &area_of_intersection, Arg("wkt_poly1"), Arg("wkt_poly2"));
}
