#include "unity.h"
#include "CircularBuffer.h"








void setUp(){}

void tearDown(){}



void test_CreateBuffer_WORK_PROPERLY()

{



 CircularBuffer *testBuffer = CreateBuffer(5);

 if ((((testBuffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)14);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((testBuffer->size)), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->length)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 if ((((testBuffer->head)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)17);;};

 if ((((testBuffer->tail)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 if ((((testBuffer->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};



 int *bufferArray=testBuffer->buffer;

 if ((((bufferArray)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)22);;};

 UnityAssertEqualNumber((_U_SINT)(_UP)((bufferArray)), (_U_SINT)(_UP)((testBuffer->head)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((bufferArray)), (_U_SINT)(_UP)((testBuffer->tail)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX32);



}



void test_add_SHOULD_ADD_ONE_NUMBER()

{





 CircularBuffer *CB = CreateBuffer(5);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((add(CB,70))), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((CB->buffer[0])), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((CB->length)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);



}



void test_add_SHOULD_ADD_ONE_NUMBER_AND_WRAP_OVER_TO_BEGINING()

{



 CircularBuffer *CB = CreateBuffer(5);



 CB->head = CB->head +(5 -1);



 add(CB,99);



 UnityAssertEqualNumber((_U_SINT)((99)), (_U_SINT)((CB->buffer[5 -1])), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)(_UP)((CB->buffer)), (_U_SINT)(_UP)((CB->head)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);



}



void test_add_SHOULD_NOT_ADD_IF_BUFFER_IS_FULL()

{

 CircularBuffer *CB = CreateBuffer(5);

 CB->length = CB-> size;

 CB ->buffer[0] = 12 +1;

 add(CB,12);



 UnityAssertEqualNumber((_U_SINT)((12 +1)), (_U_SINT)((CB->buffer[0])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((add(CB,12))), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);



 CB=CreateBuffer(5);

 add(CB,1);

 add(CB,2);

 add(CB,3);

 add(CB,4);

 add(CB,5);





 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((add(CB,6))), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((CB->buffer[0])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((CB->buffer[1])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((CB->buffer[2])), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((CB->buffer[3])), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((CB->buffer[4])), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((&(CB->buffer[0]))), (_U_SINT)(_UP)((CB->head)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((CB->tail)), (_U_SINT)(_UP)((CB->head)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_HEX32);

}



void test_Remove_SHOULD_REMOVE_THE_FIRST_INPUT_NUMBER()

{

 CircularBuffer *testBuffer= CreateBuffer(5);

 add(testBuffer,1);

 add(testBuffer,2);

 add(testBuffer,3);

 add(testBuffer,4);

 add(testBuffer,5);





 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((*(testBuffer->tail))), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);



 int data;



 Remove(testBuffer,&data);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);



 Remove(testBuffer,&data);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

 Remove(testBuffer,&data);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 Remove(testBuffer,&data);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 Remove(testBuffer,&data);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Remove(testBuffer,&data))), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);



}



void test_Removeall_SHOULD_REMOVE_ALL_THE_DATA_INSIDE_THE_BUFFER()

{



 int data;



 CircularBuffer *testBuffer= CreateBuffer(5);

 add(testBuffer,1);

 add(testBuffer,2);

 add(testBuffer,3);

 add(testBuffer,4);

 add(testBuffer,5);



 Removeall(testBuffer);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[0])), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[1])), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[2])), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[3])), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[4])), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->buffer[5])), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);







 add(testBuffer,1);

 add(testBuffer,2);

 add(testBuffer,3);

 Remove(testBuffer,&data);

 Remove(testBuffer,&data);



 Removeall(testBuffer);



 UnityAssertEqualNumber((_U_SINT)(_UP)((testBuffer->buffer)), (_U_SINT)(_UP)((testBuffer->head)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((testBuffer->buffer)), (_U_SINT)(_UP)((testBuffer->tail)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_HEX32);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((testBuffer->length)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

}



void test_GetLength_SHOULD_RETURN_THE_CURRENT_LENGTH_OF_THE_BUFFER()

{

 CircularBuffer *testBuffer= CreateBuffer(5);

 add(testBuffer,1);

 add(testBuffer,2);

 add(testBuffer,3);

 add(testBuffer,4);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((GetLength (testBuffer))), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

}
