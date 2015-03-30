#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLIEN_JUDGE
	freopen("in", "r", stdin);
#endif
	long long n, k;
	while (cin >> n >> k)
	{
		long long cnt = 0;
		long long butts = 0;
		while (n)
		{
			cnt += n;
			butts += n;
			n = butts / k;
			butts = butts % k;
		}
		cout << cnt << endl;
	}
	return 0;
}
