n, q = map(int, input().split())
server = [[] for _ in range(n)]

count = 0
for _ in range(q):
    text = input()
    if text[0] == 'a':
        a = int(text.split()[1])
        count += a
        server[0].append(a)
        print(count)

    else:
        for i in range(n-1, 0, -1):
            if server[i-1]:
                server[i].append(server[i-1][0])
                count += server[i-1][0]
                server[i - 1].pop(0)
        print(count)


'''
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // To ignore the newline character after `cin`.

    vector<vector<int>> server(n); // Initialize a vector of vectors
    int count = 0;

    for (int _ = 0; _ < q; ++_) {
        string text;
        getline(cin, text); // Read the full input line
        
        if (text[0] == 'a') { // Check if the command starts with 'a'
            int a;
            stringstream ss(text);
            string temp;
            ss >> temp >> a; // Extract the integer after 'a'
            
            count += a;
            server[0].push_back(a);
            cout << count << endl;

        } else { // Handle the "else" case
            for (int i = n - 1; i > 0; --i) {
                if (!server[i - 1].empty()) {
                    server[i].push_back(server[i - 1][0]);
                    count += server[i - 1][0];
                    server[i - 1].erase(server[i - 1].begin()); // Remove the first element
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}

'''









