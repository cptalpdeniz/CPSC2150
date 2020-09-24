#include "Stack.h"

//MACRO for common code
#define loopCopy() {			\
	T* newArr = new T[capacity];\
	for (int i = 0; i < n; ++i) \
	{							\
		newArr[i] = arr[i];		\
	}							\
	delete [] arr;				\
	arr = newArr;				\
}

template <class T, method V> Stack<T, V>::Stack() : arr(new T[1]), n(0), capacity(1) { }


template <class T, method V> Stack<T, V>::~Stack()
{
	delete [] arr;
}

template <class T, method V> Stack<T, V>::Stack(const Stack<T, V>& s)
{
	(*this) = s;
}

template <class T, method V> Stack<T,V> &Stack<T, V>::operator=(const Stack<T, V> &s)
{
	delete [] arr;
	arr = new T[s.capacity];

	for (int i = 0; i < s.n; ++i)
	{
		arr[i] = s.arr[i];
	}
	n = s.n;
	capacity = s.capacity;
	return (*this);
}

template <class T, method V> void Stack< T, V>::push(const T data)
{
	if constexpr (V == method::ONE)
	{
		capacity += 1;
		loopCopy()
	}
	if constexpr (V == method::TEN)
	{
		if (n == capacity)
		{
			capacity += 10;
			loopCopy()
		}
	}
	if constexpr (V == method::DBL)
	{
		if (n == capacity)
		{
			capacity *= 2;
			loopCopy()
		}
	}

	arr[n] = data;
	n++;
}


template class Stack<int, method::ONE>;
template class Stack<int, method::TEN>;
template class Stack<int, method::DBL>;