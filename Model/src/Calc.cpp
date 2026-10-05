#include "Calc.hpp"
#include "Logger.hpp"
#include "OperationKeeper.hpp"
Model::Calc::Calc():
    logger(new Logger()),
    operationKeeper(new OperationKeeper())
{
}

Model::Calc::~Calc()
{
    delete logger;
    delete operationKeeper;
}

std::list<std::string> Model::Calc::getHistori() {
    return logger->getCurrent();
}


Model::Calc & Model::Calc::GetInstance() {
    static Calc instance;
    return instance;
}

Model::Сalculator &Model::Calc::GetСalculator() {
    return GetInstance();
}

Model::Stenographer &Model::Calc::GetStenographer() {
    return GetInstance();
}

void Model::Calc::takeRecord(std::string name, double a, double b, double res) {
    logger->addRecord(name, a, b, res);
}

std::map<std::string, Model::Operation *> Model::Calc::getOperations()const {
    std::map<std::string, Model::Operation *> result;
    for (auto &op : operationKeeper->getOperations()) {
        result.insert(std::pair(op->getName(), op));
    }
    return result;
}