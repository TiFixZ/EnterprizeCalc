#include "pch.h"
#include "CppUnitTest.h"

#include "..\Model\src\RealOperations.hpp"
#include "..\Model\src\Operation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ModelTest
{
	namespace Operations {
		TEST_CLASS(Addition)
		{
		public:

			TEST_METHOD(Creation)
			{
				Model::Addition();
			}
			TEST_METHOD(InheritFromOperation)
			{
				Model::Operation * w = new Model::Addition();
				delete w;
			}
			TEST_METHOD(CorrectName)
			{
				Model::Operation *w = new Model::Addition();
				Assert::AreEqual("+", w->getName().c_str(),L"неправильное имя");
				delete w;
			}
			TEST_METHOD(ReturnCorrectAnswer)
			{
				Model::Operation *w = new Model::Addition();
				Assert::AreEqual(
					std::to_string(0.0), 
					std::to_string(w->operator()(0.0, 0.0)),
					L"Неверный ответ не 0"
				);
				Assert::AreEqual(
					std::to_string(10.0),
					std::to_string(w->operator()(5.0, 5.0)),
					L"Неверный ответ не не складывает числа"
				);
				Assert::AreEqual(
					std::to_string(0.0),
					std::to_string(w->operator()(5.0, -5.0)),
					L"Неверный ответ не не складывает числа"
				);
				Assert::AreEqual(
					std::to_string(0.0),
					std::to_string(w->operator()(-5.0, 5.0)),
					L"Неверный ответ не не складывает числа"
				);
				Assert::AreEqual(
					std::to_string(-10.0),
					std::to_string(w->operator()(-5.0, -5.0)),
					L"Неверный ответ не не складывает числа "
				);
				delete w;
			}
		};
		TEST_CLASS(Division)
		{
		public:

			TEST_METHOD(Creation)
			{
				Model::Division();
			}
			TEST_METHOD(InheritFromOperation)
			{
				Model::Operation *w = new Model::Division();
				delete w;
			}
			TEST_METHOD(CorrectName)
			{
				Model::Operation *w = new Model::Division();
				Assert::AreEqual("/", w->getName().c_str(), L"неправильное имя");
				delete w;
			}
			TEST_METHOD(ReturnCorrectAnswer)
			{
				Model::Operation *w = new Model::Division();
				Assert::AreEqual(
					std::to_string(0.0),
					std::to_string(w->operator()(0.0, 1.0)),
					L"Неверный ответ не 0"
				);
				Assert::AreEqual(
					std::to_string(1.0),
					std::to_string(w->operator()(5.0, 5.0)),
					L"Неверный ответ не делит числа"
				);
				Assert::AreEqual(
					std::to_string(-1.0),
					std::to_string(w->operator()(5.0, -5.0)),
					L"Неверный ответ не  делит числа"
				);
				Assert::AreEqual(
					std::to_string(-1.0),
					std::to_string(w->operator()(-5.0, 5.0)),
					L"Неверный ответ не не делит числа"
				);
				Assert::AreEqual(
					std::to_string(1.0),
					std::to_string(w->operator()(-5.0, -5.0)),
					L"Неверный ответ не делит числа"
				);
				delete w;
			}
		};
	}
}
