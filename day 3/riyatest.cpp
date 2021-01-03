#include <bits/stdc++.h>
using namespace std;
void circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    while(k>0){
        vector<int>::iterator i;
        i=a.begin();
        int count=0;
        while(count<a.size()-1){
            int temp=*i;
            a.erase(i);
            a.push_back(temp);
            count++;
        }
        k--;
    }
    vector<int> result;
    for(int i=0;i<queries.size();i++){
        result.push_back(a[queries[i]]);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\n";
    }
    
}
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> test(n);
    for(int i=0;i<n;i++){
        cin>>test[i];
    }    
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    } 
    circularArrayRotation(test,k,queries);
}