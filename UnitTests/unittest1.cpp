#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.cpp"
#include "../Programacio2/String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod_operatorPlus)
		{
			Point2f point1, point2, point3;
			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point3 = point1 + point2;

			Assert::AreEqual(point3.x, 12.0f && point3.y, 19.0f);
		}

		TEST_METHOD(TestMethod_operatorMinus)
		{
			Point2f point1, point2, point3;
			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point3 = point1 - point2;

			Assert::AreEqual(point3.x, -2.0f && point3.y, 3.0f);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point1 += point2;

			Assert::AreEqual(point1.x, 12.0f && point1.y, 19.0f);
		}

		TEST_METHOD(TestMethod_operatorMinusEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			point1 -= point2;

			Assert::AreEqual(point1.x, -2.0f && point1.y, 3.0f);
		}

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 5.0f;
			point2.y = 11.0f;

			Assert::IsTrue(point1 == point2);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			Assert::IsTrue(point1 != point2);
		}
		
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

		TEST_METHOD(TestMethod_distanceTo)
		{
			Point2f point1, point2;

			point1.x = 5.0f;
			point1.y = 11.0f;

			point2.x = 7.0f;
			point2.y = 8.0f;

			Assert::AreEqual(point1.distanceTo(point2), sqrt((point1.x - point2.x) * (point1.x - point2.x)) + ((point1.y - point2.y) * (point1.y - point2.y)));
		}

	};
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod_constructEmpty)
		{
			String s("world");
			
			Assert::IsTrue(s.size == 1);
			Assert::AreEqual(s.string, "");
		}

		TEST_METHOD(TestMethod_constructChain)
		{
			String s("%s", "hello");

			Assert::IsTrue(s.size == 6);
			Assert::AreEqual(s.string, "hello");
		}

		TEST_METHOD(TestMethod_constructChainClass)
		{
			String s("hello");
			String a(s);

			Assert::AreEqual(a.string, "hello");
		}

		TEST_METHOD(TestMethod_destructor)
		{
			String s("hello");
			s.~String();

			Assert::IsTrue(s.string[0] == '\0');
		}

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			String s("hello world");

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorEqualEqualClass)
		{
			String s("hello world");
			String a("hello world");

			Assert::IsTrue(s == a);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			String s("hello world");

			Assert::IsTrue(s != "bye");
		}

		TEST_METHOD(TestMethod_operatorNotEqualClass)
		{
			String s("hello world");
			String a("bye");

			Assert::IsTrue(s != a);
		}

		TEST_METHOD(TestMethod_operatorEqual)
		{
			String s("world");
			s.string = "hello";

			Assert::IsTrue(s.string == "hello");
		}

		TEST_METHOD(TestMethod_operatorEqualClass)
		{
			String s("hello");
			String a("world");
			a.string = s.string;

			Assert::IsTrue(a.string == s.string);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			String* s = new String("hello");

			*s += " world";

			Assert::IsTrue(s->string == "hello world");
		}

		TEST_METHOD(TestMethod_operatorPlusEqualClass)
		{
			String* s = new String("hello");
			String* a = new String(" world");

			*s += *a;

			Assert::AreEqual(s->string, "hello world");
		}

		TEST_METHOD(TestMethod_operatorLength)
		{
			String s("hello");

			Assert::IsTrue(s.length() == 5);
		}

		TEST_METHOD(TestMethod_operatorCapacity)
		{
			String s("hello");

			Assert::IsTrue(s.capacity() == 6);
		}

		TEST_METHOD(TestMethod_operatorGetString)
		{
			String s("hello");

			Assert::AreEqual(s.getString(), "hello");
		}

		TEST_METHOD(TestMethod_operatorClear)
		{
			String s("hello");
			s.clear();

			Assert::IsTrue(s.string[0] == '\0');
		}
	};
}