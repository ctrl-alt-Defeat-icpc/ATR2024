#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int N = 1e5 + 5;
const int oo = 1e9 + 7;
int n, m;
pi s, t;
queue<pi> q;

int checkPre(vector<int> &pre) {
    if(pre[0] == pre[1] && pre[1] == pre[2]) return pre[0];
    return -1;
}

void newDis(pi v, vector<vector<char>> &matrix, vector<vector<int>> &dis, queue<pi> &q, vector<vector<vector<int>>> &pre, vector<vector<int>> &nxt, int ni, int nj, int dir) {
        if(ni < 0 || ni >= n || nj < 0 || nj >= m || matrix[ni][nj] == '#') return; // invalid area or wall
        // if(matrix[ni][nj] == '#') return; // wall
        int oi = v.first, oj = v.second; // old row and column
        int disHere = dis[oi][oj];
        if(checkPre(pre[oi][oj]) == dir) {
            if(disHere + 3 < dis[ni][nj] || (disHere + 3 == dis[ni][nj] && dir != pre[ni][nj][2] && nxt[ni][nj] != dir && nxt[ni][nj] != pre[ni][nj][2])) {
                dis[ni][nj] = disHere + 3;
                q.push({ni, nj});
                nxt[oi][oj] = dir;
                pre[ni][nj][0] = -1;
                pre[ni][nj][1] = pre[ni][nj][2] = dir;
            }
        }
        else if(disHere + 1 < dis[ni][nj] || (disHere + 1 == dis[ni][nj] && dir != pre[ni][nj][2] && nxt[ni][nj] != dir && nxt[ni][nj] != pre[ni][nj][2])) {
            dis[ni][nj] = disHere + 1;
            q.push({ni, nj});
            nxt[oi][oj] = dir;
            pre[ni][nj][0] = pre[oi][oj][1];
            pre[ni][nj][1] = pre[oi][oj][2];
            pre[ni][nj][2] = dir;
        }

}

/// pre: -1: not matter, 0: right, 1: down, 2: left, 3: up
void bfs(pi start, vector<vector<char>> &matrix, vector<vector<int>> &dis) {
    dis[start.first][start.second] = 0;
    q.push(start);

    
    vector<vector<int>> nxt(n, vector<int>(m, -1));
    vector<vector<vector<int>>> pre(n, vector<vector<int>>(m, vector<int>(3, -1)));

    while(!q.empty()) {
        pi v = q.front();
        q.pop();
        
        newDis(v, matrix, dis, q, pre, nxt, v.first, v.second + 1, 0);
        newDis(v, matrix, dis, q, pre, nxt, v.first + 1, v.second, 1);
        newDis(v, matrix, dis, q, pre, nxt, v.first, v.second - 1, 2);
        newDis(v, matrix, dis, q, pre, nxt, v.first - 1, v.second, 3);
    }
}

void Main() {
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<int>> dis(n, vector<int>(m, oo));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'S') s.first = i, s.second = j;
            else if(matrix[i][j] == 'T') t.first = i, t.second = j;
        }
    bfs(s, matrix, dis);
    if(dis[t.first][t.second] == oo) cout << -1 << endl;
    else cout << dis[t.first][t.second] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}
