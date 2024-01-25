
#include <stdio.h>
#include <stdlib.h>


void my_bubbleSort(int *nums, int c) {
	//my implementation, try 1
	
	int buffer = 0;

	for (int i = 1; i < c; i++) { //I chose to set i = 1 instead of subtract +1 in the inner for loop

		for (int e = 0; e < c-i; e++) {
			
			if (nums[e] > nums[e+1]) {

				buffer = nums[e+1];
				nums[e+1] = nums[e];
				nums[e] = buffer;
			}

		}

	}

}

int main(int argc, char** argv) {
	
	int nums[] = {5,6,78,3,4,6,87};
	int c = sizeof(nums)/sizeof(int);

	my_bubbleSort(nums, c);

	for (int i = 0; i < c; ++i) {
		
		printf("%d, ", nums[i]);

	}

	return 0;
}


/*
very simple sorting alg

mathematical definition of a sorted array:
	X[i] <= X[i+1]


starts in posiiton 0, and moves to the end
	says: if [i] > [i+1], swap

	has to iterate multiple times

	1st iteration will always move the largest item to the end of the array

		so next time, dont have to iterate all the way to that point
	
	
	time complexity
		
		https://frontendmasters.com/courses/algorithms/bubble-sort/

		(N(n+1))/2

			n**2 + n
			
			^this becomes

			O(n**2)

			because you drop 'insignificant' values, since n**2 is so impactful


so, bubblesort is slow but simple.

*/
