#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
#include <string>
#include <map>
#include <list>
#include "Operation.hpp"


namespace Model {
    class Stenographer {
    public:
        virtual void takeRecord(std::string name, double a, double b, double res) = 0;
    };
    class Сalculator {
    public:
        virtual std::map<std::string, Model::Operation *> getOperations()const = 0;
        virtual std::list<std::string> getHistori() = 0;
    };

    class OperationKeeper;
    class Logger;

    class Calc:public Stenographer,public Сalculator {
    private:
        Logger *logger;
        OperationKeeper *operationKeeper;
    protected:
        Calc();
        ~Calc();
        static Calc &GetInstance();
    public:
        Calc(Calc &other) = delete;
        void operator=(const Calc &) = delete;
        static Сalculator &GetСalculator();
        static Stenographer &GetStenographer();
       

        std::map<std::string, Model::Operation *> getOperations()const;
        std::list<std::string> getHistori();
        void takeRecord(std::string name, double a, double b, double res);
    };
}