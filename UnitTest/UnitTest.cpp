#include "pch.h"
#include "CppUnitTest.h"
#include "../ModernCodingMnoshestvo/MegaSet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestOperator)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			int res = a[0];
			int expected = 1;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestRemove)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.remove(2);
			int res = a[1];
			int expected = 3;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestClear)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.clear();
			int res = a.size();
			int expected = 0;
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(TestAdd)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			MegaSet<int> b;
			b.insert(4);
			MegaSet<int> c;
			c = a.add(b);
			MegaSet<int> res = c;
			int expected[] = {1, 2, 3, 4};
			for (int i = 0; i < c.size(); ++i)
			{
				Assert::AreEqual(expected[i], res[i]);
			}
		}

		TEST_METHOD(TestDif)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			MegaSet<int> b;
			b.insert(3);
			MegaSet<int> c;
			c = a.dif(b);
			MegaSet<int> res = c;
			int expected[] = { 1, 2 };
			for (int i = 0; i < c.size(); ++i)
			{
				Assert::AreEqual(expected[i], res[i]);
			}
		}

		TEST_METHOD(TestMul)
		{
			MegaSet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			MegaSet<int> b;
			b.insert(3);
			b.insert(4);
			b.insert(2);
			MegaSet<int> c;
			c = a.mul(b);
			MegaSet<int> res = c;
			int expected[] = { 2, 3 };
			for (int i = 0; i < c.size(); ++i)
			{
				Assert::AreEqual(expected[i], res[i]);
			}
		}

	};
}
