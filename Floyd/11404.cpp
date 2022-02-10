#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int N, M;
ll dist[101][101];
const ll INF = 13121110987654321L;

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			dist[i][j] = INF;
			if (i == j)
				dist[i][j] = 0;
		}
	}
	cin >> N;
	cin >> M;
	int a, b;
	ll c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
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
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}
}