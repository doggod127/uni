#include "../headers/task_2.h"

void secondTask()
{
    char * init_str = new char [sizeof(TASK_STR)];
    strcpy(init_str, TASK_STR);
    std::string str(init_str);

    std::cout << "Строка до трансформации: " << str << std::endl;
    transformString(str);
    std::cout << "Строка после изменения: " << str << std::endl;

    delete[]init_str;
}

void transformString(std::string &str)
{
    std::string subStr("Zero");
    int subStrPos = str.find(subStr);
    std::reverse(subStr.begin(), subStr.end());
    str.replace(subStrPos, subStr.length(), subStr);
}
