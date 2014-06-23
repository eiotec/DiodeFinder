DiodeFinder
===========
DiodeFinder is a C++/Qt application that captures video from a webcam and processes it in order to visualize objects on scene. By default, DiodeFinder looks for points of chosen color formed in triangles and calculates each object's position, rotation and dynamic speed. Additionally, DiodeFinder can visualize scene in 3D using DiodeVisualizer Java application.

<h2>How does it work</h2>
The purpose of the DiodeFinder application was to visualize robots on stage. Every robot is supposed to have three diodes formed in triangles at the top. Camera should be mounted above visualized stage so that all robots are visible. Then, user can choose diodes' color by clicking it on the left window. The user is also able to choose so called "Picking difference" - due to the fact that all colors are represented in HSL palette it is possible to define hue/saturation/lightness range.<br>
<img src="https://raw.githubusercontent.com/eiotec/DiodeFinder/master/Media/Picture1.png"><br>

<h2>Documentation</h2>

