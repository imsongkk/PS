#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int G, P;
int parent[1000001];
int height[1000001];
int arr[1000001];

int find(int u)
{
	if (parent[u] == u)
		return u;
	if (parent[u] == -1)
		return -1;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) // u < v이다
{
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (height[u] > height[v])
		parent[v] = u;
	else if (height[u] < height[v])
		parent[u] = v;
	else
	{
		parent[u] = v;
		height[v] ++;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> G;
	cin >> P;
	//parent[0] = -1;
	for (int i = 1; i <= G; i++)
	{
		parent[i] = i;
		height[i] = 1;
	}
	for (int i = 1; i <= P; i++)
	{
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 1; i <= P; i++)
	{
		int root = find(arr[i]); // 루트를 찾는다
		if (root == -1)
			break;
		if (root == 1)
		{
			parent[1] = -1;
			cnt++;
			continue;
		}
		parent[root] = find(root - 1);
		cnt++;
	}
	cout << cnt;
	return 0;
}