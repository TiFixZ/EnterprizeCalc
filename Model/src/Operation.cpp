#include "Operation.hpp"

#include "Calc.hpp"
#include "Logger.hpp"

namespace Model {
	Operation::Operation(std::string name) :name(name) {}

	std::string Operation::getName() const {
		return name;
	}

	double Operation::operator()(double a, double b) const {
		auto res{ execute(a,b) };
		putLog(name, a, b, res);
		return res;
	}

	void Operation::putLog(std::string name, double a, double b, double res) const {
		auto &temp{ Model::Calc::GetStenographer() };
		temp.takeRecord(name,  a,  b,  res);	
	}

}