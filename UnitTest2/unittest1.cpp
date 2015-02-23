#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Point2f punt1, punt2;
			punt1.x = 5;
			punt1.y = 11;

			punt2.x = 7;
			punt2.y = 8;

			punt1.operator+(punt2);
			Assert::AreEqual(punt1.x + punt2.y);

		}

	};
}