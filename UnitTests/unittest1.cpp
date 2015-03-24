#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programacio2/Point2f.cpp"
#include "../Programacio2/Projectile.h"
#include "../Programacio2/Point2fTemplate.h"
#include "../Programacio2/String.cpp"
#include "../Programacio2/p2SString.h"
#include "../Programacio2/DynamicArray.h"
#include "../Programacio2/p2List.h"
#include "../Programacio2/DoubleLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
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
			String s;

			Assert::IsTrue(s.size == 1);
			Assert::AreEqual(s.string, "\0");
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

		/*TEST_METHOD(TestMethod_destructor)
		{
			String s("hello");
			s.~String();

			Assert::IsTrue(s.string == NULL);
		}*/

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
			s = "hello";

			Assert::IsTrue(s == "hello");
		}

		TEST_METHOD(TestMethod_operatorEqualClass)
		{
			String s("hello");
			String a("world");
			a = s;

			Assert::IsTrue(a == s);
		}

		TEST_METHOD(TestMethod_operatorPlusEqual)
		{
			String s("hello");

			s += " world";

			Assert::IsTrue(s == "hello world");
		}

		TEST_METHOD(TestMethod_operatorPlusEqualClass)
		{
			String s("hello");
			String a(" world");

			s += a;

			Assert::IsTrue(s == "hello world");
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

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(DynArray_ctor)
		{
			DynArray<int> array;
			Assert::AreEqual((int)array.getCapacity(), NULL);
		}

		TEST_METHOD(DynArray_ctor_capacity)
		{
			DynArray<int> array(33);
			Assert::AreEqual((int)array.getCapacity(), 33);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 3);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			int a, b;

			Assert::IsTrue(array.pop(a));
			Assert::IsTrue(array.pop(b));

			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 1);
			Assert::AreEqual(a, 3);
			Assert::AreEqual(b, 2);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			array.clear();

			Assert::AreEqual((int)array.getCapacity(), 3);
			Assert::AreEqual((int)array.count(), 0);
		}


		TEST_METHOD(DynArray_op)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
		}

		TEST_METHOD(DynArray_at)
		{
			DynArray<int> array;

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			Assert::AreEqual(*(array.at(0)), 1);
			Assert::AreEqual(*(array.at(1)), 2);
			Assert::AreEqual(*(array.at(2)), 3);
			Assert::IsNull(array.at(3));
		}

		TEST_METHOD(DynArray_resize)
		{
			DynArray<int> array;

			for (int i = 0; i < 999; ++i)
			{
				array.pushBack(i);
			}

			Assert::AreEqual(*(array.at(900)), 900);
			Assert::IsNull(array.at(1000));

			Assert::AreEqual((int)array.getCapacity(), 999);
			Assert::AreEqual((int)array.count(), 999);
		}

		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> array;

			for (int i = 0; i < 16; ++i)
			{
				array.pushBack(i);
			}

			array.insert(999, 3);
			array.insert(888, 17);
			array.insert(777, 50);

			Assert::IsFalse(array.insert(777, 50));
			Assert::AreEqual((int)array.getCapacity(), 18);
			Assert::AreEqual((int)array.count(), 18);
			Assert::AreEqual((int)array[3], 999);
			Assert::AreEqual((int)array[17], 888);
		}
	};
}

namespace UnitTestExam
{
	TEST_CLASS(UnitTestExam)
	{
	public:
		TEST_METHOD(Projectile_test)
		{
			Projectile/*<float>*/ p;
			p.point.x = 10.0f;
			p.point.y = 10.0f;
			p.speed.x = 2.0f;
			p.speed.y = 0.0f;
			Point2f/*Template<float>*/ current = p.getCurrentPosition(3.0f);
			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}
		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynArray<int> array(10);
			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);
			Assert::AreEqual((unsigned int)10, array.getCapacity());
			unsigned int wasted = array.removeWastedMemory();
			Assert::AreEqual((unsigned int)3, array.getCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_mid)
		{
			p2List<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(1, 2);
			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_begin)
		{
			p2List<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(0, 3);
			Assert::AreEqual((int)4, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)1, l.count());
		}
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_end)
		{
			p2List<int> l;
			l.add(1);
			l.add(2);
			l.add(3);
			l.add(4);
			l.delNodes(2, 100);
			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)2, l.end->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}
		TEST_METHOD(String_prefix)
		{
			p2SString a("1234567890");
			p2SString b(50);
			b = "hola";
			a.prefix(b);
			b.prefix("1234567890");
			Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
		}

		// String prefix ----------------------------------------
		/*TEST_METHOD(String_prefix)
		{
			String a("1234567890");
			String b(50);
			b = "hola";
			a.prefix(b);
			b.prefix("1234567890");
			Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
		}*/
	};
}