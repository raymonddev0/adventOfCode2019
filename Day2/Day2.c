// #define PART2 // uncomment this line for PART2 solution
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int opcode = 0;
	int param1 = 0;
	int param2 = 0;

	#ifdef PART2
	int noun = 0;
	int verb = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int Intcode[] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,9,19,1,13,19,23,2,23,9,27,1,6,27,31,2,10,31,35,1,6,35,39,2,9,39,43,1,5,43,47,2,47,13,51,2,51,10,55,1,55,5,59,1,59,9,63,1,63,9,67,2,6,67,71,1,5,71,75,1,75,6,79,1,6,79,83,1,83,9,87,2,87,10,91,2,91,10,95,1,95,5,99,1,99,13,103,2,103,9,107,1,6,107,111,1,111,5,115,1,115,2,119,1,5,119,0,99,2,0,14,0};
			Intcode[1] = i;
			Intcode[2] = j;
	#endif
			#ifndef PART2
			// restore to original state
			int Intcode[] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,9,19,1,13,19,23,2,23,9,27,1,6,27,31,2,10,31,35,1,6,35,39,2,9,39,43,1,5,43,47,2,47,13,51,2,51,10,55,1,55,5,59,1,59,9,63,1,63,9,67,2,6,67,71,1,5,71,75,1,75,6,79,1,6,79,83,1,83,9,87,2,87,10,91,2,91,10,95,1,95,5,99,1,99,13,103,2,103,9,107,1,6,107,111,1,111,5,115,1,115,2,119,1,5,119,0,99,2,0,14,0};
			Intcode[1] = 12;
			Intcode[2] = 2;
			#endif

			int index = 0;
			while (*(Intcode + index) != 99)
			{
				opcode = *(Intcode + index);
				param1 = Intcode[*(Intcode + index + 1)];
				param2 = Intcode[*(Intcode + index + 2)];
				
				if (opcode == 1)
					Intcode[*(Intcode + index + 3)] = param1 + param2;
				else if (opcode == 2)
					Intcode[*(Intcode + index + 3)] = param1 * param2;
				index += 4;
			}

	#ifdef PART2
			if (Intcode[0] == 19690720)
			{
				noun = i;
				verb = j;
				printf("100 * noun + verb: %d\n", 100*noun+verb);
				goto exit;
			}
		}
	}
	#endif

	#ifndef PART2
	printf("value at position 0: %d\n", Intcode[0]);
	#endif

	exit:
	return 0;
}