#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>
#include "GeometricObject.h"
#include "Point.h"

namespace vra
{

class Polygon : public GeometricObject
{
 private:
    std::vector<Point>  m_tabPoint;

 public:
    Polygon();
    explicit Polygon(const std::vector<Point> tabPoint);

    Polygon &operator+=(const Point &point) override;

    Polygon &operator-=(const Point &point) override;

    Polygon &move(const int &dx, const int &dy) override;

    ~Polygon() = default;

    Polygon &addPoint(const Point &point);

    const std::vector<Point> getTabPoint() const;

};

bool    operator==(const Polygon &firstPolygon, const Polygon &secondPolygon);

}   //    namespace vra


#endif  //  POLYGON_H_
