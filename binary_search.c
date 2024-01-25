
#include <stdio.h>
#include <stdlib.h>

unsigned char my_binarySearch(int* nums, int c, int target) {
//my scuffed implementation, freehand
	//same issue as the one below, really, just messier
	int x = nums[c/2];

	while (x != target) {
		
		if (c == x) {
			return 0;
		}

		if (x < target) {
			
			x += x/2;
			
			continue;
		}

		int temp = x - (c-x)/2;
		c = x;
		x = temp;

	}
	return (x == target);

}

int my2_binarySearch(int* nums, int c, int target) {
// my slightly better implementation, but still flawed
	//doing it this way I am not correcting for rounding/flooring in division, so eventually c/x are 1 away and stuck infinite loop
	int x = c/2;
	
	int temp = 0;

	while (x < c) {
		printf("%d, %d\n", x, c);
		if (nums[x] == target) {
			return x;
		}

		if (target < nums[x]) {
			temp = x;
			x -= (c-x)/2;
			c = temp;
			continue;
		}
		x += (c-x)/2;

	}
	return (x == target);
}

int binarySearch(int* nums, int c, int target) {
//implementation closely following the example
	
	int h = c;
	int l = 0;
	int m = 0;

	while (l < h) {
		m = l + (h-l)/2;
		
		if (nums[m] == target) {
			return m;
		}

		if (target < nums[m]) {
			h = m;
			continue;
		}

		l = m + 1;

	}
	
	return (m < c/2)? -1 : -2;
}

int main(int argc, char** argv) {

	int nums[] = {1,1,1,2,2,3,3,4,4,4,5,5,6,6,7,7,7,8,8,9};
	int c = sizeof(nums)/sizeof(int);
	
	printf("argv: %d", atoi(argv[1]));
	int found = binarySearch(nums, c, atoi(argv[1]));

	printf("\n%d\n", found);

	return 0;
}

/*

binary search requires a sorted algorithm

it halves the array repeatedly, and chooses to continue working with the half that will contain the value, based on the search

o(logN) <- Big 0 time complexity

	It doesnt actually 'walk' through the array at any point. It just lands on middle value, checks if is target, then halves and continues.

https://frontendmasters.com/courses/algorithms/binary-search-algorithm/
*/
