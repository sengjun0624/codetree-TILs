#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int>um;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string cmd; cin>>cmd;
        if(um.find(cmd)==um.end())um[cmd]=1;
        else um[cmd]++;
    }
    auto it=um.begin();
    string ans; int Max=-1;
    while(it!=um.end()){
        if(it->second>Max){
            Max=it->second;
            ans=it->first;
        }
        it++;
    }
    cout<<Max;
    return 0;
}