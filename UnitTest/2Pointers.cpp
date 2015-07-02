#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/List2P.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(List2PTest)
	{
	public:
		
		TEST_METHOD(Add2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);

			Assert::IsTrue(list.start->value == 4 && list.start->next->value == 5);
		}

		TEST_METHOD(Delete2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);

			list.Delete(list.end);

			Assert::IsTrue(list.end->value == 4 && list.Count() == 1);
		}

		TEST_METHOD(DeleteAll2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);
			list.Add(6);
			list.DeleteAll();

			Assert::IsTrue(list.end == list.start && list.Count() == 0);
		}
		TEST_METHOD(ListInsert)
		{
			List2P<int> mylist;
			List2P<int> mylist2;
			mylist2.Add(1);
			mylist2.Add(2);
			mylist2.Add(3);
			List2P<int> mylist3;
			mylist3.Add(4);
			mylist3.Add(5);
			mylist3.Add(6);
			mylist.InsertAfter(0, mylist2);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 3);
			mylist.InsertAfter(1, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 4);
			Assert::AreEqual(mylist[3], 5);
			Assert::AreEqual(mylist[4], 6);
			Assert::AreEqual(mylist[5], 3);
			mylist.InsertAfter(0, mylist3);
			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 4);
			Assert::AreEqual(mylist[2], 5);
			Assert::AreEqual(mylist[3], 6);
			Assert::AreEqual(mylist[4], 2);
			Assert::AreEqual(mylist[5], 4);
			Assert::AreEqual(mylist[6], 5);
			Assert::AreEqual(mylist[7], 6);
			Assert::AreEqual(mylist[8], 3);
			Assert::IsTrue((node<int>*) &mylist[0] == mylist.start);
			Assert::IsTrue((node<int>*) &mylist[8] == mylist.end);
		}
	};
}