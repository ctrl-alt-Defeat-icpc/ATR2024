#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int a, b;
void Main() {
    cin >> a >> b;
    cout << 3 << '\n' << -1000 << ' ' << b << ' ' << 3 * a - b + 1000 << endl;
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
