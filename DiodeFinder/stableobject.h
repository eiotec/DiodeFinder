#ifndef STABLEOBJECT_H
#define STABLEOBJECT_H


#include "sceneobject.h"


using namespace std;
using namespace cv;

/**
 * @brief The StableObject class. Container for scene objects that has been recognized as stable (filtered).
 */
class StableObject
{
    public:


        /** @brief Standard scene object. */
        SceneObject sceneObject;

        /** @brief Current speed. */
        float speed;


        /**
         * @brief Empty constructor.
         */
        StableObject();

        /**
         * @brief Standard constructor.
         * @param sceneObject Standard scene object.
         */
        StableObject(SceneObject sceneObject);

};

#endif // STABLEOBJECT_H
