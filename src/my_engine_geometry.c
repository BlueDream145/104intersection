/*
** EPITECH PROJECT, 2017
** my_engine_geometry.c
** File description:
**
*/

#include "intersection.h"

void process_geometry(struct request *request, double a, double b,
	double delta)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";

	if (delta < 0)
		request->intersection_len = 0;
	if (delta == 0) {
		request->intersection_len = 1;
		request->intersections = malloc(sizeof(struct coordinates));
		if (request->intersections == NULL)
			report_error(error_malloc);
		process_intersection(request, (-b / (2 * a)), 0);
	}
	if (delta > 0) {
		request->intersection_len = 2;
		request->intersections = malloc(sizeof(struct coordinates)
		* 2);
		if (request->intersections == NULL)
			report_error(error_malloc);
		process_intersection(request, (-b + sqrt(delta)) / (2 * a), 0);
		process_intersection(request, (-b - sqrt(delta)) / (2 * a), 1);
	}
}

void process_intersection(struct request *request, double x, int i)
{
	request->intersections[i] = get_single_coordinates(
	request->point->x + (x * request->directeur->x),
	request->point->y + (x * request->directeur->y),
	request->point->z + (x * request->directeur->z));
}

void process_sphere(struct request *request)
{
	double a = pow(request->directeur->x, 2) +
	pow(request->directeur->y, 2) +
	pow(request->directeur->z, 2);
	double b = (2 * request->point->x * request->directeur->x) +
	(2 * request->point->y * request->directeur->y) +
	(2 * request->point->z * request->directeur->z);
	double c = pow(request->point->x, 2) +
	pow(request->point->y, 2) + pow(request->point->z, 2) -
	pow(request->radius, 2);
	double delta = pow(b, 2) - 4 * a * c;

	process_geometry(request, a, b, delta);
}

void process_cylinder(struct request *request)
{
	double a = pow(request->directeur->x, 2) +
	pow(request->directeur->y, 2);
	double b = (2 * request->point->x * request->directeur->x) +
	(2 * request->point->y * request->directeur->y);
	double c = pow(request->point->x, 2) +
	pow(request->point->y, 2) - pow(request->radius, 2);
	double delta = pow(b, 2) - 4 * a * c;

	process_geometry(request, a, b, delta);
}

void process_cone(struct request *request)
{
	double angle = (request->radius * M_PI) / 180;
	double a = pow(request->directeur->x, 2) +
	pow(request->directeur->y, 2) -
	(pow(request->directeur->z, 2) / pow(tan(angle), 2));
	double b = (2 * request->point->x * request->directeur->x) +
	(2 * request->point->y * request->directeur->y) -
	((2 * request->point->z * request->directeur->z) /
	pow(tan(angle), 2));
	double c = pow(request->point->x, 2) + pow(request->point->y, 2)
	- (pow(request->point->z, 2) / pow(tan(angle), 2));
	double delta = pow(b, 2) - 4 * a * c;

	process_geometry(request, a, b, delta);
}