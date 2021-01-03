#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    vector<int> numbers;
    int a=n;
    while(a!=0){
        numbers.push_back(a%10);
        a=a/10;
    }
    int count=0;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]!=0){
            if(n%numbers[i]==0){
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
