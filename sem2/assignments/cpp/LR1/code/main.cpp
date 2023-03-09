#include <iostream>
#include <limits>

template<class T> void getUserInput(T &, char const *);

int main()
{
    double number1 = 0, number2 = 0;
    char mathSign;
    bool userQuit = false;
    bool correctSignInput = true;

    std::cout << "Формат ввода: число знак число" << '\n';
    getUserInput(number1, "");
    while(!userQuit)
    {
        getUserInput(mathSign, "");
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
        getUserInput(number2, "");

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

template<class T> void getUserInput(T &data, char const * message)
{
    std::cout << message;
    while(!(std::cin >> data))
    {
        std::cout << "Некорректный ввод. Попробуйте еще раз" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << message;
    }
}