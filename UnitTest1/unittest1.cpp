#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.cpp"
#include "../Programacio2/String.cpp"
#include "../Programacio2/Point2fTemplate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPoint2f
{		
	TEST_CLASS(UnitTestPoint2f)
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

namespace UnitTestString
{
	TEST_CLASS(UnitTestString)
	{
	public:

		TEST_METHOD(TestMethod_constructEmpty)
		{
			String* s = new String();
			
			Assert::IsTrue(s->size == 1);
			Assert::AreEqual(s->string, "");
		}

		TEST_METHOD(TestMethod_constructChain)
		{
			String* s = new String("%s", "hello");

			Assert::IsTrue(s->size == 6);
			Assert::AreEqual(s->string, "hello");
		}

		TEST_METHOD(TestMethod_constructChainClass)
		{
			String* s = new String("hello");
			String* a = new String(*s);

			Assert::AreEqual(a->string, "hello");
		}

		TEST_METHOD(TestMethod_destructor)
		{
			String s = "hello";
			s.~String();

			Assert::IsTrue(s.string == NULL);
		}

		TEST_METHOD(TestMethod_operatorEqualEqual)
		{
			String* s = new String("hello world");

			Assert::IsTrue(*s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorEqualEqualClass)
		{
			String* s = new String("hello world");
			String* a = new String("hello world");

			Assert::IsTrue(*s == *a);
		}

		TEST_METHOD(TestMethod_operatorNotEqual)
		{
			String s = "hello world";

			Assert::IsTrue(s != "bye");
		}

		TEST_METHOD(TestMethod_operatorNotEqualClass)
		{
			String* s = new String("hello world");
			String* a = new String("bye");

			Assert::IsTrue(*s != *a);
		}

		TEST_METHOD(TestMethod_operatorEqual)
		{
			String* s = new String();
			s->string = "hello";

			Assert::IsTrue(s->string == "hello");
		}

		TEST_METHOD(TestMethod_operatorEqualClass)
		{
			String* s = new String("hello");
			String* a = new String();
			a->string = s->string;

			Assert::IsTrue(a->string == s->string);
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
			String* s = new String("hello");

			Assert::IsTrue(s->length() == 5);
		}

		TEST_METHOD(TestMethod_operatorCapacity)
		{
			String* s = new String("hello");

			Assert::IsTrue(s->capacity() == 6);
		}

		TEST_METHOD(TestMethod_operatorGetString)
		{
			String* s = new String("hello");

			Assert::AreEqual(s->getString(), "hello");
		}

		TEST_METHOD(TestMethod_operatorClear)
		{
			String* s = new String("hello");
			s->clear();

			Assert::IsTrue(s->string[0] == '\0');
		}
	};
}

namespace UnitTestPoint2fTemplate
{
	TEST_CLASS(UnitTestPoint2fTemplate)
	{
	public:
		
		TEST_METHOD(TestMethod_Point2fTemplateInt)
		{
			Point2fTemplate<int> a;
			Point2fTemplate<int> b;

			a.x = a.y = 5;
			b = a;

			Assert::AreEqual(b.x, 5);
			Assert::AreEqual(b.y, 5);
		}
	};
}