#include "FixedList.h"
#include <list>
#include <iostream>

using namespace std;
int main() {
	FixedList<double,4> mylist;
	mylist.add(1.1);
	mylist.add(2.2);
	mylist.add(3.3);
	mylist.add(4.4);
	cout << "double list: " << " ";

	for (int i = 0; i < 4; i++) {
		cout << mylist.get(i) << " " ;
	}
	cout << endl;

	cout << "Get list capacity : " << " ";
	cout << mylist.capacity() << endl;

	cout << "Get list size : " << " ";
	cout << mylist.size() << endl;

	cout << "use operator [] get element in index 0 : " << " ";
	cout << mylist[0] << endl;

	cout << "Remove 3 from list : " << " ";
	cout << mylist.remove(3) << endl;

	cout << "new list: " << " ";
	for (int i = 0; i < 3; i++) {
		cout << mylist.get(i) << " ";
	}
	cout << endl;

	cout << "new list capacity: " << " ";
	cout << mylist.capacity() << endl;

	cout << "New list size : " << " ";
	cout << mylist.size() << endl;

	cout << "Get index of first 2 occurs : " << " ";
	cout << mylist.getFirstIndex(2.2) << endl;

	

	//--------------------------------------------
	cout << "Change input to string" << endl;
	//--------------------------------------------

	FixedList<string, 4> mylist2;
	cout << "string list: " << " ";
	mylist2.add("SFU");
	mylist2.add("UBC");
	mylist2.add("BCIT");
	mylist2.add("KPU");

	cout << "SFU UBC BCIT KPU" << " ";
	cout << endl;

	cout << "Get list capacity : " << " ";
	cout << mylist2.capacity() << endl;

	cout << "Get list size : " << " ";
	cout << mylist2.size() << endl;

	cout << "Remove 3 from list : " << endl;
	mylist2.remove("UBC");

	cout << "new list size: " << " ";
	cout << mylist2.size() << endl;

	cout << "new list capacity: " << " ";
	cout << mylist2.capacity() << endl;

	cout << "New list size : " << " ";
	cout << mylist2.size() << endl;

	system("pause");

}