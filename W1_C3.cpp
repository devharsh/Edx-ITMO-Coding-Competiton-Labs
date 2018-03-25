#include <iostream>
#include <fstream>

using namespace std;

//int tbnc(int a, int b, int c, int n);

int main()
{
	ifstream ipfl;
	ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	int a, b, c, n;

	ipfl >> a >> b >> c >> n;
	//opfl << tbnc(a, b, c, n);

	if (n == 0)
		opfl << a;
	else if (n == 1)
		opfl << b;
	else if (n == 2)
		opfl << c;
	else
	{
		int ary[100001];

		ary[0] = a;
		ary[1] = b;
		ary[2] = c;

		int i = 3;

		while(i <= n)
		{
			ary[i] = ary[i - 1] + ary[i - 2] - ary[i - 3];
			i++;
		}

		opfl << ary[n];
	}

	ipfl.close();
	opfl.close();

	return 0;
}


//int tbnc(int a, int b, int c, int n)
//{
//	if (n == 0)
//		return a;
//	else if (n == 1)
//		return b;
//	else if (n == 2)
//		return c;
//	else if (n == 3)
//		return c + b - a;
//	else
//		return tbnc(a, b, c, n - 1) + b - a;
//}