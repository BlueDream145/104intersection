/*
** EPITECH PROJECT, 2017
** my_put.c
** File description:
**
*/

#include "intersection.h"

void my_put_option(struct request *request)
{
	if (request->option == 1)
		printf("sphere of radius %.0f\n", request->radius);
	else if (request->option == 2)
		printf("cylinder of radius %.0f\n", request->radius);
	else
		printf("cone of %.0f degree angle\n", request->radius);
}

void my_put_intersection(struct request *request)
{
	int i;

	for (i = 0; i < request->intersection_len; i++) {
		my_put_coordinates_intersection(request->intersections[i], 1);
		printf("\n");
	}
}

void my_put_coordinates(struct coordinates *coord, int decimal)
{
	if (decimal == 0)
		printf("(%.0f,%.0f,%.0f)", coord->x, coord->y, coord->z);
	else
		printf("(%.3f, %.3f, %.3f)", coord->x, coord->y, coord->z);
}

void my_put_coordinates_intersection(struct coordinates inter, int decimal)
{
	if (decimal == 0)
		printf("(%.0f,%.0f,%.0f)", inter.x, inter.y, inter.z);
	else
		printf("(%.3f, %.3f, %.3f)", inter.x, inter.y, inter.z);
}