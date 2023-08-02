#include <iostream>
#include<fstream>
void alocareMemorie(int& n, float**& m)
{
	std::cin >> n;
	m = new float* [n];
	for (int i = 0; i < n; i++)
		m[i] = new float[n];
}
void citire(int n, float**& m)
{
	std::ifstream f(“fisier.txt”);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f >> m[i][j];
}
int aranjament(int n, float**& m)
{
	int min, max, k = 0, ok = 0;
	while (k != n / 2)
	{
		min = 999999; max = 0;
		for (int j = k; j < n - k; j++)
		{
			if (m[k][j] > max)
				max = m[k][j];
			if (m[n - 1 - k][j] > max)
				max = m[n - 1 - k][j];
		}
		for (int i = k; i < n - k; i++)
		{
			if (m[i][k] > max)
				max = m[i][k];
			if (m[i][n - 1 - k] > max)
				max = m[i][n - 1 - k];
		}
		for (int j = k + 1; j < n - k - 1; j++)
		{
			if (m[k + 1][j] < min)
				min = m[k + 1][j];
			if (m[n - k - 2][j] < min)
				min = m[n - k - 2][j];
		}
		for (int i = k + 1; i < n - k - 1; i++)
		{
			if (m[i][k + 1] < min)
				min = m[i][k + 1];
			if (m[i][n - k - 2] < min)
				min = m[i][n - k - 2];
		}
		if (max > min)
			ok = 1;
		k++;
	}
	if (ok == 0 && m[n / 2][n / 2] > max)
		return 0;
	else return 1;
}void inaltimea_medie(int n, int k, float**& m)
{
	float medie = 0;
	int nr = 0;
	for (int j = k - 1; j < n - k + 1; j++)
	{
		medie = m[k - 1][j] + medie + m[n - k][j]; nr = nr + 2;
	}
	std::cout << medie << ' ' << nr << std::endl;
	for (int i = k; i < n - k; i++)
	{
		medie = m[i][k - 1] + m[i][n - k] + medie; nr = nr + 2;
	}
	std::cout << medie << ' ' << nr << std::endl;
	medie = medie / nr;
	std::cout << medie;
}
void dealocare(int n, float**& m)
{
	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;
}
int main()
{
	float** m;
	int n = 0, k;
	std::cin >> k;
	alocareMemorie(n, m);
	citire(n, m);
	if (aranjament(n, m) == 0)
		std::cout << "ESTE CONSTRUCTIE PIRAMIDALA" << std::endl;
	else std::cout << "NU ESTE CONSTRUCTIE PIRAMIDALA" << std::endl;
	inaltimea_medie(n, k, m);
	dealocare(n, m);
	return 0;
}