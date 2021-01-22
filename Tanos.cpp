#include "Header.h"
#include "Input_Matrix.h"

int main(int argc, char* argv[])
{
	try
	{
		int rows = 0;
		int columns = 0;

		cout << "Enter number of rows (number of columns must be one more): ";

		if (!InputFromConsole(rows))//Вызов подпрограммы считывания из консоли
			return 0;

		columns = rows + 1;

		Input_Matrix input_matrix(rows, columns);

		switch (argc)//Проверка количества введенных в командной строке аргументов
		{
		case 1:
		{
			if (!input_matrix.FillFromFile())
				return 0;
			break;
		}
		case 2:
		{
			if (!input_matrix.FillFromFile(argv[1]))
				return 0;
			break;
		}
		default:
		{
			cout << "Error: too many command line arguments.\n";
			exit(0);
		}
		};

		//Получение корней из функции
		vector <double> roots;
		if (!Gaussian_elimination(input_matrix.GetMatrix(), roots))
			return 0;

		//Вывод значений
		cout << "Roots:\n";
		for (int i = 0; i < roots.size(); ++i)
			cout << 'X' << i + 1 << " = " << roots.at(i) << endl;

		return 0;
	}

	//Обработка стандартных исключений
	catch (exception& e)
	{
		cout << "Error: " << e.what() << endl;
		return 0;
	}

	//Обработка всех остальных исключений
	catch (...)
	{
		cout << "Undefined error.\n";
		return 0;
	}
}

