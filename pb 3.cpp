#include <iostream>
#include<vector>
#include<tuple>
#include<string>
#include<algorithm>
#include<fstream>
void citire(int& n, std::vector<std::tuple<std::string, std::string, int, int, int> >& v)
{
	std::ifstream f("fisier.txt");
	f >> n;
	f.get();
	for (int i = 0; i < n; i++)
	{
		std::tuple<std::string, std::string, int, int, int>element;
		std::getline(f, std::get<0>(element));
		std::getline(f, std::get<1>(element));
		f >> std::get<2>(element);
		f >> std::get<3>(element);
		f >> std::get<4>(element);
		v.push_back(element);
		f.get();
	}
}
void afisare(std::vector<std::tuple<std::string, std::string, int, int, int> >v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << std::get<0>(v[i]) << " ";
		std::cout << std::get<1>(v[i]) << " ";
		std::cout << std::get<2>(v[i]) << " ";
		std::cout << std::get<3>(v[i]) << " ";
		std::cout << std::get<4>(v[i]) << " ";
		float medie = (std::get<2>(v[i]) + std::get<3>(v[i]) + std::get<4>(v[i])) / 3;
		if (medie < 5)
			std::cout << "Are media sub 5" << " ";
	}
}
bool comparaEvenimente(std::tuple<std::string, std::string, int, int, int>& element1,
	std::tuple<std::string, std::string, int, int, int>& element2)
{
	float medie1, medie2;
	medie1 = (std::get<2>(element1) + std::get<3>(element1) + std::get<4>(element1)) / 3;
	medie2 = (std::get<2>(element2) + std::get<3>(element2) + std::get<4>(element2)) / 3;
	return (medie1 > medie2);
}
int main()
{
	std::vector<std::tuple<std::string, std::string, int, int, int> >v;
	int n;
	citire(n, v);
	std::sort(v.begin(), v.end(), comparaEvenimente);
	afisare(v);
}