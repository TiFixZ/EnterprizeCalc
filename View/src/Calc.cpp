#include "Calc.hpp"
#include <cstdlib>

namespace View {
	
	Calc::Calc():model(Model::Calc::GetСalculator())
	{
		operations = model.getOperations();
	}

	std::string Calc::operation(std::string A, std::string B, std::string operation) const
	{
		//проверка А
		//проверка В
		//проверка что ключ соответсвует списку
		double a{ ::atof(A.c_str()) }, b{ ::atof(B.c_str()) };
		double result{ 0 };
		try {
			result = operations.at(operation)->operator()(a, b);
		}
		catch (std::exception &ex) {
			return ex.what();
		}
		return std::to_string(result);
	}

	std::list<std::string> Calc::getOperations() const {
		std::list<std::string> result;
		for (const auto &[key, _] : operations) {
			result.push_back(key);
		}
		//альтернатива с использованием библиотеки algorithm
		//std::transform(operations.begin(), operations.end(), std::back_inserter(result),
		//               [](decltype(operations)::value_type const &pair) {
		//                   return pair.first;
		//               });
		return result;
	}

	std::list<std::string> Calc::getHistory() const {
		return model.getHistori();
	}
}
//ui -> service -> bl -> dal