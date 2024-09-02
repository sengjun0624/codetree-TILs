#include <iostream>
#include <map>
#include <climits>

using namespace std;

#define ll long long
map<ll, ll> frequencyMap;

ll calculatePairs(ll count) {
    if (count == 0) return 0;
    return count * (count - 1) / 2;
}

int main() {
    ll n, targetSum;
    cin >> n >> targetSum;

    // 숫자 입력 및 빈도수 계산
    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        frequencyMap[num]++;
    }

    ll pairCount = 0;

    for (auto element : frequencyMap) {
        ll number = element.first;
        ll count = element.second;
        ll complement = targetSum - number;

        // 같은 수를 더해서 targetSum이 되는 경우
        if (complement == number) {
            pairCount += calculatePairs(count);
            frequencyMap[complement] = 0; // 이미 계산된 수는 더 이상 처리하지 않음
        } else {
            if (frequencyMap.find(complement) == frequencyMap.end()) continue; // complement가 존재하지 않으면 pass
            pairCount += (count * frequencyMap[complement]); // 두 수의 빈도수 곱
            frequencyMap[number] = 0;
            frequencyMap[complement] = 0;
        }
    }

    cout << pairCount;
    return 0;
}