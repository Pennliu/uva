#include <iostream>
#include <cstdio>

using namespace std;

static int matrix[102][102];

static bool check_matrix(int m[][102], int n)
{
	bool f = true;
	for (int i = 0; i < n; i++)
	{
		int sum_row = 0;
		int sum_col = 0;
		for (int j = 0; j < n; j++)
		{
			sum_row += m[i][j];
			sum_col += m[j][i];
		}
		if ((sum_row % 2) || (sum_col % 2))
		{
			f = false;
			break;
		}
	}
	return f;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		if (check_matrix(matrix, n)) {cout << "OK" << endl;continue;}
		bool f = false;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = !matrix[i][j];
				if (check_matrix(matrix, n))
				{
					f = true;
					x = i, y = j;
					break;
				}
				matrix[i][j] = !matrix[i][j];
			}
			if (f) break;
		}
		if (f) printf("Change bit (%d,%d)\n", x, y);
		else cout << "Corrupt" << endl;
	}
	return 0;
}
