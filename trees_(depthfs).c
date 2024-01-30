

/*
Trees

where are trees?
	filesystem, forex
	html 'dom'
	Compilers have 'Abstract Syntax tree'
	many more

https://frontendmasters.com/courses/algorithms/trees-overview/

like a 1-directional linked list, but instead of 1 'next' value, there is an array of possible 'next' values
	(branches)


"root" - the origin point / top of tree

"height" - count from root to longest/furthest point / even if only a single branch is much higher

binary trees - has at max 2 children, rather than unlimited amt
	often 'left' and 'right' instead of array of children

"general tree" - 0+ children (default)

"binary search tree" - binary tree with specic ordering to the nodes

'leaves' - nodes without children

'balanced' - perfectly balanced when any node's left and right children have the same height

'branching factor' - amt of children a tree has 
	as in, per node. Binary tree has branching factor of two.


recursion is extremely common and handy for trees

traversal:
	1. visit node
	2. recurse


	3 types of traversals (?for binary trees) <- NO, not just for binary trees. Just illustrated easily via binary trees
		pre-order traversal
			visit, then recurse both

			root will be the first/beginning of process

		in-order traversal
			recurse to 1 side, then visit, then recurse

			root will be in the center of the process

		
			this is a bit funky with non-binary trees, though

		post-order travel
			recurse both, then visit 

			root will be at end of process
		
		(for these^, think of as priority/ordering. Visual examples from video help toohttps://frontendmasters.com/courses/algorithms/tree-traversals/: )



What is the running time (bigO)
	the 'input' is the entire tree

	traversing in these ways is O(n) linear
	

Implementation
	Trees are really just branching linked lists.

	(hard to do these implementations since his test/sample code is in TS)

	traversal is built off a stack, of course, cuz recursion

	recall recursion parts: pre,recurse, post

		makes sense with traversal types
	
	typically, you traverse left->right. Doesnt really matter, but is easier for ppl to understand generally

	
So far, these were all DEPTH-FIRST TRAVERSALS
	they go as deep as possible first (depth first), then back upwards / they prioritize depth

	we used a 'stack' for depth-first search / (yeah, because of the recursion obv)

*/
