


/*

Array Buffers
	aka 'ring buffers'


like using an arrayList for queuing, but the 'start' doesnt have to be at 0
	so you have an index for head/tail
	//kind of like using ptrs directly, ig

	so you can add to the front/back without necessarily needing to shift the entire array
		//although you have to shift at some point right?

!!! 		BUT you can just loop around in the array to index w/ %
			hence 'ring' buffer
	
	
	the downside is just still resizing, as opposed to a true linked-list queue

		you just rewrite from the head
			//?couldnt it sometimes be more performant to write from the disjoint, so you may not need to rewrite the whole thing?

	
!	Just be careful not to overflow your indexing

*/
