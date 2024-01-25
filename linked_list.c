
#include <stdio.h>
#include <stdlib.h>

/*

linked list aka node-based datastructure


my prior understanding
	each element in the list consists of the data of that element + a pointer to the next element in the array

	I dont know if you have another pointer to go backwards?

	Advantages are it can be spread out through storage, rather than needing to be subsequent like arrays
		easier to add elements

	but harder to get the length
	
singly-linked list
	only points forwards

	? or backwards?
		oh wait, that would just be the forwards then.
	
doubly-linked list
	points both directions

//im going to need to use malloc and free for this, I believe


Time complexity
	
	inserting in a linked list is O(1) because constant num of actions to insert regardless of length of list
		and deleting

		except, because indexing is slower, deleting from middle can be more difficult since you need to traverse to the middle first. Same with inserting in the middle

		but deleting from the front/back is really fast, which is a common use-case for lists

	but indexing is much slower, since its not O(1) anymore

graphs
	linked lists are all technically graphs/trees, just with no branches



Returning: arrays vs lists
	
	arrays
		0(1) for indexing values in it
		simple implementation & understanding
		not really 'inserting', just writing. 
			expensive to shift or truly insert values
	
		you allocate memory up-front
			easier to access, performance wise, since allocated already, prepared
			stricter

	linked list
		use less memory

		difficult to index the list / always O(n) time
			if scanning lists or indexing, rarely want a linked list

	`

*/
