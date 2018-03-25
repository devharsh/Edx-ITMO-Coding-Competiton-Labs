#include <iostream>
#include <fstream>
#include <map>
#include <math.h>

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
		int sd = static_cast<int>(sqrt(d)) + 1;
		for (int i = 1; i < sd; i++)
		{
			if (d % i == 0)
			{
				cur_div += 2;
				if (i*i == d)
					cur_div--;
			}
		}
		kmap.insert(std::pair<int, int>(d, cur_div));
	}

	int currentMax = 0;
	for (auto it = kmap.cbegin(); it != kmap.cend(); ++it)
	{
		if (it->second > currentMax)
			currentMax = it->second;
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

	opfl << k - minN + 1 << std::endl;

	opfl.close();
	return 0;
}