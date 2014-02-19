#include "unity.h"
#include "CircularBuffer.h"


#define SIZE_OF_BUFFER 5
#define NUMBER 12
void setUp(){}
void tearDown(){}

void test_CreateBuffer_WORK_PROPERLY()
{

	CircularBuffer *testBuffer = CreateBuffer(SIZE_OF_BUFFER);
	TEST_ASSERT_NOT_NULL(testBuffer);
	TEST_ASSERT_EQUAL_INT(SIZE_OF_BUFFER,testBuffer->size);
	TEST_ASSERT_EQUAL_INT(0,testBuffer->length);
	TEST_ASSERT_NOT_NULL(testBuffer->head);
	TEST_ASSERT_NOT_NULL(testBuffer->tail);
	TEST_ASSERT_NOT_NULL(testBuffer->buffer);

	int *bufferArray=testBuffer->buffer;
	TEST_ASSERT_NOT_NULL(bufferArray);
	TEST_ASSERT_EQUAL_PTR(bufferArray,testBuffer->head);
	TEST_ASSERT_EQUAL_PTR(bufferArray,testBuffer->tail);

}

void test_add_SHOULD_ADD_ONE_NUMBER()
{
	#define FIRST_NUMBER 70

	CircularBuffer *CB = CreateBuffer(SIZE_OF_BUFFER);

	//Make sure add is success.
	TEST_ASSERT_EQUAL_INT(1,add(CB,FIRST_NUMBER));
	TEST_ASSERT_EQUAL(FIRST_NUMBER,CB->buffer[0]);
	TEST_ASSERT_EQUAL_INT(1,CB->length);

}

void test_add_SHOULD_ADD_ONE_NUMBER_AND_WRAP_OVER_TO_BEGINING()
{
#define LAST_NUMBER 99
	CircularBuffer *CB = CreateBuffer(SIZE_OF_BUFFER);
	//Make the head pointer point to the last location.
	CB->head = CB->head +(SIZE_OF_BUFFER-1);
	//Add a number to the last slot.
	add(CB,LAST_NUMBER);
	//Expect the last number appear in the last location.
	TEST_ASSERT_EQUAL(LAST_NUMBER,CB->buffer[SIZE_OF_BUFFER -1]);
	//The head expected to point to the first location of the buffer.
	TEST_ASSERT_EQUAL_PTR(CB->buffer,CB->head);

}

void test_add_SHOULD_NOT_ADD_IF_BUFFER_IS_FULL()
{
	CircularBuffer *CB = CreateBuffer(SIZE_OF_BUFFER);
	CB->length = CB-> size;
	CB ->buffer[0] = NUMBER+1;   //Fake the original number.
	add(CB,NUMBER);
	//The number in slot 0 still be the same
	TEST_ASSERT_EQUAL( NUMBER+1, CB->buffer[0]);
	// Add should fail to size buffer is full (0 indicates failures)
	TEST_ASSERT_EQUAL(0,add(CB,NUMBER));

	CB=CreateBuffer(SIZE_OF_BUFFER);
	add(CB,1);
	add(CB,2);
	add(CB,3);
	add(CB,4);
	add(CB,5);

	//Add should fail size buffer is full (0indicates failures)
	TEST_ASSERT_EQUAL(0,add(CB,6));
	TEST_ASSERT_EQUAL(1,CB->buffer[0]);
	TEST_ASSERT_EQUAL(2,CB->buffer[1]);
	TEST_ASSERT_EQUAL(3,CB->buffer[2]);
	TEST_ASSERT_EQUAL(4,CB->buffer[3]);
	TEST_ASSERT_EQUAL(5,CB->buffer[4]);
	TEST_ASSERT_EQUAL_PTR(&(CB->buffer[0]),CB->head);
	TEST_ASSERT_EQUAL_PTR(CB->tail,CB->head);
}

void test_Remove_SHOULD_REMOVE_THE_FIRST_INPUT_NUMBER()
{
	CircularBuffer *testBuffer= CreateBuffer(SIZE_OF_BUFFER);
	add(testBuffer,1);
	add(testBuffer,2);
	add(testBuffer,3);
	add(testBuffer,4);
	add(testBuffer,5);

	//Make sure the tail is point to the first input data.
	TEST_ASSERT_EQUAL(1,*(testBuffer->tail));

	int data;
	//Test the output data, should be in FIFO order.
	Remove(testBuffer,&data);
	TEST_ASSERT_EQUAL(1,data);
	//Test the function Output can continuously output the data in FIFO order.
	Remove(testBuffer,&data);
	TEST_ASSERT_EQUAL(2,data);
	Remove(testBuffer,&data);
	TEST_ASSERT_EQUAL(3,data);
	Remove(testBuffer,&data);
	TEST_ASSERT_EQUAL(4,data);
	Remove(testBuffer,&data);
	TEST_ASSERT_EQUAL(5,data);
	//Test is that the function will return 0 while data is completely output.
	TEST_ASSERT_EQUAL(0,Remove(testBuffer,&data));

}

void test_Removeall_SHOULD_REMOVE_ALL_THE_DATA_INSIDE_THE_BUFFER()
{

	int data;
	//Create the buffer set and input some data inside the buffer.
	CircularBuffer *testBuffer= CreateBuffer(SIZE_OF_BUFFER);
	add(testBuffer,1);
	add(testBuffer,2);
	add(testBuffer,3);
	add(testBuffer,4);
	add(testBuffer,5);
	//Remove all the data inside the buffer.
	Removeall(testBuffer);
	//Show the slot are empty.
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[0]); //slot 0
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[1]); //slot 1
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[2]); //slot 2
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[3]); //slot 3
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[4]); //slot 4
	TEST_ASSERT_EQUAL(0,testBuffer->buffer[5]); //slot 5

	//Add some data and remove some data to make the head and tail
	//does not point to the initial position
	add(testBuffer,1);
	add(testBuffer,2);
	add(testBuffer,3);
	Remove(testBuffer,&data);
	Remove(testBuffer,&data);
	//Remove all the data inside the buffer.
	Removeall(testBuffer);
	//Make sure head and tail is pointing to the initial position.
	TEST_ASSERT_EQUAL_PTR(testBuffer->buffer,testBuffer->head);
	TEST_ASSERT_EQUAL_PTR(testBuffer->buffer,testBuffer->tail);
	//Test the length of the buffer is zero.
	TEST_ASSERT_EQUAL(0,testBuffer->length);
}

void test_GetLength_SHOULD_RETURN_THE_CURRENT_LENGTH_OF_THE_BUFFER()
{
	CircularBuffer *testBuffer= CreateBuffer(SIZE_OF_BUFFER);
	add(testBuffer,1);
	add(testBuffer,2);
	add(testBuffer,3);
	add(testBuffer,4);
	//Since 4 data is inputed, the function should return 4.
	TEST_ASSERT_EQUAL(4,GetLength (testBuffer));
}
