


/* Trie
	aka digital tree / re'trie'val tree

	pronounced 'Tree'
	
Particularly common in interviews, according to Prime
	
a 'trie' is essentially an autocomplete
	done in O(n) time

is based off of a linked list / will not implement, but demonstrates
	https://frontendmasters.com/courses/algorithms/tries/	


For example, say we are doing an english language tree: 
	start with a node which has 26 possible children, for each letter
	
	if word is 'cat':
		from parent -> c -> a -> t 

		at t, usually denote somehow that it is a possible end-of-word, like a bool within each node or an 'nullstringbyte' kinda thing

	So, its a tree where you can navigate down letters to create words

	
So to use autocomplete ^ :
	when type a letter, would traverse down the the tree from that letter and identify possible next words

	then prioritize them somehow to recommend 1 over the others
		typically via some sort of 'scoring algorithm' which tracks users' most used words
	
	and by 'traverse down' thats a DFS

insertion
	typically insert takes a full string or sequence as arg, then inserts each
	as in, traverse as far as can if path already exists, then add more if necessary
	end by marking end of the word

deletion
	go to end of word, delete your way back (if not destroying other words)



interview questions often look like:
	1. something something "autocomplete from a list of words" something something

	2. Caching mechanism, where you can see a 'path that they want'
		
		11:30 in https://frontendmasters.com/courses/algorithms/tries/ 
	
		dont rly understand yet


time Complexity
	technically is O(height) BUT height is bound by the longest words, so is rly O(n) where n is something like 12-20

	in situations where height is not bound like this^, probably not the right datastructure anyways


*/
