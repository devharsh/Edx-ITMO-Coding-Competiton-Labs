#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ipfl;
	std::ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	int n;
	ipfl >> n;

	for (int i = 2; i < n; i++)
	{
		for (int j = i + 1; j < n + 1; j++)
		{
			if (j%i == 0)
				jdiv++;
		}
	}

	ipfl.close();
	opfl.close();

	return 0;
}