#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
	// If an error occurs
	if(errno)
	{
		//Print the supplied error message
		perror(message);
	} else {
		printf("ERROR: %s\n", message);	
	}	
	
	// Unsuccessful termination
	exit(1);
}

//a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	// Allocate a chunk of memory for however many arguments
	int *target = malloc(count * sizeof(int));

	// Make a copy of the array and specify memory a;location in bytes
	memcpy(target, numbers, count * sizeof(int));

	// While i is less than count
	for(i = 0; i < count; i++)
	{
		// While j is less thna count minus one
		for(j = 0; j < count -1; j++)
		{
			// If the comparison returns true
			if(cmp(target[j], target[j + 1]) >0)
			{
				//[3,  4,  5,  6]
				// |   |
				// j   j+1
      
				// Store index j + 1 in temp
				temp = target[j + 1];
				// item at index j up to j + 1
				target[j + 1] = target[j];
				// Set item at index j to temp(j + 1)
				target[j] = temp;
				//[4,  3,  5,  6]
				// |   |
				// j  j+1
			}	
		}
	}
	
	return target;
}

// Returns true if a is greater than b
int sorted_order(int a , int b)
{
	return a - b;
}

// Returns true if b is greater than a
int reverse_order(int a , int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	// a or b equals zero, return false
	if(a == 0 || b ==0)
	{
		return 0;
	} else {
		// Return the remainder of a divided by b
		return a % b;
	}
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out
 */

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	
	// If sorted is null or 
	if(!sorted) die("Failed to sort as requested");

	for(i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}

	printf("\n");
	
	// Free up memory
	free(sorted);
} 

int main(int argc, char *argv[])
{
	// There must be at least two arguments
	if(argc < 2) die("USAGE: ex18 4 3 1 5 6");
	
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	
	// Allocate memory
	int *numbers = malloc(count * sizeof(int));

	// Make sure the memory has been allocated
	if(!numbers) die("Memory error.");

	for(i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	return 0;
}
