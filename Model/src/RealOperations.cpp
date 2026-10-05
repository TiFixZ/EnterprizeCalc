#include "RealOperations.hpp"
#include <stdexcept>


namespace Model {

	Addition::Addition() :Operation("+") {}

	double Addition::execute(double a, double b) const {
		return a+b;

	}

	Subtraction::Subtraction() :Operation("-") {}

	double Subtraction::execute(double a, double b) const {
		return a - b;
	}

	Multiply::Multiply() :Operation("*") {}

	double Multiply::execute(double a, double b) const {
		return a*b;
	}

	Division::Division():Operation("/"){}

	double Division::execute(double a, double b) const {
		return a / b;
	}

	Remainder::Remainder() :Operation("%") {}

	double Remainder::execute(double a, double b) const {
		if (!std::isfinite(a) || !std::isfinite(b)) {
			throw std::domain_error("Numbers must be finite");
		}
		if (b == 0) {
			throw std::domain_error("Division by zero");
		}
		return std::fmod(a, b);
	}
  
	
}
