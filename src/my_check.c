/*
** EPITECH PROJECT, 2017
** my_check.c
** File description:
**
*/

#include "intersection.h"

void check(int ac, char **as)
{
	const char *error_usage = "Bad usage.\n";
	const char *error_syntax = "Bad syntax.\n";

	if (ac != 9)
		report_error(error_usage);
	if (as[1][0] != '1' && as[1][0] != '2' && as[1][0] != '3')
		report_error(error_syntax);
	if ((as[1][0] == '1' || as[1][0] == '2') && atof(as[8]) <= 0)
		report_error(error_usage);
	else if (as[1][0] == '3' && (atof(as[8]) < 0 || atof(as[8]) > 360))
		report_error(error_usage);
	if (atof(as[5]) == 0 && atof(as[6]) == 0)
		report_error(error_usage);
	for (int i = 2; i < ac; i++)
		check_number(as[i]);
}

void check_number(char *param)
{
	const char *error_syntax = "Bad syntax.\n";
	int len = strlen(param);

	for (int i = 0; i < len; i++)
		if (!(param[i] >= '0' && param[i] <= '9') && param[i] != ' ' &&
			param[i] != '.' && param[i] != '-')
			report_error(error_syntax);
}