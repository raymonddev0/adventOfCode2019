// #define PART2 // uncomment this line for PART2 solution
#include <stdio.h> // for fs and printf
#include <stdlib.h> // for free(), atoi()
#include <string.h> // for strtok()

int computeFuel(int mass)
{
	#ifdef PART2
	int interimFuel = 0;

	if (mass <= 0)
		return 0;
	else
	{
		interimFuel = mass/3 - 2;
		if (interimFuel < 0) interimFuel = 0;
	}

	return interimFuel + computeFuel(interimFuel);
	#endif

	#ifndef PART2
	return mass/3 - 2;
	#endif
}

int main(int argc, char const *argv[])
{
	FILE* fileStream = NULL;
	int totalFuel = 0;

	// to open the file
	fileStream = fopen("data.txt", "r");
	if (fileStream == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}	

	/* set buffer and size to 0; they will be changed by getline */
	char *buffer = NULL;
	size_t size = 0;

	ssize_t chars = 0;

	while (!feof(fileStream))
	{
		// ssize_t getline(char **lineptr, size_t *n, FILE *stream);
		chars = getline(&buffer, &size, fileStream);

		// Discard newline character if it is present,
		if (chars > 0 && buffer[chars-1] == '\n') 
		    buffer[chars-1] = '\0';

		// computation of fuel requirements
		totalFuel += computeFuel(atoi(buffer));
				
		// iterate through fileStream and buffer will realloc where necessary
	}

	// free the buffer
	free(buffer);

	// to close the file
	fclose(fileStream);

	printf("sum of fuel requirements: %d\n", totalFuel);

	return 0;
}