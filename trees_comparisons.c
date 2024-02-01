
/*

Using DFS vs BFS to navigate/search/compare trees

https://frontendmasters.com/courses/algorithms/search-practice



When comparing trees with BFS, the 'structure' or order of the branches is not preserved. For ex:
	A <B, C> == A< B< C>>

	so in this case, DFS may be superior since it preserves ordering/branching of the tree
		(given that they convene about their 'base case' / when they reach the end of a branch or when they reach a leaf, they need to next both compare their 'null' next branch result, if that makes sense )

		(as in, you _could_ do it with BFS, if you compared w/ extra information each step, but its more complicated and taxing than using DFS where you can just compare the null at termination points)
	
		(At first I didnt think this was a fair comparison because you are adding a 'null' check to the DFS, and thats why its preserving structure. However, I think I get it now.)
			Yes, you are adding to it, and yes, _if_ you added it to the BFS, it would also preserve structure. However: its just much easier to add that check with the DFS than the BFS because of the nature of the alg/structure being used for traversal.
			BUT, if you're comparing at the point that a node is added to the stack/queue, (or more precisely when it is _read_ in order to add it to the queue, cuz thats when youd see null) You could just do that with the BFS too right?
				And then for BFS youd just add a check every time you add something to the queue, right? making note of whenever you add a null to the queue, or would've.
			
???			SO, it DOES preserve shape for both, as long as you add that null check / I must not understand correctly, or???
		

!		I THOUGHT I GOT IT
			I thought maybe it was for checking when a single node is identical btwn trees, but I think you might have to compare the entire tree to verify that
				cuz both BFS and DFS had errors in this area

*/
