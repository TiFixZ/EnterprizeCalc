#include "pch.h"
#include "CppUnitTest.h"



#include "..\Model\src\OperationKeeper.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ModelTest
{
	 
	TEST_CLASS(OperationKeeper)
	{
	public:

		TEST_METHOD(Creation) {
			Model::OperationKeeper();
		}
		TEST_METHOD(HasAddition) {
			Model::OperationKeeper q;
			auto temp = q.getOperations();
			bool check = false;
			for (const auto &el : temp) {
				if (el->getName() == std::string("+")) {
					check = true;
					break;
				}
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(HasSubstruction) {
			Model::OperationKeeper q;
			auto temp = q.getOperations();
			bool check = false;
			for (const auto &el : temp) {
				if (el->getName() == std::string("-")) {
					check = true;
					break;
				}
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(HasMultiply) {
			Model::OperationKeeper q;
			auto temp = q.getOperations();
			bool check = false;
			for (const auto &el : temp) {
				if (el->getName() == std::string("*")) {
					check = true;
					break;
				}
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(HasDivision) {
			Model::OperationKeeper q;
			auto temp = q.getOperations();
			bool check = false;
			for (const auto &el : temp) {
				if (el->getName() == std::string("/")) {
					check = true;
					break;
				}
			}
			Assert::IsTrue(check,L"Cant find division in operation list ");
		}
	};
	
}