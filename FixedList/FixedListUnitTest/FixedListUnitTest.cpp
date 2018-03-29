#include "CppUnitTest.h"
#include "../FixedList/FixedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedListUnitTest
{		
	
	TEST_CLASS(UnitTest1)
	{
		FixedList<double, 3> list;


	public:
		
		TEST_METHOD(ADD_)
		{
			Assert::AreEqual(true, list.add(1.1));
			Assert::AreEqual(true, list.add(2.2));
			Assert::AreEqual(true, list.add(3.3));
		}

	};
}