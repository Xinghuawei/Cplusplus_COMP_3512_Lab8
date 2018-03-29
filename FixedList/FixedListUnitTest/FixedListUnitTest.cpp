#include "CppUnitTest.h"
#include "../FixedList/FixedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedListUnitTest
{		
	
	TEST_CLASS(UnitTest1)
	{
		FixedList<double, 3> list;


	public:
		
		TEST_METHOD(add_three_double)
		{
			Assert::AreEqual(true, list.add(1.1));
			Assert::AreEqual(true, list.add(2.2));
			Assert::AreEqual(true, list.add(3.3));
		}

		TEST_METHOD(add_four_double_out_of_bound)
		{
			Assert::AreEqual(true, list.add(1.1));
			Assert::AreEqual(true, list.add(2.2));
			Assert::AreEqual(true, list.add(3.3));
			//try to test throw exception
			Assert::AreEqual(false, list.add(4.4));
		}

	};
}