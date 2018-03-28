#pragma once
#include <list>

using namespace std;
template<class T, size_t N>
class FixedList {
private:
	size_t s_size{ 0 };
	size_t cap = N;
	list<T> lst;
public:
	FixedList();

	~FixedList();

	const T& get(unsigned int index) const;

	T& operator[](unsigned int index);

	int getFirstIndex(const T& t) const;

	size_t size() const;

	size_t capacity() const;

	bool add(const T& t);

	T remove(const T&);

};



template<class T, size_t N>
FixedList<T, N>::FixedList() {}

template<class T, size_t N>
FixedList<T, N>::~FixedList() {}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const {
	if (index >= cap || index < 0) {
		return -1;
	}
	else {
		lst[index];
	}
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index)
{
	if (index >= cap || index < 0) {
		throw "Index out of bound";
	}
	else {
		std::list<T>::iterator it = std::next(lst.begin(), index); 
			return *it;
	}
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{	
	int count{ 0 };
	//wrong
	if (s_size==0) {
		return -1;
	}
	else {
		for (std::list<T>::const_iterator it = lst.begin();
			it != lst.end(); ++it) {
			if (t != *it) {
				return std::distance(lst.begin(), it);
			}
		}
		
	}
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return s_size;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return cap;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	if (s_size < cap) {
		lst.push_back(t);
		s_size++;
		return true;
	} else {
		return false;
	}
}

template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{	
	
	for (std::list<T>::const_iterator it = lst.begin();
		it != lst.end();) {
		if (*it == t) {
			T tmp = *it;
			it = lst.erase(it);
			s_size--;
			return tmp;
		} else {
			it++;
		}
	}
	
}


