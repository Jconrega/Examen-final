#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/Point2D.h"
#include "../Punt2D/Point2D.cpp"
#include "../Punt2D/String.h"
#include "../Punt2D/String.cpp"
#include "../Punt2D/Point2DTemplate.h"
#include "../Punt2D/DynArray.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(Point2DTest)
	{
	public:
		
		//Methods

		TEST_METHOD(IsZero)
		{
			Point2D p, p2, p3, p4;
			p.x = 0;
			p.y = 0;

			p2.x = 4;
			p2.y = 0;

			p3.x = 0;
			p3.y = 4;

			p4.x = 4;
			p4.x = 4;

			Assert::IsTrue(p.IsZero() && !p2.IsZero() && !p3.IsZero() && !p4.IsZero());

		}
		TEST_METHOD(SetZero)
		{
			Point2D p,p2;

			p.x = 4;
			p.y = 4;
			p.SetZero();

			p2.SetZero();

			Assert::IsTrue(p.IsZero() && p2.IsZero());

		}
		TEST_METHOD(DistanceTo)
		{
			Point2D p1, p2;
			p1.SetZero();
			p2.x = 3;
			p2.y = 4;
			
			Assert::IsTrue(p1.DistanceTo(p2) == 5);

		}

		//Operators

		TEST_METHOD(OperatorSum)
		{
			Point2D p,p2,p3;
			p.SetZero();
			p2.x = 4;
			p2.y = 5;

			p3 = p + p2;

			Assert::IsTrue(p3.x == 4 && p3.y == 5);

		}

		TEST_METHOD(OperatorSubtraction)
		{
			Point2D p, p2, p3;
			p.SetZero();
			p2.x = 4;
			p2.y = 5;

			p3 = p - p2;

			Assert::IsTrue(p3.x == -4 && p3.y == -5);

		}

		TEST_METHOD(OperatorSumEqual)
		{
			Point2D p, p2;
			p.x = 4;
			p.y = 1;

			p2.x = 1;
			p2.y = 4;

			p += p2;

			Assert::IsTrue(p.x == 5 && p.y == 5);

		}

		TEST_METHOD(OperatorSubtractionEqual)
		{
			Point2D p, p2;
			p.x = 4;
			p.y = 1;

			p2.x = 1;
			p2.y = 4;

			p -= p2;

			Assert::IsTrue(p.x == 3 && p.y == -3);

		}

		TEST_METHOD(OperatorEqual)
		{
			Point2D p, p2, p3;
			p.x = 4;
			p.y = 1;

			p2.x = 4;
			p2.y = 1;

			p3.x = 1;
			p3.x = 1;

			Assert::IsTrue(p==p2);
			Assert::IsFalse(p == p3);

		}
		TEST_METHOD(OperatorNoEqual)
		{
			Point2D p, p2, p3;
			p.x = 4;
			p.y = 1;

			p2.x = 4;
			p2.y = 1;

			p3.x = 1;
			p3.x = 1;

			Assert::IsTrue(p != p3);
			Assert::IsFalse(p != p2);

		}


	};

	TEST_CLASS(StringTest)
	{
	public:

		//Constructors

		TEST_METHOD(EmptyConst)
		{
			String s;
			
			Assert::IsTrue(s.Capacity() == 1);
		}

		TEST_METHOD(CharCConst)
		{
			char* c = "hola";
			String s(c);

			Assert::IsTrue(s.Capacity() == 5 && s.Length() == 4 && strcmp(c, s.GetString()) == 0 );
		}

		TEST_METHOD(StringConst)
		{
			String s("hola");
			String s2(s);

			Assert::IsTrue(s.Capacity() == 5 && s.Length() == 4 && strcmp(s2.GetString(), s.GetString()) == 0);
		}
		TEST_METHOD(OperatorEqualEqualChar)
		{
			char* c = "hola";
			String s(c);

			Assert::IsTrue(s==c);
		}
		TEST_METHOD(OperatorEqualEqualString)
		{
			String s("hola");
			String s2("hola");

			Assert::IsTrue(s == s2);
		}
		TEST_METHOD(OperatorNotEqualChar)
		{
			char* c = "hola";
			String s("bye");

			Assert::IsTrue(s != c);
		}
		TEST_METHOD(OperatorNotEqualString)
		{
			String s("hola");
			String s2("bye");

			Assert::IsTrue(s != s2);
		}
		TEST_METHOD(OperatorEqualChar)
		{
			char* c = "hola";
			String s("bye");
			String s2;

			s = c;
			s2 = c;

			Assert::IsTrue(s == c && s2 == c);
		}
		TEST_METHOD(OperatorEqualString)
		{
			String r("hola");
			String s("bye");
			String s2;

			s = r;
			s2 = r;

			Assert::IsTrue(s == r && s2 == r);
		}

		TEST_METHOD(OperatorSumEqualChar)
		{
			
			String s("s");

			s += "hola";
			Assert::IsTrue(strcmp(s.GetString(), "shola") == 0);
		}

		TEST_METHOD(OperatorSumEqualString)
		{
			
			String s("hey");
			String s2("bro");

			s += s2;

			Assert::IsTrue(strcmp(s.GetString(), "heybro") == 0);
		}

		TEST_METHOD(Lenght)
		{
			String s("hola");

			Assert::IsTrue(s.Length() == 4);
		}

		TEST_METHOD(Capacity)
		{
			String s("hola");

			Assert::IsTrue(s.Capacity() == 5);
		}
		TEST_METHOD(GetString)
		{
			String s("hola");

			Assert::IsTrue(strcmp(s.GetString(), "hola") == 0);
		}

		TEST_METHOD(Clear)
		{
			String s("hola");
			s.Clear();
			Assert::IsTrue(s.Capacity() == 1);
		}
		TEST_METHOD(Trim)
		{
			String s;
			char* c = "     hola     ";
			
			s.Trim(c);
			Assert::IsTrue(s.GetString()== "hola");

			
		}
		TEST_METHOD(SString_cut)
		{
			String s1("Hola mundo");
			s1.Cut(2, 5);
			Assert::AreEqual((int)strcmp("Houndo", s1.GetString()), 0);
			s1.Cut(3, 0);
			Assert::AreEqual((int)strcmp("Hou", s1.GetString()), 0);
		}

	};

	TEST_CLASS(PointTemplate){
	public:
		TEST_METHOD(PointInt)
		{
			Point2DTemplate<int> a, b;

			a.x = a.y = 5;
			b.SetZero();

			Assert::IsTrue(a != b);
		}
	};

	TEST_CLASS(DynArrayTest)
	{
	public:
		TEST_METHOD(DynArray_Operator_concat)
		{
			DynArray<int> array(5);
			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(4);
			array.PushBack(5);
			array.PushBack(8);

			DynArray<int> array2;
			array2.PushBack(991);
			array2.PushBack(992);
			array2.PushBack(993);
			array += array2;

			//Assert::AreEqual((int)array.Count(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}
	};

}