#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <Windows.h>

std::vector<double> worker(double a[3], double b[3][3]) 
{
	std::vector<double> c;

	for (int i = 0; i < 3; i++) {
		c.push_back(0.0);

		for (int j = 0; j < 3; j++) {
			c.at(i) += a[j] * b[j][i];
		}
	}

	return c;
}

int main()
{
	return 0;
	system("PAUSE");
}