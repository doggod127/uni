#include <iostream>
#include <limits>

template<class T> void getUserInput(T &, char const *);

void firstTask(short *, float *);
void secondTask(bool *, const int *);

float calcSum(float *, short *);
void getArrayFromUser(bool *, int);
int countFalse(bool *, int);

short data_short_global;
float data_float_global;

const int array_size = 5;
bool array_global[array_size];

int main()
{
    float data_float;
    short data_short;
    float *data_float_ptr;
    short *data_short_ptr;

    const int * array_size_ptr = &array_size;
    bool array[array_size];

    bool user_quit = false;
    char user_menu_choice;

    while (!user_quit)
    {
        std::cout << "1. Задание 1" << "\n";
        std::cout << "2. Задание 2" << "\n";
        std::cout << "3. Выход" << "\n";
        getUserInput(user_menu_choice, "Ввод: ");

        switch (user_menu_choice)
        {
            case '1':
                std::cout << "Локальные переменные: " << "\n";
                getUserInput(data_short, "Short: ");
                getUserInput(data_float, "Float: ");
                data_short_ptr = &data_short;
                data_float_ptr = &data_float;
                firstTask(data_short_ptr, data_float_ptr);

                std::cout << "Глобальные переменные" << "\n";
                getUserInput(data_short_global, "Global short: ");
                getUserInput(data_float_global, "Global float: ");
                data_short_ptr = &data_short_global;
                data_float_ptr = &data_float_global;
                firstTask(data_short_ptr, data_float_ptr);

                break;
            case '2':
                std::cout << "Локальные переменные: " << "\n";
                getArrayFromUser(array, array_size);
                secondTask(array, array_size_ptr);

                std::cout << "Глобальные переменные" << "\n";
                getArrayFromUser(array_global, array_size);
                secondTask(array_global, array_size_ptr);
                break;
            case '3':
                user_quit = true;
                break;
            default:
                std::cout << "Некорректный ввод. Попробуйте еще раз" << "\n";
                break;
        }
        system("clear");
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

void firstTask(short * data_short_ptr, float *data_float_ptr)
{
    std::cout << "Сумма: " << calcSum(data_float_ptr, data_short_ptr) << "\n";
    std::cout << "Размер памяти под сумму: "
              << sizeof(calcSum(data_float_ptr, data_short_ptr)) << "\n";
    std::cout << "Рарзмер памяти под сумму после приведения к типу: "
              << sizeof((long int)calcSum(data_float_ptr, data_short_ptr)) << "\n";
}

float calcSum(float * data_float, short * data_short)
{
    return *data_float + (float)*data_short;
}

void secondTask(bool *array, const int *arr_size)
{
    std::cout << "Количество false: " << countFalse(array, *arr_size) << "\n";
}

void getArrayFromUser(bool *array, int arr_size)
{
    int user_input;
    bool user_input_is_correct;

    std::cout << "1 - true, 0 - false" << "\n";
    for(int i = 0; i < arr_size; i++)
    {
        std::cout << "a[" << i << "] = ";
        do
        {
            getUserInput(user_input, "");
            switch (user_input)
            {
                case 1:
                    array[i] = true;
                    user_input_is_correct = true;
                    break;
                case 0:
                    array[i] = false;
                    user_input_is_correct = true;
                    break;
                default:
                    std::cout << "Некорректный ввод. Попробуйте еще раз" << "\n";
                    user_input_is_correct = false;
                    break;
            }
        } while(!user_input_is_correct);
    }
}

int countFalse(bool *array, int arraySize)
{
    int counter = 0;
    for (int i = 0; i < arraySize; i++)
        if (!array[i]) counter++;

    return counter;
}