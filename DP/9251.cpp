#include <cstring>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int cache[1001][1001];
string A, B;

int getAns(int a, int b)
{
	if (a > A.length() - 1 || b > B.length() - 1)
		return 0;
	if (cache[a][b] != -1)
		return cache[a][b];
	if (A[a] == B[b])
		return cache[a][b] = 1 + getAns(a + 1, b + 1);
	else
		return cache[a][b] = max(getAns(a + 1, b), getAns(a, b + 1));
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B;
	memset(cache, -1, sizeof(cache));
	cout << getAns(0, 0);
	return 0;
}