#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {23, 56, 78, 23, 26, 25};
	char *names[] = {"Alan", "Frank", "Mary", "John", "Kaetlyn", "Jack"};

	// safely get the size of ages
	//printf("%ld", sizeof(ages));
	//printf("%ld", sizeof(int));

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for(i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	// setup the pointers to the start of the array
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\n", *(cur_name+i), *(cur_age+i));
	}

	printf("---\n");
	
	// third way, pointers are just arrays
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
			
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}
