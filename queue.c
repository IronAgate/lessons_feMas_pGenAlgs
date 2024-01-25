
#include <stdio.h>
#include <stdlib.h>


struct QueueHandler {
	struct QueueItem *head;
	struct QueueItem *tail;
	unsigned int length;
};

struct QueueItem {
	int value;
	struct QueueItem *child;
};


//QueueHandler Functions

void QueueHandler_initialize(struct QueueHandler *qh) {

	qh->head = NULL;
	qh->tail = NULL;
	qh->length = 0;

}

void QueueHandler_enqueue(struct QueueHandler *qh, int value) {

	struct QueueItem *qi = malloc(sizeof(struct QueueItem));
	qi->value = value;
	qi->child = NULL;

	if (qh->length == 0) {
		qh->head = qi;
	} else {
		qh->tail->child = qi;
	}
	qh->tail = qi;
	qh->length++;
	return;
}


int QueueHandler_deque(struct QueueHandler *qh) {

	if (qh->length == 0) {
		return 0; //what if the value is NULL anyways? how to signify an error here?
	}

	qh->length--;

	struct QueueItem *oldHead = qh->head;

	qh->head = oldHead->child; //if no next children, sets to null by default. Otherwise is set to next child
	if (qh->head == NULL) {
		qh->tail = NULL;
	}

	int rVal = oldHead->value;
	free(oldHead);
	return rVal;

}


int QueueHandler_peek(struct QueueHandler *qh) {
	return qh->head->value;
} //ERROR: will try to dereference null ptr here if queue is empty


int main(int argc, char** argv) {

	struct QueueHandler q;
	QueueHandler_initialize(&q);

	printf("%d\n", QueueHandler_deque(&q));

	QueueHandler_enqueue(&q, 10);
	QueueHandler_enqueue(&q, 15);
	QueueHandler_enqueue(&q, 20);

	printf("%d\n", QueueHandler_peek(&q));
	printf("%d\n", QueueHandler_deque(&q));
	printf("%d\n", QueueHandler_deque(&q));
	printf("%d\n", QueueHandler_deque(&q));
	printf("%d\n", QueueHandler_deque(&q));
	printf("%d\n", QueueHandler_deque(&q));




	return 0;
}







/* 

is just a specific implementation of a linked list

entering gray-areas of 'is this a datastructure or algorithm?'
	its specific algorithms that run over specific datastructures



a queue is a restrained linked list
	
	no traversal

	store reference to head & maybe tail

	often singly-linked


*/
