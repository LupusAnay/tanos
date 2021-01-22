#pragma once
#include "Header.h"

class Input_Matrix
{
private:
	string path;
	ifstream file;
	const int rows, columns;
	vector< vector<double> > input_matrix;

public:
	Input_Matrix(int rows_, int columns_);
	bool FillFromFile(const char *path_ = "");
	vector< vector<double> >& GetMatrix() { return input_matrix; }
};

