#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dist[100001];
int INF = 987654321;

bool inRange(int x)
{
	if (x < 0 || x>100000)
		return false;
	return true;
}

void dijk()
{
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[here] < cost)
			continue;
		if (inRange(here + 1) && dist[here + 1] > cost + 1)
		{
			dist[here + 1] = cost + 1;
			pq.push(make_pair(cost + 1, here + 1));
		}
		if (inRange(here - 1) && dist[here - 1] > cost + 1)
		{
			dist[here - 1] = cost + 1;
			pq.push(make_pair(cost + 1, here - 1));
		}
		if (inRange(here * 2) && dist[here * 2] > cost)
		{
			dist[here * 2] = cost;
			pq.push(make_pair(cost, here * 2));
		}
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
		dist[i] = INF;
	dist[N] = 0;
	pq.push(make_pair(0, N));
	dijk();
	cout << dist[K];
}