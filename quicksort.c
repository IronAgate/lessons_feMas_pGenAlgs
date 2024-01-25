


#include <stdio.h>
#include <stdlib.h>


int partition(int *nums, int low, int hig) {
//qs often split this part out into its own function
	
//he showed to implement simpler version where pivot is just the last num

	int pivot = nums[hig];
	
	int idx = low - 1;
	int buffer = 0;
	
	for (int i = low; i < hig; ++i) {
		if (nums[i] <= pivot) {
			idx++;
			buffer = nums[i];
			nums[i] = nums[idx];
			nums[idx] = buffer;
		}
	}

	idx++;
	nums[hig] = nums[idx];
	nums[idx] = pivot;

	return idx;
}

void quickSort(int *nums, int low, int hig) {
	
	if (low >= hig) {
		return;
	}
	
	int pivot = partition(nums, low, hig);

	quickSort(nums, low, pivot - 1);
	quickSort(nums, pivot + 1, hig);

}


int main(int argc, char** argv) {

	int nums[] = {1,5,7,21,4,78,2,5};
	int numc = sizeof(nums)/sizeof(int);


	quickSort(nums, 0, numc - 1);

	printf("c: %d\n\n", numc);
	for (int i = 0; i < numc; ++i) {
		
		printf("%d, ", nums[i]);

	}

	return 0;
}


/*
quicksort
//finallyyy

https://frontendmasters.com/courses/algorithms/quicksort-algorithm/


how quicksort works
	
	pick an initial index, often known as 'p' or 'pivot'

	Then, take two indexes/ptrs

		ptr1 sits at the beginning of the array to hold that position for later

		ptr2 walks through the array
			any value < pivot is placed at the beginning of the array (using the above ptr)
				(and incrementing the earlier ptr too)

			any value > pivot is placed after the pivot
		

		After this is done, pivot will be in the middle. the upper half is greater than pivot, and lower is less than
				NO! Pivot is NOT in middle. You move the pivot to be at the next ptr1 position, meaning all the nums beneath it are lower. 
			this is known as a 'weak sort'
				//is weak-sort specific to this configuration, or a class of sorting-types that are all weak?


		Then, repeat the process twice, for each side of the pivot UNTIL
			UNTIL you have an array of len(1), which is always sorted

			as in, you keep repeating it

	
	//how do you pick a pivot?



time complexity
	O(nlogn) 

	see 10:00ish //i dont rly get it


	slowest possible case is trying to sort a reverse-sorted array
		in which case it is O(n**2)

		AND picking the last element

		to mitigate, can always pick the middle of the array as the pivot


	he is comparing to merge sort, which I dont really know.
		from what I understand it creates new arrays, so isnt 0(1) space

		he says merge sort is always O(logn) time, but there is more overhead/larger constants so can often be slower



*/
