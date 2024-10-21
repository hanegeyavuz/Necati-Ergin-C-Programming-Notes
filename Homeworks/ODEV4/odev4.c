#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

/* strstr() functions implementation */

char *strstr_1(const char *hay, const char *needle)
{
	size_t needle_size = strlen(needle);
	while (*hay)
	{
		if (*hay == *needle)
		{
			needle++;
			if (*needle == '\0')
			{
				return (char *)(hay - needle_size + 1);
			}
		}
		hay++;
	}
	return NULL;
}