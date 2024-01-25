


/*

Say you have array like [000111]
	trying to find the point at which it changes from 0->1, or the first 1

	binary search will find a random 1, meaning you have to walk at some point to find point of change
		so is just o(n)
	
	linear will find it, but is alos o(n)


	instead, jump forwards by sqrt(n)
		meaning O(sqrtN)

		// the sqrt is not considered a constant just like how o(n*n) would work, ofc

		are stepping forwards in intervals of sqrt(n), then at most you have to walk sqrt(n) when you find a point where it changes
	

! Must assume array is large enough to have a square root.


https://frontendmasters.com/courses/algorithms/two-crystal-balls-problem/
*/
