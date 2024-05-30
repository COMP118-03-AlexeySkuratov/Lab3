#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/Lab3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestUnitTestLab3
{
	TEST_CLASS(TestUnitTestLab3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			const double TEST = 10.0;
			double result = 0.0;
			
			// Act
			result = TEST + 5;

			// Assert
			Assert::AreEqual(15.0, result);

		}
	};
}
