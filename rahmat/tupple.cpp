#include <bits/stdc++.h>
using namespace std;

// Comparator to sort by the 2nd element (index 1)
bool compareBySecond(const tuple<int, char, double, string>& a,
                     const tuple<int, char, double, string>& b) {
    return get<1>(a) < get<1>(b);
}

int main() {
    vector<tuple<int, char, double, string>> quartet = {
        {1, 'b', 3.14, "Apple"},
        {2, 'a', 2.71, "Banana"},
        {3, 'c', 1.61, "Cherry"}
    };

    sort(quartet.begin(), quartet.end(), compareBySecond);

    for (const auto& q : quartet) {
        cout << get<0>(q) << " "
                  << get<1>(q) << " "
                  << get<2>(q) << " "
                  << get<3>(q) << "\n";
    }

    return 0;
}
