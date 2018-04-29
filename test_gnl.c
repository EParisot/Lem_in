#include <stdlib.h>
#include <stdio.h>
#include "GNL/get_next_line.h"

int main(void)
{
	char		**line;

	if (!(line = (char **)malloc(sizeof(char *))))
		return (0);
	while (get_next_line(0, line) > 0)
	{
		printf("%s\n", *line);
		free(*line);
	}
	free(*line);
	free(line);
	return 0;
}
