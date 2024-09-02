#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 선택할 3개의 원소에 대응하는 마스크를 생성합니다.
    vector<bool> selectMask(n, false);
    fill(selectMask.end() - 3, selectMask.end(), true);  // 뒤에서부터 3개의 원소를 선택

    // 배열을 정렬하여 초기 상태 설정
    sort(arr.begin(), arr.end());
    int ans=0;
    do {
        // 현재 조합 출력
        int sum=0;
        for (int i = 0; i < n; i++) {
            if (selectMask[i]) {
                sum+=arr[i];
            }
        }
        if(sum==k)ans++;
    } while (next_permutation(selectMask.begin(), selectMask.end()));
    cout<<ans;
    return 0;
}