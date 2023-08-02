#include <iostream>
void alocare(int& n, int*& v)
{
	std::cin >> n;
	v = new int[n];
}
void alocareFr(int*& fr)
{
	fr = new int[5];
}
void citire(int n, int*& v)
{
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
}
int cifPar(int nr, int*& v)
{
	int* fr;
	int p = 1, n = 0;
	alocareFr(fr);
	for (int i = 0; i < 5; i++)
		fr[i] = 0;
	for (int i = 0; i < nr; i++)
	{
		if (v[i] == 0)
			fr[0]++;
		while (v[i])
		{
			if (v[i] % 2 == 0)
				fr[(v[i] % 10) / 2]++;
			v[i] /= 10;
		}
	}
	for (int i = 4; i >= 0; i--)
		while (fr[i])
		{
			n = n * 10 + i * 2; fr[i]--;
		}
	delete[] fr;
	return n;
}
void dealocare(int n, int*& v)
{
	delete[] v;
}
int main()
{
	int* v;
	int nr = 0;
	alocare(nr, v);
	citire(nr, v);
	std::cout << cifPar(nr, v);
	dealocare(nr, v);
	return 0;
}
