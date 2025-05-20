#pragma once
#include <iostream>

template <class T>
class Queue {
public:
	Queue();
	Queue(size_t cap);
	Queue(const Queue<T>& other);
	Queue<T> operator=(const Queue<T>& other);
	Queue(Queue<T>&& other) noexcept;
	Queue<T> operator=(Queue<T>&& other) noexcept;
	~Queue();

	void push(const T& newElement);
	void push(T&& newElement);
	void pop();
	const T& peek() const;
	size_t getSize() const;
	bool isEmpty() const;
private:
	T* data;

	size_t size;
	size_t capacity;
	int put;
	int get;

	void copyFrom(const Queue<T>& other);
	void moveFrom(Queue<T>&& other);
	void free();
	void resize(size_t newCap);
};

template<class T>
inline Queue<T>::Queue() : Queue<T>(8)
{
}

template<class T>
inline Queue<T>::Queue(size_t cap)
{
	capacity = cap;
	size = 0;
	put = 0;
	get = 0;
	data = new T[capacity];
}

template<class T>
inline Queue<T>::Queue(const Queue<T>& other)
{
	copyFrom(other);
}

template<class T>
inline Queue<T> Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
inline Queue<T>::Queue(Queue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
inline Queue<T> Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
inline Queue<T>::~Queue()
{
	delete data;
}

template<class T>
inline void Queue<T>::push(const T& newElement)
{
	if (size == capacity) {
		resize(capacity * 2);
	}

	data[put] = newElement;
	(++put) %= capacity;
	size++;
}

template<class T>
inline void Queue<T>::push(T&& newElement)
{
	if (size == capacity) {
		resize(capacity * 2);
	}

	data[put] = std::move(newElement);
	(++put) %= capacity;
	size++;
}

template<class T>
inline void Queue<T>::pop()
{
	if (isEmpty()) {
		throw std::exception("Queue is empty, cant pop any elements");
	}

	(++get) %= capacity;
	size--;
}

template<class T>
inline const T& Queue<T>::peek() const
{
	if (isEmpty()) {
		throw std::exception("Index out of queue range");
	}

	return data[get];
}

template<class T>
inline size_t Queue<T>::getSize() const
{
	return size;
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
inline void Queue<T>::copyFrom(const Queue<T>& other)
{
	data = new T[other.capacity];
	capacity = other.capacity;
	size = other.size;
	get = other.get;
	put = other.put;

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<class T>
inline void Queue<T>::moveFrom(Queue<T>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<class T>
inline void Queue<T>::free()
{
	delete[] data;
}

template<class T>
inline void Queue<T>::resize(size_t newCap)
{
	T* newData = new T[newCap];
	for (int i = 0; i < size; i++) {
		newData[i] = data[get];
		(++get) %= capacity;
	}

	delete[] data;
	data = newData;

	get = 0;
	put = size;
	capacity = newCap;
}