
#include <stdio.h>
#include <stdlib.h>


typedef struct MinHeapT {

	int length;
	int maxLength; //next time, dont name this with 'length' cuz i got them mixed up a couple times
	int *nums;

} MinHeap;

void MinHeap_print(MinHeap *self) {
	for (int i = 0; i < self->length; ++i) {
		printf("%d, ", self->nums[i]);
	}
	printf("\nSpace: %d/%d\n", self->length, self->maxLength);
}

MinHeap MinHeap_initiate(int maxLength) {
	MinHeap self;
	self.length = 0;
	self.maxLength = maxLength;
	self.nums = malloc(sizeof(int)*maxLength);
	return self;
}
void MinHeap_destroy(MinHeap *self) {
	free(self->nums);
}

void MinHeap_swap(MinHeap *self, int idx1, int idx2) {
	int buffer = self->nums[idx2];
	self->nums[idx2] = self->nums[idx1];
	self->nums[idx1] = buffer;
}

int MinHeap_getParentIdx(int child) {
	return (child-1)/2; //would I want to unify with getChildIdx so it returns -1 when 'child' param is 0? Cuz right now just returns 0 again
}
int MinHeap_getChildIdx(int parent, unsigned char side) { //1 = left, 2 = right
	return parent*2 + side; //was going to validate within length here and return -1 if past, but better to do that wherever this is called cuz otherwise have to pass MinHeap ptr and still have to validate later for -1 anyways
}

int MinHeap_bubbleUp(MinHeap *self, int bub) {
	if (!bub) {
		return bub;
	}
	int parentIndex = MinHeap_getParentIdx(bub);
	if (self->nums[bub] <= self->nums[parentIndex]) {
		return bub;
	}
	MinHeap_swap(self, bub, parentIndex);
	return MinHeap_bubbleUp(self, parentIndex);
}

int MinHeap_insert(MinHeap *self, int value) {
	if (self->length >= self->maxLength) {
		return -1;
	}

	self->nums[self->length] = value;
	self->length++;

	return MinHeap_bubbleUp(self, self->length-1);
}

void MinHeap_bubbleDown(MinHeap *self, int bub) {
	int lChildIdx = MinHeap_getChildIdx(bub, 1);
	int rChildIdx = MinHeap_getChildIdx(bub, 2);

	if (lChildIdx >= self->length) {
		return;
	}
	int nextChild = 0;
	if (rChildIdx >= self->length) {  //if rchild out of range
		nextChild = lChildIdx; //shouldve called it nextChildIdx for consistency
	} else {
		nextChild = (self->nums[lChildIdx] >= self->nums[rChildIdx])? lChildIdx : rChildIdx;
		//here, next is greater child with Min, lesserChild with max
	}

	if (self->nums[bub] >= self->nums[nextChild]) {
		return;
	}
	MinHeap_swap(self, bub, nextChild);

	MinHeap_bubbleDown(self, nextChild);
}
int MinHeap_pop(MinHeap *self, int idx) {
	//cases: out of bounds vs returning the value
		//will exit w/ 0 if out of bounds, but should check before calling ideally anyways
	if (idx < 0 || idx >= self->length) {
		return 0;
	}
	
	int popped = self->nums[idx];
	self->nums[idx] = self->nums[self->length-1];
	self->length--;

	MinHeap_bubbleDown(self, idx);

	printf("\npopped: %d at index %d / New order:\n", popped, idx);
	MinHeap_print(self);

	return popped;
}

int main(int argc, char **argv) {

	MinHeap heap = MinHeap_initiate(20);

	int toInsert[] = {1,2,3,4,5,6,7,8,9,11,2,3,45,56,2,1,0};
	int toInsertLength = sizeof(toInsert)/sizeof(int);

	for (int i = 0; i < toInsertLength; ++i) {
		MinHeap_insert(&heap, toInsert[i]);
	}
	
	MinHeap_print(&heap);

	MinHeap_pop(&heap, 3); //should be checking if index is in range
	MinHeap_pop(&heap, 9);
	MinHeap_pop(&heap, 0);
	MinHeap_pop(&heap, 12);
	
	MinHeap_destroy(&heap);
	return 0;
}

//this time, I implemented w/o watching his implementation first.
	//he called it 'heapify' instead of bubble




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
		
		2*index + 1 = left child
		2*index + 2 = right child

		and parent is ceil(i/2.0) - 1
			(this was the way I found the equation)
			OR:
		and parent is floor((i-1)/2)
	
	THEN: keep length

Updating:
	much more complicated
		(hes talking abt it like its different than just deleting then inserting. Must be some way to reduce the amt of steps needed?)
	
	sidenoted / not the focus

now, for implementing! Imma do this one fr fr.



Time complexity:
	deletion: O(logN)
	insertion: O(logN)
		
	worst case scenarios ^ / because tree is complete, so will at most be the height if have to bubble up/down from top/bottom


*/ 
