#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

unordered_map<int,int>m;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    cin>> n>>k;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){

        int num; cin>>num;

        if(m.find(num)==m.end()){
            //map으로 숫자의 vector idx를 저장.
            //vector엔 숫자와 빈도수 저장.
            v.push_back({1,num});
            m[num]=v.size()-1;
        }else{
            int idx=m.find(num)->second;
            v[idx].first++; //이미 존재한다면 빈도수 올려주기
        }
    }
    //sort
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int l=v.size()>k?k:v.size();
    
    for(int i=0;i<l;i++){
        cout<<v[i].second<<" ";
    }


    return 0;
}