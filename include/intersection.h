/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef intersection_
#define intersection_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

struct request {
	int option;
	int intersection_len;
	struct coordinates *point;
	struct coordinates *directeur;
	struct coordinates *intersections;
	double radius;
};

struct coordinates {
	double x;
	double y;
	double z;
};

// main.c
void dispose(struct request *request);

// my_check.c
void check(int ac, char **as);
void check_number(char *param);

// my_engine_geometry.c
void process_sphere(struct request *request);
void process_cylinder(struct request *request);
void process_cone(struct request *request);
void process_geometry(struct request *request, double a, double b,
	double delta);
void process_intersection(struct request *request, double x, int i);

// my_engine.c
struct request *serialize(char **as);
void process(struct request *request);
void display(struct request *request);

// my_get.c
struct request * get_request(int opt, struct coordinates *coord1,
struct coordinates *coord2, double radius);
struct coordinates *get_coordinates(double x, double y, double z);
struct coordinates get_single_coordinates(double x, double y, double z);

// my_put.c
void my_put_option(struct request *request);
void my_put_intersection(struct request *request);
void my_put_coordinates(struct coordinates *coord, int decimal);
void my_put_coordinates_intersection(struct coordinates inter, int decimal);

// my_report.c
void report_error(const char *str);

#endif /* intersection */