# 104intersection
Epitech Project, MATHS 104

Subject:

To code a software to create synthesis images (it may remind you something....), potential intersection points be-
tween light rays and scene objects (here cylinders, spheres and cones) must be computed.
This is exactly what you have to do.

To do so, you need to write a 3 dimensional equation of the straight line representing the light ray, and inject into it
the equation of the considered surface. You’ll get a quadratic equation, with 0, 1 or 2 solutions, that will give you the
intersection points coordinates (one do not take into account the possibility that the equation has an infinite number
of solutions here).

The straight line is defined by the coordinates of a point by which it goes through and by the coordinates of a direction
vector.
O being the origin of the coordinate system, and X, Y and Z the axis, the surfaces that has to be handled in this
project are :
1. O-centered spheres,
2. cylinders of revolution around Z axis,
3. cones of revolution around Z axis which apex is O.

Usage:

∼/B-MAT-100> ./104intersection opt xp yp zp xv yv zv p

opt             number of the option : 1 for a sphere, 2 for a cylinder, 3 for a cone
(xp, yp, zp)    coordinates of the point by which the light ray goes through
(xv, yv, zv)    coordinates of the direction vector of the light ray
p               radius of the sphere, radius of the cylinder or angle formed by the cone and the Z-axis.

Example:

![alt text](https://raw.githubusercontent.com/alexandre10044/104intersection/master/example.png)
