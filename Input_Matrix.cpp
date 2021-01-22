#include "Input_Matrix.h"

//Constructor
Input_Matrix::Input_Matrix(int rows_, int columns_) :
	rows(rows_), columns(columns_)
{
	input_matrix.resize(rows);
	for (auto& element : input_matrix)
		element.resize(columns);
}

//Reading values from file
bool Input_Matrix::FillFromFile(const char* path_)
{
	if (path_ == "")//Если не был передан путь
	{
		cout << "Enter path to file: ";
		cin >> path;

		//cout << "C:\Matrix.txt\n";
		//path = "C:\Matrix.txt";
	}
	else path = path_;

	file.open(path);
	if (!file.is_open())//Проверка открытия файла
	{
		cout << "Error: file was not opened.\n";
		return 0;
	}

	//Ввод значений из файла
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
		{
			if (!(file >> input_matrix[i][j]))
			{
				file.clear();
				cout << "Error: invalid data in file.\n";
				return 0;
			}
		}

	//Проверка на лишние значения после введенных
	int temp{ 0 };
	if (file >> temp || !file.eof())
	{
		file.clear();
		cout << "Error: invalid data in file.\n";
		return 0;
	}

	file.close();
	return 1;
}
