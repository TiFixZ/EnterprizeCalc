#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <queue>
#include <fstream>
#include <list>
#include <mutex>
#include <string>


namespace Model {
	class Logger {
	public:
		Logger();
		void addRecord(std::string name, double a, double b, double res);
		using History = std::list<std::string>;
		History getCurrent();
		//History getAll();
		~Logger();
	private:
		std::list<std::string> actions;
		std::string logFilename;
		std::mutex mut;
	};
}
#endif // !LOGGER_HPP