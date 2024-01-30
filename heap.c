

/* Heap


Priority Queue:
	aka 'Heap'

	binary tree where every child/grandchild is either smaller or larger than the parent (or ==)
		MaxHeap if larger
		MinHeap if smaller
	
	
	this is a 'weak ordering'
		it is ordered, but not specific down to every single point.

	
	ALSO: is always 'full' / never any gaps like with the BST	
		fills in left-to-right
		not necessarily balanced, just without holes

		so, have to do an insertion in a certain way.
	

insertion:
	go to 'final' spot in tree (does that mean we keep a reference to it?)
		(but the tail gets swapped with other things, so does the tail node need to know its the tail?)
	try to add a value
		if it is less than its parent, swap with parent (for maxheap. obvs 'greater' instead for MinHeap)
		repeat ^ until is at appropriate position

	Essentially just 'bubbles' up like bubble sort to insert at the right spot

!?	(good question asked by crowd): is this a doubly linked list then, to move up it like that?
		answer: sort-of (see below)
	

Deleting
	remember, there are no holes, so we need to fill it in properly when we delete:

	when deleting, fill-in the hole with the 'tail' of the tree
	THEN bubble-down just like we did upwards before

	When going down, ofc is different because there are potentially two viable paths, unlike upwards.
		so, prioritize the furthest-distance /aka/ greatest diff
			(aka, if MaxHeap, when going down choose the smallest)

! Tracking nodes, finding notes, etc

	the nodes are 'indexed' (in BFS order)
		AND heaps are implemented through an array, or usually ArrayList so can be growable.
	
	because are indexed, can calculate the children's indexes, or parent
		
		2*index + 1 = left parent
		2*index + 2 = right parent

		and parent is ceil(5/2.0) - 1
			(this was the way I found the equation)
			OR:
		and parent is floor((5-1)/2)
	
	THEN: keep length

Updating:
	much more complicated
		(hes talking abt it like its different than just deleting then inserting. Must be some way to reduce the amt of steps needed?)
	
	sidenoted / not the focus

now, for implementing! Imma do this one fr fr.


*/ 
