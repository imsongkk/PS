#include <iostream>
#include <cmath>

using namespace std;

int N, M, K;
int dist[251][251];
const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < 251; i++)
	{
		for (int j = 1; j < 251; j++)
		{
			dist[i][j] = INF;
			if (i == j)
				dist[i][j] = 0;
		}
	}
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (c == 0)
		{
			dist[a][b] = 0;
			dist[b][a] = 1;
		}
		else if (c == 1)
		{
			dist[a][b] = 0;
			dist[b][a] = 0;
		}
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}
}