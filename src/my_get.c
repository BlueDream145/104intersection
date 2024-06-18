/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "intersection.h"

struct request * get_request(int opt, struct coordinates *coord1,
struct coordinates *coord2, double radius)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	struct request *request = malloc(sizeof(struct request));

	if (request == NULL)
		report_error(error_malloc);
	request->option = opt;
	request->point = coord1;
	request->directeur = coord2;
	request->radius = radius;
	request->intersection_len = 0;
	return (request);
}

struct coordinates *get_coordinates(double x, double y, double z)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	struct coordinates *coord = malloc(sizeof(struct coordinates));

	if (coord == NULL)
		report_error(error_malloc);
	coord->x = x;
	coord->y = y;
	coord->z = z;
	return (coord);
}

struct coordinates get_single_coordinates(double x, double y, double z)
{
	struct coordinates coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}