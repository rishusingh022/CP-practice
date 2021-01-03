#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
/*vector<int> breakingRecords(vector<int> scores) {
    vector<int> low_score;
    vector<int> high_score;
    low_score.push_back(scores[0]);
    high_score.push_back(scores[0]);
    vector<int>::iterator i;
    for(i=scores.begin()+1;i!=scores.end();i++){
        //int a=low_score.back();
        int b=high_score.back();
        if(*i>=b){
            int c=*i;
            high_score.push_back(c);
        }
        else{
            int c=*i;
            low_score.push_back(c);
        }
    }
    vector<int> result(2);
    for(i=high_score.begin();i!=high_score.end();i++){
        if(*i>*(i+1)){
            result[0]++;
        }
    }
    for(i=low_score.begin();i!=low_score.end();i++){
        if(*i<*(i+1)){
            result[1]++;
        }
    }
    return result;
}
*/
vector<int> breakingRecords(vector<int> scores){
    int max=scores[0];
    int min=scores[0];
    vector<int> result(2);
    vector<int> :: iterator i;
    for(i=scores.begin()+1;i!=scores.end();i++){
        if(*i>max){
            result[0]++;
            max=*i;
        }
        else if(*i<min){
            result[1]++;
            min=*i;
        }
        else{
            continue;
        }
    }
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
