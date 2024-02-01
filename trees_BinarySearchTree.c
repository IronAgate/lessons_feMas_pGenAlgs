
/* Binary search tree

is a binary tree which is sorted according to 1 rule:
	everything to the left of EVERY node is less than that node
	everything to the right of EVERY node is greater than

	(I presume == doesnt rly matter here?
		he says there are some niche cases where one or the other matters, but we will keep it simple here
		default to <= and >, but sometimes might want both to be ||==
	
	Can _always_ insert in a way so that it stays sorted / same with removal / so dont need to sort it before use, because it is inherently sorted

	*tree will not necessarily be balanced

Creating a binary search tree resembles quicksort. Searching through a binary search tree resembles Binary Search Alg from earlier
	often, these are easier to implement via a tree than an array, especially the BSalg

Use cases of BStree:
	
	decent search performance + growable datastructure


Time Complexity:
	Might think its O(logn) like the binary search alg, but is not.

	search is O(h) where h == height, rather than n==len/num

		depends on how balanced the tree is / can be anywhere from O(logn) to O(n), depending on that height
		
		tree-balancing methods is an entire other topic / he mentions offhand:
			red-black trees
			AVL
			
			these are algs which rotate/reorganize the tree to try to balance it better / do it when inserting (at least in the case he mentioned? it was a sidenote.)
	
	this vs binary search alg on array
		w/ array, is harder to implement, insert, and keep sorted. 
			BUT, will be O(logN) because is always perfectly balanced
		w/ BST, is easier to implement (if more overhead) and mutate as you go, plus it stays sorted.
			BUT will be O(logN) - O(n) depending on height since not always balanced


Navigating:
	Check if > or < than node, move down to children accordingly
	check if == the new node you are on, ofc

Inserting:
	Navigate (^) to value that is lesser than self, where its 'greater' child is >= self / insert btwn them, like linked list
	
	& dont forget you need to handle null/leaf cases

deleting:
	navigate to value to delete / delete and reconnect nodes / but can be complicated cuz there may be 2 children but only 1 reconnection point

	Cases:
		1. no children => just delete
		2. 1 child => delete & reconnect to that 1 child
		3. 2 children => 
			This is the complicated one

			Initial thought was to delete, connect childA, connect childB to childA / BUT this doesnt work if childA already has children, of course. Instead:

			have to take childB & insert it (with its children) somewhere down childA, where appropriate

				(in example, am referring to childA as lesser/left and childB as greater/right / will discuss later)
				and can always just go all the way down, since childA will never have anything greater|== t childB
		
			Choosing which child is A/B: greater/lesser:
				Why does it matter?
						may try to limit height of tree if you are storing data abt the height elsewhere
!!							(interesting. Want to go through this sometime.)




* Can order trees by other things than >< / these may be weaker or stronger sorts??
	dont fullyunderstand, was another sidenote


*/
