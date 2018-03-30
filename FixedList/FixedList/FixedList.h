#pragma once
#include <list>
#include <stdexcept>

using namespace std;
/*
Create a fixed list that can support any data type.
*/
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

	T remove(const T& t);

};


//constructor
template<class T, size_t N>
FixedList<T, N>::FixedList() {}

//destructor
template<class T, size_t N>
FixedList<T, N>::~FixedList() {}

/*
Overload subcript operator[]
Precondition: an int represent index
Postcondition: return element of the index.
*/
template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index)
{
	if (index >= cap || index < 0) {
			throw std::out_of_range("Index out of bound");
	}
	else {
		std::list<T>::iterator it = std::next(lst.begin(), index); 
			return *it;
	}
}

/*
Get the element in the input index.
Precondition: an int represent index
Postcondition: return element of the index.
*/
template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const {
	if (index >= cap || index < 0) {
		throw std::out_of_range("Index out of bound");
	}
	else {
		std::list<T>::const_iterator it = std::next(lst.begin(), index);
		return *it;
	}
}

/*
Get the index of the first occurence of the input element.
Precondition: a type T element
Postcondition: return index of first occurence of that element.
*/
template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{	
	
		for (std::list<T>::const_iterator it = lst.begin();
			it != lst.end(); ++it) {
			if (t == *it) {
				return std::distance(lst.begin(), it);
			}
		}
		
		throw std::invalid_argument("Input not found in the container");
}

/*
Size function return the number of element in the FixedList.
Precondition: an valid container(include empty)
Postcondition: return the size of the FixedList.
*/
template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return s_size;
}

/*
Capacity function return the capacity of the FixedList
Once capacity is initialed, it will not change.
Precondition: an valid container(include empty)
Postcondition: return the capacity of the FixedList.
*/
template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return cap;
}


/*
Add function add element in the back of the Fixedlist.
Precondition: If add success, return ture. Otherwise, return false.
Postcondition: return ture.
*/
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

/*
Remove function remove element in the Fixedlist.
Precondition: Fixedlist size not 0 or negative.
Postcondition: Remove the element and return the removed element.
The next closed element fill the blank.
*/
template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{	
	if (s_size <= 0) {
		throw std::out_of_range("Out of bound");
	}
	else {
		for (std::list<T>::const_iterator it = lst.begin();
			it != lst.end();) {
			if (*it == t) {
				T tmp = *it;
				it = lst.erase(it);
				s_size--;
				return tmp;
			}
			else {
				it++;
			}
		}
	}
	
}


