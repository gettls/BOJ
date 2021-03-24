#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#pragma warning (disable:4996)
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int R, C, v[26];
char arr[20][20];
int result;


void dfs(int x, int y, int cnt) {
	if (v[arr[x][y]-'A'] == 1) {
		result = max(result, cnt-1);
		return;
	}
	v[arr[x][y]-'A'] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		dfs(nx, ny, cnt + 1);	
	}
	v[arr[x][y] - 'A'] = 0;
}


int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &arr[i][j]);
		}
	}

	dfs(0, 0, 1);


	cout << result;
}