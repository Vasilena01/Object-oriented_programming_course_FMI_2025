#pragma once
#include <iostream>

template <class T>
class Optional {
public:
	Optional();
	Optional(const T& value);
	Optional(const Optional<T>& other);
	Optional<T> operator=(const Optional<T>& other);
	Optional(Optional<T>&& other) noexcept;
	Optional<T> operator=(Optional<T>&& other) noexcept;
	~Optional();

	const T& operator*() const;
	T& operator*() const;
	const T& getValue() const;

	bool has_value() const;
	void setValue(const T& newValue);
	void setValue(T&& newValue);
	bool reset();
private:
	T* data;

	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);
	void free();
};

template<class T>
inline Optional<T>::Optional()
{
	data = nullptr;
}

template<class T>
inline Optional<T>::Optional(const T& value)
{
	setValue(value);
}

template<class T>
inline Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<class T>
inline Optional<T>::Optional(Optional<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
inline Optional<T>::~Optional()
{
	free();
}

template<class T>
inline Optional<T> Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
inline Optional<T> Optional<T>::operator=(Optional<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
inline const T& Optional<T>::operator*() const
{
	return *data;
}

template<class T>
inline const T& Optional<T>::getValue() const
{
	if (!has_value()) {
		throw std::logic_error("Value does not exist");
	}
	return *data;
}

template<class T>
inline bool Optional<T>::has_value() const
{
	if (data != nullptr)
		return true;
	else
		return false;
}

template<class T>
inline void Optional<T>::setValue(const T& newValue)
{
	if (has_value()) {
		*data = newValue;
	}
	else {
		data = new T(newValue);
	}
}

template<class T>
inline void Optional<T>::setValue(T&& newValue)
{
	if (has_value()) {
		*data = std::move(newValue);
	}
	else {
		data = new T(std::move(newValue));
	}
}

template<class T>
inline bool Optional<T>::reset()
{
	if (data) {
		data = nullptr;
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (other.has_value()) {
		data = new T(*other.data);
	}
	else {
		data = nullptr;
	}
}

template<class T>
inline void Optional<T>::moveFrom(Optional<T>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<class T>
inline void Optional<T>::free()
{
	delete data;
}