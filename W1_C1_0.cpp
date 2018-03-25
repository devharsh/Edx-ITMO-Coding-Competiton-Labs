#include <iostream>

int main()
{
		errno_t err;
		FILE* infl;
		FILE* otfl;

		err = fopen_s(&infl, "input.txt", "r");
		err = fopen_s(&otfl, "output.txt", "w+");

		int a, b;

		fscanf_s(infl, "%d%d", &a, &b);
		fprintf(otfl, "%d\n", a + b);

	return 0;
}