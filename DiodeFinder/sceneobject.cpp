#include "sceneobject.h"

using namespace std;
using namespace cv;


SceneObject::SceneObject()
{
    size=rotation=0;
}


SceneObject::SceneObject(Point basePoint, Point shortPoint, Point longPoint) {
    this->basePoint = basePoint;
    this->shortPoint = shortPoint;
    this->longPoint = longPoint;
    rotation = calcRotation(this);
    size = calcSize(this);
}


float SceneObject::distance(Point *p1, Point *p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(pow(dx,2)+pow(dy,2));
}


float SceneObject::calcRotation(SceneObject *obj) {
    float dx = obj->longPoint.x - obj->basePoint.x;
    float dy = obj->longPoint.y - obj->basePoint.y;
    if (dx==0) dx = 0.001;
    float rot = 180*(atan(abs(dy)/abs(dx))/PI);
    if (dx>=0 && dy>=0) return rot;
    else if (dx<0 && dy>=0) return 180-rot;
    else if (dx<0 && dy<0) return 180+rot;
    else return 360-rot;
}


float SceneObject::calcSize(SceneObject *obj) {
    return distance(&(obj->basePoint), &(obj->longPoint));
}


float SceneObject::diff(SceneObject *obj1, SceneObject *obj2) {
    float dist = distance(&(obj1->basePoint), &(obj2->basePoint));
    float dRot = abs(obj1->rotation - obj2->rotation);
    return (dist*dRot);
}
