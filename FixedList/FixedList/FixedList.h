#pragma once
#include <list>

using namespace std;
template<class T, size_t N>
class FixedList {
private:
	list<T> lst{ N };
public:	
	FixedList();
	
	~FixedList();

	const T& get(unsigned int index) const;

	T& operator[](unsigned int index);

	int getFirstIndex(const T& t) const;

	size_t size() const;

	size_t capacity() const;

	bool add(const T&);

	T remove(const T&);

};



template<class T, size_t N>
FixedList<T,N>::FixedList() {}

template<class T, size_t N>
FixedList<T,N>::~FixedList() {}

template<class T, size_t N>
inline const T & FixedList<T,N>::get(unsigned int index) const {
	if (index >= N || index < 0) {
		return -1;
	} else {
		return lst[index];
	}
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index)
{	
	if (index >= N || index < 0) {
		return -1;
	}
	else {
		return lst[index];
	}
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{	
	if (t.empty()) {
		return -1;
	} else {
		return t.begin();
	}
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return size_t();
}



