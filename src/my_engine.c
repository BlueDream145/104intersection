/*
** EPITECH PROJECT, 2017
** my_engine.c
** File description:
**
*/

#include "intersection.h"

struct request *serialize(char **as)
{
	int option = as[1][0] - '0';
	double radius = atof(as[8]);
	struct coordinates *cp = get_coordinates(
		atof(as[2]), atof(as[3]), atof(as[4]));
	struct coordinates *cv = get_coordinates(
		atof(as[5]), atof(as[6]), atof(as[7]));

	return (get_request(option, cp, cv, radius));
}

void process(struct request *request)
{
	if (request->option == 1)
		process_sphere(request);
	else if (request->option == 2)
		process_cylinder(request);
	else
		process_cone(request);
}

void display(struct request *request)
{
	my_put_option(request);
	printf("straight line going through the ");
	my_put_coordinates(request->point, 0);
	printf(" point and of direction vector ");
	my_put_coordinates(request->directeur, 0);
	printf("\n");
	if (request->intersection_len == 0)
		printf("No intersection point.");
	else if (request->intersection_len >= 99)
		printf("There is an infinite number of intersection points.");
	if (request->intersection_len == 1)
		printf("1 intersection point :");
	else if (request->intersection_len == 2)
		printf("2 intersection points :");
	printf("\n");
	my_put_intersection(request);
}