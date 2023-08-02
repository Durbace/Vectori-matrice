#include <iostream>
void alocare(int& n, int*& v)
{
	std::cin >> n;
	v = new int[n];
}
void alocare_v3(int n1, int n2, int& n3, int*& v)
{
	n3 = n1 + n2;
	v = new int[n3];
}
void citire(int n, int*& v)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
}
void afisare(int n, int*& v)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << " ";
	}
}
void interclasare(int n1, int n2, int*& v1, int*& v2, int*& v3)
{
	int i = 0, j = n2 - 1, k = 0;
	while (i < n1 && j >-1)
	{
		if (v1[i] < v2[j])
		{
			v3[k] = v1[i];
			i++;
		}
		else
		{
			v3[k] = v2[j];
			j--;
		}
		k++;
	}
	if (i == n1)
		for (i = j; i >= 0; i--)
		{
			v3[k] = v2[i];
			k++;
		}
	else
		if (j == -1)
		{
			for (j = i; j < n1; j++)
			{
				v3[k] = v1[j];
				k++;
			}
		}
}
void dealocare(int n, int*& v)
{
	delete[] v;
}
int main()
{
	int* v1, * v2, * v3;
	int n1 = 0, n2 = 0, n3 = 0;
	alocare(n1, v1); alocare(n2, v2); alocare_v3(n1, n2, n3, v3);
	citire(n1, v1); citire(n2, v2);
	interclasare(n1, n2, v1, v2, v3);
	afisare(n3, v3);
	dealocare(n1, v1); dealocare(n2, v2); dealocare(n3, v3);
	return 0;
}
2)