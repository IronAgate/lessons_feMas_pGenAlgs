




/*

ArrayList or DynamicArray

trying to get the benefits of both arrays and linked lists

//see linked_list.c for comparison

used by maps, ringbuffers, ?etc

https://frontendmasters.com/courses/algorithms/arraylist/


array list uses an Array as the underlying datastructure, but implements list-style functionality over it
	//?

	for ex:
		arrayLists have a 'length' and a 'capacity'
			may only write to first 3 elements, thats the length, but may be able to hold 10, the capacity

		can 'push' by:
			1. check if length is within capacity still
			2. write 'pushed' value to length index, aka next open index
			3. increment length++
			
			this is O(1)

		same with 'pop' to get the final value //thinking as though its a 'stack'

		//? yes but what about shifting the array if you index from the middle
	
	?^ what if exceed capacity?
		
		create a new, longer array & memcopy the array over

		so you need to find a balance where you dont have to 'grow' like this very often, cuz its slow, but you also arent using wayyy too much memory in your array
	

	Now, for queue-like operations
		
		of course, have to shift the array elements over, which is O(n)

		also shifting for dequeing
	

		so, not ideal for queue-like operations

so arrayLists can be good for stack-like operations, but not great for everything
	IT DEPENDS

	arrayLists can give you indexing capability, but any time you have to shift the list it suffers

*/
