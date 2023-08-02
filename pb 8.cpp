#include <iostream>
#include<vector>
void citire(int& n, std::vector<std::pair<int, int> >& v)
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::pair<int, int> element;
		std::cin >> element.first;
		std::cin >> element.second;
		v.push_back(element);
	}
}
void interval(int n, std::vector<std::pair<int, int> > v, int nr)
{
	int x, y, min = 999999;
	std::cin >> nr;
	for (int i = 0; i < n; i++)
	{
		if (nr >= v[i].first && nr <= v[i].second)
		{
			if (v[i].second - v[i].first < min)
			{
				min = v[i].second - v[i].first;
				x = v[i].first;
				y = v[i].second;
			}
		}
	}
	std::cout << x << ',' << y;
}
int main()
{
	int n = 0, nr = 0;
	std::vector<std::pair<int, int> > v;
	citire(n, v);
	interval(n, v, nr);
	return 0;
}