/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "intersection.h"

int main(int ac, char **as)
{
	struct request *request;

	check(ac, as);
	request = serialize(as);
	process(request);
	display(request);
	dispose(request);
	return (0);
}

void dispose(struct request *request)
{
	free(request->point);
	free(request->directeur);
	free(request->intersections);
	free(request);
}