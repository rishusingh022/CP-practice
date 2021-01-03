/*int pickingNumbers(vector<int> a) {
    vector<vector<int>>arr;
    vector<int>::iterator i;
    vector<int>::iterator j;
    for(i=a.begin(); i!=a.end();i++){
        vector<int> temp;
        for(j=a.begin(); j!=a.end();j++){
            if(abs(*i-*j)<=1){
                temp.push_back(*j);
            }
        }
        arr.push_back(temp);
    }
    vector<int> result;
    while (!arr.empty()) 
    {
        int size=arr.back().size()-1;
        result.push_back(size);
        arr.pop_back();
    }
    int max=*max_element(result.begin(),result.end());
    return max;
}
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int pickingNumbers(vector<int> a) {
    sort(a.begin(),a.end());
    int result=0;
    int count=1;
    int temp= a[0];
    // 2 3 4 5 6 7 
    for(int i=1;i<a.size();i++){
        if (temp == a[i] || temp + 1 == a[i])
        {
            count++;
        }
        else{
            if(count>result){
                result=count;
            }
            count=1;
            temp=a[i];
        }
    }
    if(count>result){
        result=count;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

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

