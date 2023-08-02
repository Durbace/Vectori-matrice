#include <iostream>
#include <cmath>
#include<vector>
#include<fstream>
void alocare(int& nrows, int& ncols, int**& m)
{
	std::cin >> nrows >> ncols;
	m = new int* [nrows];
	for (int i = 0; i < nrows; i++)
		m[i] = new int[ncols];
}
void citire(int nrows, int ncols, int**& m)
{
	std::ifstream f(“fisier.txt”);
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			f >> m[i][j];
}
bool validare(int nrows, int ncols, int**& m, std::vector <int>& v)
{
	int col, nr;
	for (int j = 0; j < ncols; j++)
	{
		nr = 0;
		col = j;
		for (int i = 0; i < nrows; i++)
		{
			if (m[i][j] >= col + 2)
				return false;
			nr += m[i][j] * pow(col + 2, nrows - i - 1);
		}
		v.push_back(nr);
	}
	return true;
}
void afisare(int nrows, int ncols, int**& m, std::vector<int>v)
{
	if (validare(nrows, ncols, m, v) == true)
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
	else
		std::cout << "Matricea nu este valida.";
}
void dealocare(int nrows, int**& m)
{
	for (int i = 0; i < nrows; i++)
		delete[] m[i];
	delete[] m;
}
int main()
{
	int** m;
	std::vector<int>v;
	int nrows = 0, ncols = 0;
	alocare(nrows, ncols, m);
	citire(nrows, ncols, m);
	afisare(nrows, ncols, m, v);
	dealocare(nrows, m);
	return 0;
}