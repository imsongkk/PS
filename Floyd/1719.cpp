#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 987654321;
int N, M;
int dist[201][201];
int via[201][201];
vector<int> linked[201][201];

void reconstruct(int s, int e, int u, int v)
{
	if (via[u][v] == 0)
	{
		linked[s][e].push_back(u);
		linked[s][e].push_back(v);
		return;
	}
	reconstruct(s, e, u, via[u][v]);
	linked[s][e].pop_back();
	reconstruct(s, e, via[u][v], v);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			dist[i][j] = INF;
			if (i == j)
				dist[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					via[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
				reconstruct(i, j, i, j);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				cout << "- ";
			else
				cout << linked[i][j][1] << " ";
		}
		cout << "\n";
	}
}