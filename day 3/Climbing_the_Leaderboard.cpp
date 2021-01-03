#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
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
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
/*
#include <bits/stdc++.h>
//riya solution
using namespace std;
void check(long long int arr[1000000],long long int newtotal,long long int total,long long int arr2[1000000],long long int m,long long int indexofarr2)
{
    
    {
        int i=indexofarr2;
        for(long long int j=newtotal;j>=0;j--)
            {   //flag=0;
                if(arr2[i]<arr[total-1])
                {
                    cout<<total+1<<endl;
                    if(i==m-1)
                    return;
                    else{
                    check(arr,total,total,arr2,m,indexofarr2+1);
                    break;
                    }
                }
                if(arr2[i]>=arr[j] && (j==0 || arr2[i]<arr[j-1]))
               {
                    cout<<j+1<<endl;
                    if(i==m-1)
                    return;
                    else{
                    check(arr,j,total,arr2,m,indexofarr2+1);
                    break;}
               }
            }
            
    }
}
int main()
{
    long long int arr1[1000000],arr2[1000000],arr[1000000],n,m,total,i,c=0;
    int flag=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr1[i];
    cin>>m;
    for(i=0;i<m;i++)
        cin>>arr2[i];
    for(i=0;i<n;i++)//unique array
    {
        if(i==0 || arr1[i]!=arr1[i-1])
            arr[c++]=arr1[i];
        else continue;
    }
    total=c;//total no. of ranks 
    check(arr,total,total,arr2,m,0);
    return 0;
}
*/