#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int board[8][8];
int checked[8][8];
const int INF = 987654321;
int MIN = INF;
vector<int> cctv_dir[6] = { {},{0},{0,2},{0,3},{0,2,3},{0,1,2,3} };
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

struct info
{
	int y, x, type, dir;
};

vector<info> cctv;

int calc_safety()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (checked[i][j] == 0)
				sum++;
		}
	}
	return sum;
}

bool inRange(int y, int x)
{
	if (x<0 || y<0 || x>M - 1 || y>N - 1)
		return false;
	return true;
}

void see(int index, bool light)
{
	int dir = cctv[index].dir;
	int type = cctv[index].type;
	for (int i = 0; i < cctv_dir[type].size(); i++)
	{
		int y = cctv[index].y;
		int x = cctv[index].x;
		while (true)
		{
			y += dy[(cctv_dir[type][i] + dir) % 4];
			x += dx[(cctv_dir[type][i] + dir) % 4];
			if (!inRange(y, x) || board[y][x] == 6)
				break;
			if (light)
				checked[y][x] ++;
			else
				checked[y][x] --;
		}
	}
}

void bt(int index)
{
	if (index == cctv.size())
	{
		MIN = min(MIN, calc_safety());
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		see(index, true);
		bt(index + 1);
		see(index, false);
		cctv[index].dir++;
		cctv[index].dir %= 4;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
			{
				cctv.push_back(info{ i,j,board[i][j],0 });
				checked[i][j] ++;
			}
			else if (board[i][j] == 6)
				checked[i][j] ++;
		}
	}
	bt(0);
	cout << MIN;
}