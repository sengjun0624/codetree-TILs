#include <iostream>
#include<unordered_map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
unordered_map<int,int>um;

int main() {
    // 여기에 코드를 작성해주세요.
    
    fastio();
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        int num; cin>>num;
        if(um.find(num)==um.end()){
            um[num]=1;
        }
        else um[num]++;
    }
    for(int i=0;i<m;i++){
        int quiz; cin>>quiz;
        if(um.find(quiz)==um.end()){
            cout<<0<<" ";
        }else cout<<um[quiz]<<" ";
    }

}