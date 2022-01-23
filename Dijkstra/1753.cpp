#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int V, E, K;
vector<pair<int, int> > list[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > pq;
int dist[20001];

void dijk()
{
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[here] < cost)
			continue;
		for (int i = 0; i < list[here].size(); i++)
		{
			int there = list[here][i].second;
			int nextD = cost + list[here][i].first;
			if (dist[there] > nextD)
			{
				dist[there] = nextD;
				pq.push(make_pair(nextD, there));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	cin >> K;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		list[u].push_back(make_pair(w, v));
	}
	pq.push(make_pair(0, K));
	for (int i = 0; i <= V; i++)
		dist[i] = 987654321;
	dist[K] = 0;
	dijk();
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != 987654321)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";
	}
}

