#include <stdio.h>
#include <stdlib.h>

void unrecursive_quicksort_pivL(int* nums, int numc) {

	int* passedNums = nums + numc;
	
	

}

int main(int argc, char** argv) {

	int nums[] = {7,6,8,4,5,3,2};
	int numc = sizeof(nums)/sizeof(int);

	unrecursive_quicksort_pivL(nums, numc);


	for (int i = 0; i < numc+1; i++) {
		printf("%d, ", nums[i]);
	}


	return 0;
}
