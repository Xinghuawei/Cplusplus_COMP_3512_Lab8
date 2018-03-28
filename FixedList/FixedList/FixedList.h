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
FixedList::FixedList() {}

template<class T, size_t N>
FixedList::~FixedList() {}

template<class T, size_t N>
const T& FixedList::get(unsigned int index) const {
	return lst[index];

}
template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index)
{
	// TODO: insert return statement here
}
