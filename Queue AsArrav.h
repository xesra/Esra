#include <iostream>
template<class Type> 
class queueType
{
private:
int maxQueueSize; 
int count; 
int queueFront; 
int queueRear;
 Type *list; 
public:
queueType(int queuesize = 100); 
void initializeQueue(); 
void destroyQueue();
 bool isEmptyQueue(); 
bool isFullQueue(); 
void addQueue(Type queueElement);
 void deQueue(Type& deqElement); 
~queueType();
template<class Type>
void queueType<Type>::initializeQueue() 
{
queueFront = 0; 
queueRear = maxQueueSize - 1; 
count = 0; 
}
template<class Type>
void queueType<Type>::destroyQueue() 
{
queueFront = 0; 
queueRear = maxQueueSize - 1; 
count = 0;
}
template<class Type> 
bool queueType<Type>::isEmptyQueue()
 {
return(count ==0);

}

template<class Type>
bool queueType<Type>::isFullQueue()
 {
return(count == maxQueueSize);
}
template<class Type>
void queueType<Type>::addQueue(Type newElement)
{
if (!isFullQueue()) 
{
queueRear = (queueRear + 1) % maxQueueSize; 
count++; 
list[queueRear] = newElement;
}
else
cout << "can’t add to full queue. " << endl;
}
template<class Type>
void queueType<Type>::deQueue(Type& deqElement)
{
if (!isEmptyQueue()) 
{
deqElement = list[queueFront]; 
count--; 
queueFront = (queueFront + 1) % maxQueueSize;
}
else
cout << "can't delete from empty queue. " << endl;
}
 template<class Type>
queueType<Type>::queueType(int queuesize)
{
if (queuesize <= 0) 
{
cout << "Size of the array to hold the queue must << "be positive." << endl; 
cout << "Creating an array of size 100." << endl; 
maxQueueSize = 100;
}
else
 maxQueueSize = queuesize;
 queueFront = 0; 
queueRear = maxQueueSize - 1;
 count = 0; list = new Type[maxQueueSize];
}
template<class Type>
queueType<Type>::~queueType()
 {
delete [] list;
 }

