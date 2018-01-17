#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <windows.h>
#include <string>
#include "Worker\Worker.cpp"
#include <sstream>
#include <iterator>
#include <cctype>
#include <algorithm>

std::string Transformer(double d)
{
	std::ostringstream doubleStr;
	doubleStr << d;
	return doubleStr.str();
}

void coordinator() 
{
	STARTUPINFO startInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startInfo, sizeof(startInfo));
	startInfo.cb = sizeof(startInfo);
	ZeroMemory(&processInfo, sizeof(processInfo));
	// matrices
	double a[3][3] = { 3, 1, 2,
		6, 5, 1,
		4, 0, 1 };

	double b[3][3] = { 5, 3, 2,
		0, 8, 3,
		4, 1, 2 };

	double c[3][3];

	std::vector<double> r;

	
	for (int i = 0; i < 3; i++) 
	{
		r = worker(a[i], b);
		std::vector<std::string> doubleStr;
		std::transform(r.begin(), r.end(), std::back_inserter(doubleStr), Transformer);
		std::copy(doubleStr.begin(), doubleStr.end(), std::ostream_iterator<std::string>(std::cout, " "));
		CreateProcess("C:/Users/jocon/Desktop/Games-Engineering/Processes(CoordinatorAndWorker)/Processes/Worker/Debug/Worker.exe", r, NULL, NULL, false, 0, NULL, NULL, &startInfo, &processInfo);

		for (int j = 0; j < 3; j++) 
		{
			c[i][j] = r.at(j);

			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
		r.clear();
	}
}