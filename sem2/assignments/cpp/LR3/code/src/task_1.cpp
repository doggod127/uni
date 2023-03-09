#include "../headers/task_1.h"

void firstTask()
{
    const int matrix_size = 6;
    printMatrix(matrix_size);
}

void printMatrix(int matrixLength)
{
    for (int i = 1; i <= matrixLength; i++)
    {
        for (int j = 1; j <= matrixLength; j++)
        {
            if (i == matrixLength - j + 1)
                std::cout << j;
            else
                std::cout << "?";

            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
