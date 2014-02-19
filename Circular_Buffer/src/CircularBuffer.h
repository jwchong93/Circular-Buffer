/*
 * CircularBuffer.h
 *
 *  Created on: Feb 5, 2014
 *      Author: JingWen
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_
#include<stdbool.h>

typedef struct CircularBuffers{
	int *head;
	int *tail;
	int *buffer;
	int length;
	int size;

}CircularBuffer;


CircularBuffer * CreateBuffer (int size);
int add(CircularBuffer * CB,int value);
void destroy(CircularBuffer *CB);
int Remove(CircularBuffer *CB,int *value);
void Removeall(CircularBuffer *CB);
#endif /* CIRCULARBUFFER_H_ */
