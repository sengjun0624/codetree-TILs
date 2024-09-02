#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>>n>>k;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>check(n,0);
    check[0]=1;check[1]=1;check[2]=1;
    int ans=0;
    do{
        int sum=0;
        for(int i=0;i<n;i++){
            if(check[i]){
                sum+=v[i];
            }
        }
        if(sum==k)ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans/3;
    return 0;
}