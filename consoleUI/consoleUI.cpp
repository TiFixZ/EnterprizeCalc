#include <iostream>

#include "..\View\src\Calc.hpp"

int main()
{
    View::Calc calc;
    while (true) {
        std::cout << "Simple calc\nIt can solve this task:\n";
        auto op = calc.getOperations();
        int i = 0;
        for (auto &el:op)
        {
            std::cout << ++i << " " << el << '\n';
        }
        std::cout << "plz enter first number";
        std::string A;
        std::cin >> A;
        std::cout << "plz enter second number";
        std::string B;
        std::cin >> B;
        std::cout << "plz enter operation symbol";
        std::string C;
        std::cin >> C;
        std::cout << "Your answer is: " << calc.operation(A, B, C) <<'\n';
        std::cout << "press q for exit:";
        char k = 0;
        std::cin >> k;
        if (k == 'q')break;
    }
}
