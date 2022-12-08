#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string currentfull;
	bool contains = false, partII = false;
	int overlap = 0, halfpoint = 0, quarterpoint = 0;
	vector<int> elfone, elftwo;

	ifstream infile;
	infile.open("input.txt");
	while (!infile.eof())
	{
		contains = false;
		elfone.clear();
		elftwo.clear();

		getline(infile, currentfull);
		for (int i = 0; i < currentfull.size(); i++)
		{
			if (currentfull[i] == ',')
			{
				halfpoint = i;
			}
		}
		for (int i = 0; i < halfpoint; i++)
		{
			if (currentfull[i] == '-')
			{
				quarterpoint = i;
			}
		}
		elfone.push_back(stoi(currentfull.substr(0, quarterpoint)));
		elfone.push_back(stoi(currentfull.substr(quarterpoint + 1, halfpoint - 1)));

		for (int i = halfpoint + 1; i < currentfull.size(); i++)
		{
			if (currentfull[i] == '-')
			{
				quarterpoint = i;
			}
		}
		elftwo.push_back(stoi(currentfull.substr(halfpoint + 1, quarterpoint)));
		elftwo.push_back(stoi(currentfull.substr(quarterpoint + 1, currentfull.size() - 1)));

		if (partII)
		{
			if (elfone[0] <= elftwo[1] && elfone[1] >= elftwo[0])
			{
				contains = true;
			}
		}
		else
		{
			if (elfone[0] <= elftwo[0] && elfone[1] >= elftwo[1])
			{
				contains = true;
			}
			if (elfone[0] >= elftwo[0] && elfone[1] <= elftwo[1])
			{
				contains = true;
			}
		}

		if (contains)
		{
			overlap++;
		}
	}
	cout << overlap;
}