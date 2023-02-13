#include <iostream>

int main()
{
    double number1 = 0, number2 = 0;
    char mathSign;
    bool userQuit = false;
    bool correctSignInput = true;

    std::cout << "Формат ввода: число знак число" << '\n';
    std::cin >> number1;
    while(!userQuit)
    {
        std::cin >> mathSign;
        switch (mathSign)
        {
            case 'Q':
                std::cout << number1 << '\n';
                userQuit = true;
                continue;

            case 'C':
                std::cout << "Калькулятор обнулен." << '\n';
                std::cin >> number1;
                continue;

            default:
                break;
        }
        std::cin >> number2;

        do
        {
            correctSignInput = true;
            switch (mathSign)
            {
                case '*':
                    number1 *= number2;
                    break;
                case '/':
                    if (number2 == 0)
                    {
                        std::cout << "Обнаружено деление на 0. Операция не выполняется" << '\n';
                        break;
                    }
                    number1 /= number2;
                    break;
                case '+':
                    number1 += number2;
                    break;
                case '-':
                    number1 -= number2;
                    break;
                default:
                    std::cout << "Неизвестный знак. Попробуйте еще раз." << '\n';
                    std::cout << "Новый знак: "; std::cin >> mathSign;
                    correctSignInput = false;
                    break;
            }
        } while(!correctSignInput);

        std::cout << number1 << '\n';
    }

    return 0;
}