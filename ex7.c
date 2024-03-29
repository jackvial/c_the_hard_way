#include <stdio.h>

int main(int argc, char *argv[])
{
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginery rate of %f.\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs .\n ", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("That is only a %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n", part_of_universe);

	// this makes no sense, just a demo of something wierd
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);

	char a_as_num = 'a';
	char b_as_num = 'b';
	
	int result  = b_as_num * a_as_num;
	printf("result of multiplying char a by char b= %d .\n\n", result);

	return 0;
}
