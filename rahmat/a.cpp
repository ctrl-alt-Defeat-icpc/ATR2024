#include <bits/stdc++.h>
using namespace std;

#define ll long long
int visited[10], temp;
void Main() {
    for(int i = 0; i < 4; i++) {
        cin >> temp;
        visited[temp] = 1;
    }
    for(int i = 1; i <= 5; i++) {
        if(!visited[i]) {
            cout << i << endl;
            return;
        }
    }
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
