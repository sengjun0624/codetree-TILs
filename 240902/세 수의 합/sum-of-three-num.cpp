#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int target=k-arr[i];
        unordered_map<int,int>count;
        for(int j=i+1;j<n;j++){
            int diff=target-arr[j];
            ans+=count[diff];

            count[arr[j]]++;
        }
    }
    cout<<ans;
}