#include "CppUnitTest.h"
#include "../FixedList/FixedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedListUnitTest
{		
	
	TEST_CLASS(UnitTest1)
	{
		FixedList<double, 3> list;
		FixedList<double, 0> list2;
		FixedList<string, 3> list3;
		FixedList<string, 0> list4;
	public:
		
		//check if size function return expect value when size is full
		//of doubles
		TEST_METHOD(full_size)
		{	
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);
			Assert::AreEqual(3, (int)list.size());

		}

		//check if size function return expect value when size is full
		//of strings
		TEST_METHOD(full_size_string)
		{
			list3.add("a");
			list3.add("b");
			list3.add("c");
			Assert::AreEqual(3, (int)list3.size());

		}

		//check if size function return expect value when size is zero
		TEST_METHOD(zero_size)
		{
			
			Assert::AreEqual(0, (int)list.size());

		}

		//check if capacity function return expect value when capacity is zero doubles
		TEST_METHOD(zero_capacity)
		{
			Assert::AreEqual(0, (int)list2.capacity());

		}

		//check if capacity function return expect value when capacity is zero strings
		TEST_METHOD(zero_capacity_string)
		{
			Assert::AreEqual(0, (int)list4.capacity());

		}

		//check if capacity function return expect value when capacity is full of string
		TEST_METHOD(full_capacity_string)
		{
			Assert::AreEqual(3, (int)list3.capacity());

		}

		//check if capacity function return expect value when capacity is full of doubles
		TEST_METHOD(full_capacity)
		{
			Assert::AreEqual(3, (int)list.capacity());

		}

		//check if add function return expect value when adding 3 doubles
		TEST_METHOD(add_three_double)
		{
			Assert::AreEqual(true, list.add(1.1));
			Assert::AreEqual(true, list.add(2.2));
			Assert::AreEqual(true, list.add(3.3));
		}

		//check if add function return expect value when adding 3 strings
		TEST_METHOD(add_three_strings)
		{
			Assert::AreEqual(true, list3.add("a"));
			Assert::AreEqual(true, list3.add("b"));
			Assert::AreEqual(true, list3.add("c"));
		}

		//check if add function return expect value when adding 
		//a out of range double
		TEST_METHOD(add_four_double_out_of_bound)
		{
			Assert::AreEqual(true, list.add(1.1));
			Assert::AreEqual(true, list.add(2.2));
			Assert::AreEqual(true, list.add(3.3));
			Assert::AreEqual(false, list.add(4.4));
		}

		//check if add function return expect value when adding 
		//a out of range string
		TEST_METHOD(add_four_strings_out_of_bound)
		{
			Assert::AreEqual(true, list3.add("a"));
			Assert::AreEqual(true, list3.add("b"));
			Assert::AreEqual(true, list3.add("c"));
			Assert::AreEqual(false, list3.add("d"));
		}

		//check if get function return expect value when get 
		//a list of 3 doubles.
		TEST_METHOD(get_from_three_strings)
		{
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);
			Assert::AreEqual(3, (int)list.get(2));

		}

		//check if get function throw a exception when get
		//value from out of range.
		TEST_METHOD(get_from_out_of_bound_list)
		{
			
			list.add(1);
			list.add(2);
			list.add(3);
			bool exception = false;
			try {
				double element = list.get(3);
			}
			catch (std::exception &e) {
				exception = true;
			}
			Assert::AreEqual(true, exception);

		}

		//check if overloaded operation [] return the
		//except value.
		TEST_METHOD(operation_get_element)
		{
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);
			Assert::AreEqual(3.3, (double)list[2]);

		}

		//check if overloaded operation [] throws exception
		//when use [] to get element out of range.
		TEST_METHOD(operation_get_from_out_of_bound_list)
		{
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);

			bool exception = false;
			try {
				double element = list[3];
			}
			catch (std::exception &e) {
				exception = true;
			}
			Assert::AreEqual(true, exception);

		}

		//check if get first occour element index function
		//return except value.
		TEST_METHOD(element_first_index_found)
		{
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);
			Assert::AreEqual(2, list.getFirstIndex(3.3));

		}

		//check if get first occour element index function
		//return exception when element not found.
		TEST_METHOD(element_first_index_not_found)
		{
			list.add(1);
			list.add(2);
			list.add(3);

			bool exception = false;
			try {
				double element = list.getFirstIndex(4);
			}
			catch (std::exception &e) {
				exception = true;
			}
			Assert::AreEqual(true, exception);

		}

		//check if remove function return expect value
		TEST_METHOD(remove_from_full_list) {
			list.add(1.1);
			list.add(2.2);
			list.add(3.3);

			Assert::AreNotEqual(2,(int)list.remove(3.3));
		}

		////check if remove function return expect value
		//from one element list.
		TEST_METHOD(remove_from_one_element) {
			list.add(1);


			Assert::AreEqual(1, (int)list.remove(1));
		}

		//check if remove function return expect value
		//from a empty list.
		TEST_METHOD(remove_from_zero_size)
		{
			bool exception = false;
			try {
				list.remove(1);
			}
			catch (std::exception &e) {
				exception = true;
			}
			Assert::AreEqual(true, exception);
			
		}

	};
}