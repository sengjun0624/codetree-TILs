#include <iostream>
#include <map>

using namespace std;
#define ll  long long
map<int, short> m;

ll factorial(int n) {
    if (n == 1)return 1;
    else n * factorial(n - 1);
}

ll permutation(int n, int k) {
    return factorial(n) / factorial(n - k);
}

int main() {
    // 여기에 코드를 작성해주세요.
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (m.find(num) == m.end()) {
            m[num] = 1;
        } else m[num]++;
    }
    //0으로 바꾸면
    ll ans = 0;
    for (auto pair: m) {
        // k-* 의 *이 first
        ll First = pair.first;
        // *의 갯수
        ll freq = pair.second;
        // k에서 뺀값 = *에서 X를 더하면 K가 되는수
        ll Second = k - First;
        // 같은 수를 더해서 k가 될때
        /*
         * 빈도수가 0이되면 다른애가 나를 집어도 0*0이 되는거아닌가
         */
        if (Second == First) {
            //k는 4, n=2
            ans += permutation(freq, 2);
            m[Second]=0;
        } else {
            if (m.find(Second) == m.end())continue; // map에 존재하지 않으면 pass
            ans += (freq * m[Second]); // *의 개수 * k-*의 개수
            m[First]=0;
            m[Second]=0;
        }

    }
    cout << ans;
    return 0;
}