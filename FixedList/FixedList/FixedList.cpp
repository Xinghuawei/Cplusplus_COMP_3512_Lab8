#include "FixedList.h"
#include <list>
#include <iostream>

using namespace std;
int main() {
	FixedList<int,3> mylist;
	mylist.add(2);
	mylist.add(5);
	mylist.add(7);

	cout << mylist[0] << endl;
	cout << mylist.capacity() << endl;
	cout << mylist.getFirstIndex(2) << endl;

	system("pause");

}