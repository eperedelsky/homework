﻿#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter coordinates x, y" << endl;
	double x, y;
	cin >> x >> y;

	if (x < 0)
		if (x >= -1 && y*y <= 1)
			cout << "point is inside" << endl;
		else
			cout << "point isn't inside" << endl;
	else
		if (x*x + y * y <= 1)
			cout << "point is inside" << endl;
		else
			cout << "point isn't inside" << endl;

	return 0;
}

