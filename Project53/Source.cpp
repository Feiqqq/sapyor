#include <iostream>
// Вульферт Антон, Пи-192//

int main()
{
	setlocale(LC_ALL, "Ru");
	int rows;// строка
	int cols;// стоблец
	std::cout << "Введите размер массива. Количество строк" << std::endl;
	std::cin >> rows;

	std::cout << "Введите размер массива. Количество столбцов" << std::endl;
	std::cin >> cols;
	char **arr = new char*[rows]; // создание основного массива, куда будет осуществляться записть
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols];
	}
	int **newArr = new int*[rows]; // создание доп.массива, который будет отредактирован
	for (int i = 0; i < rows; i++)
	{
		newArr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) //заполнение доп.массива нулями
	{
		for (int j = 0; j < cols; j++)
		{
			newArr[i][j] = 0;
		}

	}

	system("cls");
	std::cout << "Заполните поле: " << std::endl;// заполнение основного массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}

	}
	system("cls");//очистка экрана
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == '*') {
				newArr[i][j] = arr[i][j];
				if (i > 0) newArr[i - 1][j] += 1;
				if (j > 0) newArr[i][j - 1] += 1;
				if ((i > 0) && (j > 0)) newArr[i - 1][j - 1] += 1;
				if (i < (rows - 1)) newArr[i + 1][j] += 1;
				if (i < (cols - 1)) newArr[i][j + 1] += 1;
				if ((i < (rows - 1)) && (j < (cols - 1))) newArr[i + 1][j + 1] += 1;
				if ((i < (rows - 1)) && (j > 0)) newArr[i + 1][j - 1] += 1;
				if ((i > 0) && (j < (cols - 1))) newArr[i - 1][j + 1] += 1;
			}

		}

	}
	std::cout << rows << " " << cols << std::endl;
	std::cout << "________________" << std::endl;
	for (int i = 0; i < rows; i++)// вывод основного массива
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";

		}
		std::cout << std::endl;
	}
	std::cout << "________________" << std::endl;
	for (int i = 0; i < rows; i++)// вывод доп.массива
	{
		for (int j = 0; j < cols; j++)
		{
			if (newArr[i][j] >= 42) std::cout << "* ";
			else std::cout << newArr[i][j] << " ";

		}
		std::cout << std::endl;
	}

	//////////////////////////////////////////////////// очистка оперативной памяти
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		delete[] newArr[i];
	}
	delete[] arr, newArr;

	system("pause");
}