#include "pch.h"
#include "CppUnitTest.h"

#include <limits>
#include <stdexcept>
#include "..\Model\src\RealOperations.hpp"
#include "..\Model\src\OperationKeeper.hpp"
#include "..\View\src\Calc.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ModelTest
{
	TEST_CLASS(Remainder)
	{
	public:
		TEST_METHOD(CorrectName) {
			Model::Remainder op;
			Assert::AreEqual(std::string("%"), op.getName());
		}

		TEST_METHOD(FractionalNumbers) {
			Model::Remainder op;
			Assert::AreEqual(1.5, op(7.5, 2.0), 0.000001);
			Assert::AreEqual(0.25, op(1.75, 0.5), 0.000001);
		}

		TEST_METHOD(NegativeNumbers) {
			Model::Remainder op;
			Assert::AreEqual(-1.0, op(-7.0, 3.0), 0.000001);
			Assert::AreEqual(1.0, op(7.0, -3.0), 0.000001);
			Assert::AreEqual(-1.0, op(-7.0, -3.0), 0.000001);
		}

		TEST_METHOD(ZeroDividend) {
			Model::Remainder op;
			Assert::AreEqual(0.0, op(0.0, 3.0), 0.000001);
			Assert::AreEqual(0.0, op(0.0, -3.0), 0.000001);
		}

		TEST_METHOD(ZeroDivisor) {
			Model::Remainder op;
			View::Calc calc;
			auto count = calc.getHistory().size();
			Assert::ExpectException<std::domain_error>([&] { op(7.0, 0.0); });
			Assert::ExpectException<std::domain_error>([&] { op(7.0, -0.0); });
			Assert::IsTrue(calc.getHistory().size() == count);
		}

		TEST_METHOD(NonFiniteNumbers) {
			Model::Remainder op;
			View::Calc calc;
			auto count = calc.getHistory().size();
			double values[] = {
				std::numeric_limits<double>::quiet_NaN(),
				std::numeric_limits<double>::infinity(),
				-std::numeric_limits<double>::infinity()
			};
			for (double value : values) {
				Assert::ExpectException<std::domain_error>([&] { op(value, 2.0); });
				Assert::ExpectException<std::domain_error>([&] { op(7.0, value); });
			}
			Assert::IsTrue(calc.getHistory().size() == count);
		}

		TEST_METHOD(Registered) {
			Model::OperationKeeper keeper;
			int count = 0;
			for (auto op : keeper.getOperations()) {
				if (op->getName() == "%") count++;
			}
			Assert::AreEqual(1, count);
			View::Calc calc;
			count = 0;
			for (const auto &name : calc.getOperations()) {
				if (name == "%") count++;
			}
			Assert::AreEqual(1, count);
		}

		TEST_METHOD(ViewAndHistory) {
			View::Calc calc;
			auto count = calc.getHistory().size();
			Assert::AreEqual(std::string("1.500000"), calc.operation("7.5", "2", "%"));
			auto history = calc.getHistory();
			Assert::IsTrue(history.size() == count + 1);
			Assert::AreEqual(std::string("7.500000%2.000000=1.500000"), history.back());
		}

		TEST_METHOD(ViewErrorsDoNotEnterHistory) {
			View::Calc calc;
			auto count = calc.getHistory().size();
			Assert::AreEqual(std::string("Division by zero"), calc.operation("7", "0", "%"));
			Assert::AreEqual(std::string("Division by zero"), calc.operation("7", "-0", "%"));
			Assert::AreEqual(std::string("Numbers must be finite"), calc.operation("nan", "2", "%"));
			Assert::AreEqual(std::string("Numbers must be finite"), calc.operation("7", "inf", "%"));
			Assert::IsTrue(calc.getHistory().size() == count);
		}

		TEST_METHOD(OldOperations) {
			View::Calc calc;
			Assert::AreEqual(std::string("10.000000"), calc.operation("7", "3", "+"));
			Assert::AreEqual(std::string("4.000000"), calc.operation("7", "3", "-"));
			Assert::AreEqual(std::string("21.000000"), calc.operation("7", "3", "*"));
			Assert::AreEqual(std::string("4.000000"), calc.operation("8", "2", "/"));
		}

		TEST_METHOD(DeleteThroughOperation) {
			class CheckedOperation :public Model::Remainder {
				bool &destroyed;
			public:
				CheckedOperation(bool &destroyed) :destroyed(destroyed) {}
				~CheckedOperation() override { destroyed = true; }
			};
			bool destroyed = false;
			Model::Operation *op = new CheckedOperation(destroyed);
			delete op;
			Assert::IsTrue(destroyed);
		}
	};
}
