#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <iostream>
#include <math.h>
#include <opencv2/core/core.hpp>


#define PI  3.14159265359


using namespace std;
using namespace cv;


/**
 * @brief The SceneObject class. It's a container for objects found on scene, based on filtered diodes.
 */
class SceneObject
{
    public:

        /** @brief Base point of the triangle. */
        Point basePoint;

        /** @brief Point near to basePoint. */
        Point longPoint;

        /** @brief Point far from basePoint. */
        Point shortPoint;

        /** @brief Calculated rotation. */
        float rotation;

        /** @brief Size of the object based on distance between points. */
        float size;


        /** @brief Empty constructor. */
        SceneObject();

        /**
         * @brief Constructor.
         * @param basePoint Base point of the triangle.
         * @param shortPoint Point near to basePoint.
         * @param longPoint Point far from basePoint.
         */
        SceneObject(Point basePoint, Point shortPoint, Point longPoint);



        /* STATIC METHODS */


        /**
         * @brief Calculate distance between points.
         * @param p1
         * @param p2
         * @return
         */
        static float distance(Point *p1, Point *p2);


        /**
         * @brief Calculate SceneObject's rotation.
         * @param obj
         * @return
         */
        static float calcRotation(SceneObject *obj);


        /**
         * @brief Calculate SceneObject's size.
         * @param obj
         * @return
         */
        static float calcSize(SceneObject *obj);


        /**
         * @brief Calculates difference between given objects.
         * @param obj1
         * @param obj2
         * @return
         */
        static float diff(SceneObject *obj1, SceneObject *obj2);

};

#endif // SCENEOBJECT_H
