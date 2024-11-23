#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool compare1(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second.first > b.second.first;
}

void Main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<pair<int, pair<int, int>>> h(n, {0, {0, 0}});
    for (int i = 0; i < n; i++)
        cin >> h[i].second.first >> h[i].second.second;
    for (int i = 0; i < n; i++)
        h[i].first = h[i].second.first - h[i].second.second;

    sort(begin(h), begin(h) + n, compare1);

    int i;
    for (i = 0; i < m && i < n; i++)
        ans += h[i].second.first;
    for (; i < n; i++)
        ans += h[i].second.second;

    cout << ans << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}
