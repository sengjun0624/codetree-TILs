#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

using namespace std;

const int Max = 100001;
unordered_map<string, int> um;
string arr[Max];

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string cmd;
        cin >> cmd;
        um[cmd] = i;
        arr[i] = cmd;
    }
    for (int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;
       
        if (isalpha(cmd[0])) {
            cout << um[cmd] << "\n";
        } else {
            int idx = stoi(cmd);
            cout << arr[idx] << "\n";
        }
    }
    return 0;
}