#include "stableobject.h"


using namespace std;
using namespace cv;


StableObject::StableObject()
{
    speed = 0;
}


StableObject::StableObject(SceneObject sceneObject) {
    this->sceneObject = sceneObject;
    StableObject();
}
