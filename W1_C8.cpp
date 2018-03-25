// https://github.com/devharsh/Edx-ITMO-Coding-Competiton-Labs/blob/master/W1_C8.cpp

#include <iostream>
#include <fstream>
#include <map>

// http://com.puter.tips/2018/03/c-array-declaration-stack-overflow.html
// int kar[10000000];

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");
	int k;
	ipfl >> k;
	ipfl.close();

	std::map<int, int> kmap;

	for (int d = 2; d <= k; d++)
	{
		int cur_div = 0;
		for (int i = 2; i <= d; i++)
		{
			if (d%i == 0)
			{
				cur_div++;
			}
		}
		kmap.insert(std::pair<int, int>(d, cur_div));
	}

	int currentMax = 0;
	for (auto it = kmap.cbegin(); it != kmap.cend(); ++it)
	{
		if (it->second > currentMax)
		{
			currentMax = it->second;
		}
	}

	int minN = -1;
	for (auto it = kmap.cbegin(); it != kmap.cend(); ++it)
	{
		if (it->second == currentMax)
		{
			minN = it->first;
			break;
		}
	}

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << k - minN + 1;
	opfl.close();
	return 0;
}