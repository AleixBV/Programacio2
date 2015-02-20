#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Point2f punt;

			punt.setZero();
			Assert::IsTrue(punt.checkZero());
		}

	};
}