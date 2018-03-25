#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");

	int n;

	int tarr[100];
	int parr[100];

	ipfl >> n;

	for (int i = 0; i < n; i++)
		ipfl >> tarr[i];
	for (int i = 0; i < n; i++)
		ipfl >> parr[i];

	ipfl.close();

	bool tcnt = false, pcnt = false;
	int sum[5] = { 0,0,0,0,0 };

	for (int i = 0; i < n; i++)
	{
		if (tarr[i] > parr[i])
		{
			sum[0] += tarr[i];
			tcnt = true;
		}
		else
		{
			sum[0] += parr[i];
			pcnt = true;
		}
	}

	sum[1] = sum[0];
	sum[2] = sum[0];
	if (!tcnt)
	{
		int tmax = -1;
		int tmindiff = 1001;
		int tmxind = -1;

		for (int i = 0; i < n; i++)
		{
			if (tarr[i] >= tmax && parr[i] - tarr[i] < tmindiff)
			{
				tmax = tarr[i];
				tmindiff = parr[i] - tarr[i];
				tmxind = i;
			}
		}
		sum[1] -= parr[tmxind];
		sum[1] += tarr[tmxind];

		int pmin = 1001;
		int pmindiff = 1001;
		int pmnind = -1;

		for (int i = 0; i < n; i++ && parr[i] - tarr[i] < pmindiff)
		{
			if (parr[i] < pmin)
			{
				pmin = parr[i];
				pmindiff = parr[i] - tarr[i];
				pmnind = i;
			}
		}
		sum[2] -= parr[pmnind];
		sum[2] += tarr[pmnind];

		sum[0] = sum[1] > sum[2] ? sum[1] : sum[2];
	}

	sum[3] = sum[0];
	sum[4] = sum[0];
	if (!pcnt)
	{
		int pmax = -1;
		int pmindiff = 1001;
		int pmxind = -1;

		for (int i = 0; i < n; i++)
		{
			if (parr[i] > pmax && tarr[i] - parr[i] < pmindiff)
			{
				pmax = parr[i];
				pmindiff = tarr[i] - parr[i];
				pmxind = i;
			}
		}
		sum[3] -= tarr[pmxind];
		sum[3] += parr[pmxind];

		int tmin = 1001;
		int tmindiff = 1001;
		int tmnind = -1;

		for (int i = 0; i < n; i++)
		{
			if (tarr[i] < tmin && tarr[i] - parr[i] < tmindiff)
			{
				tmin = tarr[i];
				tmindiff = tarr[i] - parr[i];
				tmnind = i;
			}
		}
		sum[4] -= tarr[tmnind];
		sum[4] += parr[tmnind];

		sum[0] = sum[3] > sum[4] ? sum[3] : sum[4];
	}

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << sum[0];
	opfl.close();

	return 0;
}