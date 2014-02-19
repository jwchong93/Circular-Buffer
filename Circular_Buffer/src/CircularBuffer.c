#include "CircularBuffer.h"
#include <malloc.h>
#include <stdio.h>

CircularBuffer * CreateBuffer (int size)
{
	CircularBuffer *newBuffer = malloc(sizeof(CircularBuffer));
	newBuffer->size=size;
	newBuffer->length=0;

	free(newBuffer->head);
	free(newBuffer->tail);
	free(newBuffer->buffer);
	newBuffer->buffer= malloc(sizeof(int) * size);
	newBuffer->head = newBuffer->tail = newBuffer ->buffer;
	return newBuffer;
}

/*
 * Add a number to the circular buffer.
 *
 * Input:
 * 		CB		points to the circular buffer data structure
 * 		value	contains the number to be added to the buffer.
 * Return:
 * 		0 indicate fail to add(buffer is full).
 * 		1 indicate pass
 *
 */
int add(CircularBuffer * CB,int value)
{
	if(CB->length==CB->size)
		return 0;

	*(CB->head)=value;
	CB->head++;
	CB->length++;

	if(CB->head >= &(CB->buffer[CB->size]))
	{
		CB->head=CB->buffer;
	}
	return 1;

}


/*
 * Remove a number from the circular buffer.
 *
 * Input:
 * 		CB		points to the circular buffer data structure
 * Return:
 * 		0		No data left inside the circular buffer.
 * 		1		Successfully remove data from the buffer.
 * 	Output:
 * 		*value  pointer to the data
 *
 */
int Remove(CircularBuffer *CB,int *value)
{
	if(CB->length==0)
		return 0;
	*value = *(CB->tail);
	CB->tail++;
	CB->length--;
	return 1;

}

/*
 * Remove all the data inside the buffer, and reset the head and tail to the initial position.
 *
 * Input:
 * 		CB		points to the circular buffer data structure
 * Return:
 * 		None
 *
 */
void Removeall(CircularBuffer *CB)
{

	int i=0;
	while(CB->length!=0)
	{
		CB->buffer[i]=0;
		CB->length--;
		i++;
	}
	CB->head=CB->buffer;
	CB->tail=CB->buffer;



}


/*
 * Get the length of the circular buffer.
 *
 * Input:
 * 		CB		points to the circular buffer data structure
 * Return:
 * 		current length of the circular buffer.
 *
 */
int GetLength (CircularBuffer * CB)
{
	return CB->length;
}
/*
 * Destroy the circular buffer that created in the memory.
 *
 * Input:
 * 		CB		points to the circular buffer data structure
 * Return:
 * 		None
 *
 */
void destroy(CircularBuffer *CB)
{
	free(CB->buffer);
	free(CB);
}
