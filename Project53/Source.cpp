#include <iostream>
// Vulfert Anton, Pi-192//

int main()
{
	setlocale(LC_ALL, "Ru");
	int rows;
	int cols;
	std::cout << "Enter the size of the array. Number of rows" << std::endl;
	std::cin >> rows;

	std::cout << "Enter the size of the array. Number of columns" << std::endl;
	std::cin >> cols;
	char **arr = new char*[rows]; // creating the main array to write to
	{
		arr[i] = new char[cols];
	}
	int **newArr = new int*[rows]; // creating an additional array to be edited
	for (int i = 0; i < rows; i++)
	{
		newArr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) // fill an additional array null
	{
		for (int j = 0; j < cols; j++)
		{
			newArr[i][j] = 0;
		}

	}

	system("cls");
	std::cout << "Заполните поле: " << std::endl;// fill main array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}

	}
	system("cls");// cleaning
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
	for (int i = 0; i < rows; i++)// output main array
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";

		}
		std::cout << std::endl;
	}
	std::cout << "________________" << std::endl;
	for (int i = 0; i < rows; i++)// output additional array
	{
		for (int j = 0; j < cols; j++)
		{
			if (newArr[i][j] >= 42) std::cout << "* ";
			else std::cout << newArr[i][j] << " ";

		}
		std::cout << std::endl;
	}

	//////////////////////////////////////////////////// clean Ram
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		delete[] newArr[i];
	}
	delete[] arr, newArr;

	system("pause");
}