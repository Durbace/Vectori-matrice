#include <iostream>
#include<vector>
#include<fstream>
struct Matrice
{
	int** matrice;
	int n, m;
};
void alocare(Matrice& matr, int& initial)
{
	std::cin >> matr.n >> matr.m;
	matr.matrice = new int* [matr.n * 2];
	initial = matr.n * 2;
	for (int i = 0; i < matr.n; i++)
		matr.matrice[i] = new int[matr.m];
}
void citire(Matrice& matr)
{
	std::ifstream f(“fisier.txt”);
	for (int i = 0; i < matr.n; i++)
		for (int j = 0; j < matr.m; j++)
			f >> matr.matrice[i][j];
}
int nrLiniiPare(Matrice matr)
{
	int nr = 0, ok;
	for (int i = 0; i < matr.n; i++)
	{
		ok = 1;
		for (int j = 0; j < matr.m; j++)
			if (matr.matrice[i][j] % 2 != 0)
			{
				ok = 0; break;
			}
		if (ok == 1)
			nr++;
	}
	return nr;
}
void afisare(Matrice& matr)
{
	int cnt = nrLiniiPare(matr);
	for (int i = 0; i < matr.n + cnt; i++)
	{
		for (int j = 0; j < matr.m; j++)
			std::cout << matr.matrice[i][j] << " ";
		std::cout << std::endl;
	}
}
void dublareLinie(Matrice& matr, int linie)
{
	for (int i = matr.n - 1; i > linie - 1; i--)
	{
		int* vector = new int[matr.m]();
		for (int j = 0; j < matr.m; ++j)
			vector[j] = matr.matrice[i][j];
		matr.matrice[i + 1] = new int[matr.m];
		for (int j = 0; j < matr.m; ++j)
			matr.matrice[i + 1][j] = vector[j];
		delete[] vector;
	}
	matr.n++;
}
void liniiPare(Matrice& matr)
{
	int ok = 1, cnt = 0;
	for (int i = 0; i < matr.n; i++)
	{
		ok = 1;
		for (int j = 0; j < matr.m; j++)
			if (matr.matrice[i][j] % 2 != 0)
			{
				ok = 0;
				break;
			}
		if (ok == 1)
		{
			dublareLinie(matr, i); i++;
		}
	}
}
void dealocare(Matrice& matr, int initial)
{
	for (int i = 0; i < matr.n; i++)
		delete[] matr.matrice[i];
	delete[] matr.matrice;
}
int main()
{
	Matrice matr;
	matr.n = 0; matr.m = 0;
	int initial = 0;
	alocare(matr, initial);
	citire(matr);
	liniiPare(matr);
	afisare(matr);
	dealocare(matr, initial);
	return 0;
}
