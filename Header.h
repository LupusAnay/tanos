#pragma once
#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <math.h>
#include <exception>

using namespace std;

bool Gaussian_elimination(vector< vector<double> > input_matrix, vector<double> &roots);
bool InputFromConsole(int& number);
