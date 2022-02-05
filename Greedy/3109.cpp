#include <iostream>
#include <string>

using namespace std;

int N, M;
string board[10000];
bool visited[10000][500];
int dy[3] = { -1,0,1 };
int cnt = 0;

bool inRange(int y, int x)
{
	if (x<0 || y<0 || x>M - 1 || y>N - 1)
		return false;
	return true;
}

bool dfs(int y, int x)
{
	//cout<<y<<' '<<x<<endl;
	if (x == M - 1)
	{
		cnt++;
		visited[y][x] = true;
		return true;
	}
	bool ret;
	for (int i = 0; i < 3; i++)
	{
		if (inRange(y + dy[i], x + 1) && board[y + dy[i]][x + 1] != 'x' && !visited[y + dy[i]][x + 1])
		{
			visited[y + dy[i]][x + 1] = true;
			if (dfs(y + dy[i], x + 1))
				return true;
		}
	}
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < N; i++)
	{
		//visited[i][0] = true;
		dfs(i, 0);
	}
	cout << cnt;
}