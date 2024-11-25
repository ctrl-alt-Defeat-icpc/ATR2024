#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n, a[N], ans, sum, t, l, dp[N];

void Main() {
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] + a[i - 1];

    for(int i = 1; i <= n; i++) {
        if(dp[i] - dp[l] <= t) ans = max(ans, i - l);
        else while(dp[i] - dp[l] > t) l++;
    }
    cout << ans << endl;
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
