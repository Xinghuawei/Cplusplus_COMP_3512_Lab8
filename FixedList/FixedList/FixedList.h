#pragma once
#include <list>

using namespace std;
template<class T, size_t N>
class FixedList {
private:
	list<int>;
public:	
	FixedList();
	
	~FixedList();

	const T& get(unsigned int) const;

	T& operator[](unsigned int);

	int getFirstIndex(const T& t) const;

	size_t size() const;

	size_t capacity() const;

	bool add(const T&);

	T remove(const T&);

};