#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <rice/rice.hpp>

using namespace Rice;

double are_of_intersection(Object self, String wkt_poly1, String wkt_poly2) {
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    std::string std_str_poly1 = wkt_poly1.str();
    std::string std_str_poly2 = wkt_poly2.str();
    double intersection_area;
    std::deque<polygon> intersection_deque;

    polygon poly1, poly2;

    boost::geometry::read_wkt(std_str_poly1, poly1);
    boost::geometry::read_wkt(std_str_poly2, poly2);

    boost::geometry::intersection(poly1, poly2, intersection_deque);

    for (int i = 0; i < intersection_deque.size(); i++) {
        intersection_area += boost::geometry::area(intersection_deque[i]);
    }

    return intersection_area;
}

extern "C"

void Init_vtslv()
{
  Class rb_cTest =
    define_class("VTSLV")
    .define_singleton_method("area_of_intersection", &are_of_intersection, Arg("wkt_poly1"), Arg("wkt_poly2"));
}
