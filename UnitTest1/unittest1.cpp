#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		/*TEST_METHOD(TestMethod_operator)
		{
		Point2f point1, point2;
		punt1.x = 5;
		punt1.y = 11;

		punt2.x = 7;
		punt2.y = 8;

		punt1.operator+(punt2);
		Assert::AreEqual(punt1.x + punt2.y);

		}*/
		
		TEST_METHOD(TestMethod_isZero)
		{
			Point2f point;

			point.x = 0.0f;
			point.y = 0.0f;
			Assert::IsTrue(point.isZero());
		}

		TEST_METHOD(TestMethod_setZero)
		{
			Point2f point;

			point.setZero();
			Assert::IsTrue(point.isZero());
		}


	};
}