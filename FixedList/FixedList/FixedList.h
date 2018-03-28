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

	bool add(const T& t);

	T remove(const T&);

};



template<class T, size_t N>
FixedList<T, N>::FixedList() {}

template<class T, size_t N>
FixedList<T, N>::~FixedList() {}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const {
	if (index >= N || index < 0) {
		return -1;
	}
	else {
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
	}
	else {
		return t.begin();
	}
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	int count{ 0 };
	for (typename T::const_iterator it = t.begin();
		it != t.end(); ++it) {
		count++;
	}
	return count;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return N;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	if (lst.size() < (N-1)) {
		lst.push_back(t);
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
		}
		else {
			index++;
		}
	}

	for (typename T::const_iterator  itt = (index+1);
		itt != t.end(); ++itt) {
		*(itt-1) = *itt
	}
	return it;
}

int main() {

}

