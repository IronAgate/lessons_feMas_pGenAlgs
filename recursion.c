


/*

I dont like recursion, and was planning to skip this section (notes for it, that is. Not watching it ofc), but instructor mirrored my feelings towards it so imma give it a shot.

So far covered:
	functions are on a stack
	functions have returnAddress, returnValue, and args
	how recursion works, generally

	When building recursive function, VERY IMPORTANT to have a good understanding of the base case / fully flesh it out FIRST



Sometimes it seems to simple and why would you ever want to use it, so following will be an example of why you might genuinely want it or where it would be better
Maze Solver:
  https://frontendmasters.com/courses/algorithms/path-finding-base-case/


2d grid of a maze. has walls, start square, end square, empty (walkable) squares

our options are moving in any of the cardinal 4 directions //not diagonal ig
	
base case if recursing:
	when we cant move in a direction because:
	is a wall
	is already visited
	is off the map
	//and i forgot:
	ITS THE END!

function is:
	given the map
	symbol representing wall
	position of start
	position of end
	returns a list of points which lead to the end


recursive case
	pre-
		
	recurse
		
	post

//ngl still dont like recursion. This seems unnecessary. Just use a loop, you absolute jester.

hes saying this is a case where you cant easily use a for loop. Why? I guess I don't understand properly, but it seems like you could just use a for loop right? am I stupid?
https://frontendmasters.com/courses/algorithms/recursion-q-a/
	
	he explains more here

	I see. This is similar to one of my first projects, the 'randomly generated maze map' thing.
		I had to, like, add new tiles to a queue and go through that queue to do the next steps.
			(not a proper queue of course, I suck)
		With this recursion, it would automatically do that using the built-in function stack datastructure, so you dont have to write that in yourself
	

!!	I want to try to solve this problem without using recursion to try and understand better why the recursion may be easier


Time complexity

	its O(4n)

	or just O(n)

	since you check each 'n' or tile/position 4 times at most

*/
