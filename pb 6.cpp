#include <iostream>
#include <cmath>
#include<vector>
#include<fstream>
void alocare(int& height, int& width, int**& m)
{
	std::cin >> height >> width;
	m = new int* [height];
	for (int i = 0; i < height; i++)
		m[i] = new int[width];
}
void citire(int height, int width, int**& m)
{
	std::ifstream f(“fisier.txt”);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			f >> m[i][j];
}
void sum_max(int height, int width, int**& m)
{
	int max = 0, sus = 0, jos = 0, stanga = 0, dreapta = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (i < j && i + j < height - 1)
				sus += m[i][j];
			if (i<j && i + j>height - 1)
				dreapta += m[i][j];
			if (i > j && i + j > height - 1)
				jos += m[i][j];
			if (i > j && i + j < height - 1)
				stanga += m[i][j];
		}
	std::cout << std::max(std::max(sus, jos), std::max(dreapta, stanga));
}
void dealocare(int height, int**& m)
{
	for (int i = 0; i < height; i++)
		delete[] m[i];
	delete[] m;
}
int main()
{
	int** m;
	int height = 0, width = 0;
	alocare(height, width, m);
	citire(height, width, m);
	sum_max(height, width, m);
	dealocare(height, m);
	return 0;
}