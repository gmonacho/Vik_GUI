#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>
#include "Point.h"

namespace vra
{

class Polygon
{
 private:
    std::vector<Point>  m_tabPoint;

 public:
    Polygon();
    explicit Polygon(const std::vector<Point> tabPoint);

    Polygon &operator+=(const Point &point);

    Polygon &operator-=(const Point &point);

    ~Polygon() = default;

    Polygon &addPoint(const Point &point);

    const std::vector<Point> getTabPoint() const;

};

bool    operator==(const Polygon &firstPolygon, const Polygon &secondPolygon);

}   //    namespace vra


#endif  //  POLYGON_H_
