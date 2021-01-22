#include "Header.h"

 bool Gaussian_elimination(vector< vector<double> > input_matrix, vector<double> &roots)
{
	int rows, columns;
	int i = 0, j = 0, max_row_index = 0;
	double temp;

	roots.resize(input_matrix.size());
	rows = input_matrix.size();
	columns = input_matrix.at(0).size();

	////Создание верхнетреугольной матрицы и нахождение числа корней
	for (j = 0; j < rows - 1; ++j)
	{
		//Поиск строки с максимальным элементом для данной строки
		for (i = j + 1; i < rows; ++i)
			if (fabs(input_matrix[i][j]) > fabs(input_matrix[j][j]))
				max_row_index = i;

		//Если такая строка нашлась, ставим ее на нужное место
		if (max_row_index != j)
			input_matrix[j].swap(input_matrix[max_row_index]);

		//Если элемент на главной диагонали ненулевой, приводим элементы в текущем столбце к нулю
		if (input_matrix[j][j] != 0)
		{
			temp = input_matrix[j][j];

			for (double& element : input_matrix[j])
				element /= temp;

			for (i = j + 1; i < rows; ++i)
			{
				temp = -input_matrix[i][j];

				for (int k = 0; k < columns; ++k)
					input_matrix[i][k] += input_matrix[j][k] * temp;
			}
		}
	}

	//// Проверка системы на вырожденность
	for (i = 0; i < rows; ++i)
	{
		bool zerorow = true;
		//Проверка на то, что все значения в строке—нулевые
		for (j = 0; j < columns - 1; ++j)
		{
			if (input_matrix[i][j] != double(0))
			{
				zerorow = false;
				break;
			}
		}

		if (zerorow && input_matrix[i][size_t(columns) - 1] != double(0))
		{
			//Система несовместна (нет решений)
			cout << "System is inconsistent.\n";
			roots.resize(0);
			return 0;
		}

		else if (zerorow && input_matrix[i][size_t(columns) - 1] == double(0))
		{
			//Система имеет бесконечное количество решений
			cout << "System has infinitely many solutions.\n";
			roots.resize(0);
			return 0;
		}
	}

	////Вычисление корней
	for (i = rows - 1; i >= 0; --i)
	{
		double sum = 0;
		for (j = rows - 1; j > i; --j)
			sum += roots[j] * input_matrix[i][j];
		roots[i] = (input_matrix[i][rows] - sum) / input_matrix[i][i];

		//Обработка погрешностей вычисления чисел с плавающей запятой
		if (fabs(roots[i]) <= numeric_limits<double>::epsilon())
			roots[i] = 0;
	}
	return 1;
}


bool InputFromConsole(int &number)
{
	int temp;
	cin >> temp;

	//Проверка введенного значения
	if (cin.fail() || cin.peek() != '\n' ||
		(numeric_limits<int>::max)() < temp ||
		(numeric_limits<int>::min)() > temp)
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Error: incorrect console input.\n";
		return 0;
	}
	
	if (temp < 1)
	{
		cout << "Error: number of rows must be more than 0.\n";
		return 0;
	}

	if (temp > 10)
	{
		cout << "Too many values. The programm will run too long.\n";
		return 0;
	}

	number = temp;
	return 1;
}

