#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string word) {
    pair<int, int> solution = { -1, -1 };
    //lmno
    //lmon
    for (int j = word.size() - 1; j >= 0; --j)//3
        for (int i = j; i >= 0; --i)
            if (word[i] < word[j] && i > solution.first) solution = { i, j };//2 3

    if (solution.first == solution.second)
        return "no answer";
    else {
        swap(word[solution.first], word[solution.second]);
        sort(word.begin() + solution.first + 1, word.end(), less<int>());
        return word;
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
