#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
int dist[101][10001];
const int INF = 987654321;
vector<pair<int, pair<int, int> > > linked[101]; // ½Ã°£ µ· À§Ä¡  
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > empty;

void dijk()
{
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int money = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();
		if (here == N)
		{
			swap(pq, empty);
			break;
		}
		if (dist[here][money] < cost)
			continue;
		for (int i = 0; i < linked[here].size(); i++)
		{
			int there = linked[here][i].second.second;
			int nextD = cost + linked[here][i].first;
			int nextM = money + linked[here][i].second.first;
			if (nextM > M)
				continue;
			if (dist[there][nextM] > nextD)
			{
				dist[there][nextM] = nextD;
				pq.push(make_pair(nextD, make_pair(nextM, there)));
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	int u, v, c, d;
	while (T > 0)
	{
		//cout<<"A";
		cin >> N >> M >> K;
		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= M; j++)
			{
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> d;
			linked[u].push_back(make_pair(d, make_pair(c, v)));
		}
		dist[1][0] = 0;
		pq.push(make_pair(0, make_pair(0, 1)));
		dijk();
		int ans = INF;
		for (int i = 0; i <= M; i++)
		{
			ans = min(ans, dist[N][i]);
		}
		if (ans == INF)
			cout << "Poor KCM\n";
		else
			cout << ans << "\n";
		for (int i = 1; i <= N; i++)
		{
			linked[i].clear();
		}
		T--;
	}
}