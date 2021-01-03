#include<bits/stdc++.h>
using namespace std;
//{100,90,90,80,75,60};{50,65,77,90,102};
void climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> result;
    vector<int>::iterator i;
    vector<int>::iterator j;
    for(i=player.begin();i!=player.end();i++){
        int count=1;
        //to remove the duplicate element from the ranked
        vector<int>::iterator ip; 
        ip=unique(ranked.begin(),ranked.end());
        ranked.resize(distance(ranked.begin(),ip));
        //100 90 80 75 60
        for(j=ranked.begin();j!=ranked.end();j++){
            if(*i<*min_element(ranked.begin(),ranked.end())){
                int a=*i;
                ranked.push_back(a);
                result.push_back(ranked.size());
                break;
            }
            else{
                if(*i>=*j){
                    int a=*i;
                    ranked.insert(j,a); 
                    result.push_back(count);
                    break;
                }
            }
            count++;
        }
    }
    cout<<result[0];
}
int main(){
    vector<int> ranked={100,90,90,80,75,60};
    vector<int> player={50,65,77,90,102};
    climbingLeaderboard(ranked,player);
}