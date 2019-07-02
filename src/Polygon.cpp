#include "Polygon.h"

namespace vra
{

Polygon::Polygon() : m_tabPoint() {}

Polygon::Polygon(const std::vector<Point> tabPoint) :
                 m_tabPoint(tabPoint) {}


Polygon &Polygon::operator+=(const Point &point)
{
    for (Point &p : m_tabPoint)
        p += point;
    return (*this);
}

Polygon &Polygon::operator-=(const Point &point)
{
    for (Point &p : m_tabPoint)
        p -= point;
    return (*this);
}

Polygon &Polygon::move(const int &dx, const int &dy)
{
    for (Point &p : m_tabPoint)
        p.move(dx, dy);
    return (*this);
}

Polygon &Polygon::addPoint(const Point &point)
{
    m_tabPoint.push_back(point);
}


const std::vector<Point> Polygon::getTabPoint() const
{
    return (m_tabPoint);
}

bool    operator==(const Polygon &firstPolygon, const Polygon &secondPolygon)
{
    std::vector<Point> fTabPoint{firstPolygon.getTabPoint()};
    std::vector<Point> sTabPoint{secondPolygon.getTabPoint()};

    if (fTabPoint.size() != sTabPoint.size())
        return (false);
    for (int i{0}; i < fTabPoint.size(); i++)
    {
        if (fTabPoint[i] != sTabPoint[i])
            return (false);
    }
    return (true);
}

}   //  namespace vra
