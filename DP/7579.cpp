#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int cache[101][10001];
int memory[101];
int cost[101];


int pick(int index, int c)
{
	if (index == N)
		return 0;
	if (cache[index][c] != -1)
		return cache[index][c];
	cache[index][c] = pick(index + 1, c);
	if (c - cost[index] >= 0)
		cache[index][c] = max(cache[index][c], pick(index + 1, c - cost[index]) + memory[index]);
	return cache[index][c];
}


int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> memory[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
	}
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i <= 10000; i++)
	{
		pick(0, i);
	}
	int ans = 987987;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (cache[i][j] >= M)
				ans = min(ans, j);
		}
	}
	cout << ans;
}