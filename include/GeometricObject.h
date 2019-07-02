#ifndef GEOMETRICOBJECT_H_
#define GEOMETRICOBJECT_H_

namespace vra
{
class Point;

class GeometricObject
{
 public:
    virtual GeometricObject &operator+=(const vra::Point &point) = 0;
    virtual GeometricObject &operator-=(const vra::Point &point) = 0;

    virtual GeometricObject &move(const int &dx, const  int &dy) = 0;
};
}   //  namespace vra

#endif  //  GEOMETRICOBJECT_H_
