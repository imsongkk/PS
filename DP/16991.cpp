#include <iostream>
#include <cstring>
#include <cmath>
#define ld double

using namespace std;


int N;
pair<ld, ld> pos[17];
ld cost[17][17];
ld cache[1 << 17][16];
const ld INF = 987654321;

ld func(int bit, int index)
{
	if (cache[bit][index] != -1.0)
		return cache[bit][index];
	if (bit == (1 << N) - 1)
		return cache[bit][index] = cost[index][0];
	ld ret = INF;
	for (int i = 0; i < N; i++)
	{
		if ((bit & (1 << i)) == 0)
			ret = min(ret, cost[index][i] + func(bit | (1 << i), i));
	}
	return cache[bit][index] = ret;
}

int main()
{
	cin >> N;
	ld a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		pos[i] = make_pair(a, b);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cost[i][j] = sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
		}
	}
	for (int i = 0; i < (1 << 17); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cache[i][j] = -1.0;
		}
	}
	printf("%.6lf", func(1, 0));

	return 0;
}