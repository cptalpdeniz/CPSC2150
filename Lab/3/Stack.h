#ifndef STACK_H
#define STACK_H 

enum class method
{
	ONE = 1,
	TEN = 10,
	DBL = 2
};

template <class T = int, method V = method::ONE> class Stack 
{
	T* arr;
	int n;
	int capacity;
public:
	Stack();
	~Stack();
	Stack(const Stack<T, V>&);
	Stack &operator=(const Stack<T, V> &);
	void push(const T);
private:
};


#endif