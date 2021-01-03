#include <bits/stdc++.h>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    //n number of prisoners
    //m represent number of candies
    //distribution of candies begin from this index
    int i=s;
    int count=0;
    while(count!=m && i<=n){
        i++;
        count++;
        if(i==n && count!=m){
            i=1;
        }
        if(count==m){
            break;
        }
    }
    return i;
}
int main(){
    int a=saveThePrisoner(7,19,2);
    cout<<a;
}