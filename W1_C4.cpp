#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ipfl;
	std::ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	int n;

	int tarr[100];
	int parr[100];

	ipfl >> n;

	for (int i = 0; i < n; i++)
	{
		ipfl >> tarr[i];
	}
	for (int i = 0; i < n; i++)
	{
		ipfl >> parr[i];
	}

	int max = 0;

	bool tarr_count = false;
	bool parr_count = false;

	for (int i = 0; i < n; i++)
	{
		if (tarr[i] > parr[i])
		{
			tarr_count = true;
			max += tarr[i];
		}
		else
		{
			parr_count = true;
			max += parr[i];
		}
	}

	if (!tarr_count)
	{
		int pind = 0;

		for (int i = 1; i < n; i++)
		{
			if (parr[i] < parr[i + 1] && parr[i] < parr[pind])
				pind = i;
			else if (parr[i + 1] < parr[i] && parr[i + 1] < parr[pind])
				pind = i + 1;
		}

		int max_1 = max - parr[pind];
		max_1 += tarr[pind];

		int tind = 0;

		for (int i = 1; i < n; i++)
		{
			if (tarr[i] > tarr[i + 1] && tarr[i] > tarr[tind])
				tind = i;
			else if (tarr[i + 1] > tarr[i] && tarr[i + 1] > tarr[tind])
				tind = i + 1;
		}

		int max_2 = max - parr[tind];
		max_2 += tarr[tind];

		max_1 > max_2 ? max = max_1 : max = max_2;
	}
	else if (!parr_count)
	{
		int tind = 0;

		for (int i = 1; i < n; i++)
		{
			if (tarr[i] < tarr[i + 1] && tarr[i] < tarr[tind])
				tind = i;
			else if (tarr[i + 1] < tarr[i] && tarr[i + 1] < tarr[tind])
				tind = i + 1;
		}

		int max_1 = max - tarr[tind];
		max_1 += parr[tind];

		int pind = 0;

		for (int i = 1; i < n; i++)
		{
			if (parr[i] > parr[i + 1] && parr[i] > parr[pind])
				pind = i;
			else if (parr[i + 1] > parr[i] && parr[i + 1] > parr[pind])
				pind = i + 1;
		}

		int max_2 = max - tarr[pind];
		max_2 += parr[pind];

		max_1 > max_2 ? max = max_1 : max = max_2;
	}

	opfl << max;

	ipfl.close();
	opfl.close();

	return 0;
}