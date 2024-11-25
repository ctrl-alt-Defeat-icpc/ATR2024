#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int N = 2e5 + 5;
const int MAXLINES = 1e4 + 5;
const int oo = 1e9;

int n, m, ans;
string s[MAXLINES];
pair<int, int> beg, ed;
int dis[N][4][4];
bool vis[N][4][4];
queue<array<int, 4>> q;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
// directions: down(0) | right(1) | up(2) | left(3)

void Main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) { // input
        cin >> s[i]; s[i] = " " + s[i]; // for starting from 1
        for(int j = 1; j <= m; j++)
            if(s[i][j] == 'S') beg.first = i, beg.second = j;
            else if(s[i][j] == 'T') ed.first = i, ed.second = j;
    }

    q.push({beg.first, beg.second, 0, 0}); // start from S location | direction isn't manner | num of duplicate previues dir 0
    vis[beg.first * m + beg.second][0][0] = 1;
    while(!q.empty()) {
        auto current = q.front(); q.pop();
        int x = current[0], y = current[1], dir = current[2], p = current[3];
        for(int i = 0; i < 4; i++) {  // iterate all directions
            int xx = x + dx[i]; // new x position
            int yy = y + dy[i]; // new y position
            int pp = (i == dir ? p + 1 : 1); // new number of duplicate previues direction
            if(s[xx][yy] == '#' || pp > 3 || vis[xx * m + yy][i][pp]) // invalid or visited position
                continue;
            dis[xx * m + yy][i][pp] = dis[x * m + y][dir][p] + 1;
            vis[xx * m + yy][i][pp] = 1; // new position visited
            q.push({xx, yy, i, pp});
        }
    }

    ans = oo;
    for(int i = 0; i < 4; i++) // iterate all directions
        for(int j = 0; j <= 3; j++) // iterate for all dup. pre. dir. (can 0, 1, 2, 3)
            if(vis[ed.first * m + ed.second][i][j]) // only visited position can be answer
                ans = min(ans, dis[ed.first * m + ed.second][i][j]);

    cout << (ans > 1e8 ? -1 : ans) << '\n'; // print answer
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
