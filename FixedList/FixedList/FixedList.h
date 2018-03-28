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
		throw "not correct";
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
	if (s_size==0) {
		return -1;
	}
	else {
		for (std::list<T>::const_iterator it = lst.begin();
			it != lst.end(); ++it) {
			if (t != *it) {
				count++;
			}
			
		}
		return count;
	}
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	for (typename T::const_iterator it = t.begin();
		it != t.end(); ++it) {
		s_size++;
	}
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
	int index{ 0 };
	for (typename T::const_iterator it = t.begin();
		it != t.end(); ++it) {
		if (*it == t) {
			it = lst.erase(it);
		} else {
			index++;
		}
	}

	for (typename T::const_iterator  itt = (index+1);
		itt != t.end(); ++itt) {
		*(itt-1) = *itt
	}
	return it;
}


