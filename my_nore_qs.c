
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT {
	int low;
	int high;
	struct NodeT *parent;
} Node;

Node *Node_create(int low, int high, Node *parent) {
	Node *self = malloc(sizeof(Node));
	self->low = low;
	self->high = high;
	self->parent = parent;
	return self;
}

//next time consider making de-allocation a Node function rather than an impromptu thing

void qs(int* nums, int len) {
	
	Node *youngest = Node_create(0, len-1, NULL);
	int nodeCount = 1;
	
	int l = 0, mid = 0, h = 0, pivot = 0, buffer = 0;
	Node *nextYoungest = NULL;
	while (nodeCount > 0) {
		
		nodeCount--;
		h = youngest->high;
		l = youngest->low;
		nextYoungest = youngest->parent;
		free(youngest);
		youngest = nextYoungest;

		pivot = nums[h];
		mid = l;

		for (int i = l; i < h; ++i) {
			if (nums[i] < pivot) {
				buffer = nums[mid];
				nums[mid] = nums[i];
				nums[i] = buffer;
				mid++;
			}
		}
		nums[h] = nums[mid];
		nums[mid] = pivot;
		
		if (h - mid > 1) {
			youngest = Node_create(mid+1, h, youngest);
			nodeCount++;
		}
		if (mid - l > 1) {
			youngest = Node_create(l, mid-1, youngest);
			nodeCount++;
		}

	}
}

int main(int argc, char **argv) {

	int nums[] = {1,2,5,54,7,2,3,345,2345,457,2,3,1,2,53,676,5,2345,243,56,4567,1,345,3457,476,0,0,7,5,1,42,23};
	int len = sizeof(nums)/sizeof(int);

	qs(nums, len);

	for (int i = 0; i < len; i++) {
		printf("%d, ", nums[i]);
	}
	printf("\n");

	return 0;
}
