#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
//$(SolutionDir)\bin\$(ProjectName)\$(Configuration)\
//$(SolutionDir)\bin\$(ProjectName)\$(Configuration)\intermediate\

#include <string>
#include <list>
#include <map>
#include "..\..\Model\src\Calc.hpp"


namespace View {
	class Calc {
	public:
		Calc();
		std::list<std::string> getOperations()const;
		std::string operation(
			std::string A, 
			std::string B, 
			std::string operation)const;
		std::list<std::string> getHistory()const;
	private:
		std::map<std::string, Model::Operation *> operations;
		Model::Сalculator &model;
	};
}