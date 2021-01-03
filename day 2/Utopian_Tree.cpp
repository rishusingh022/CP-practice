#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int h=1;
    if(n==0){
        return 1;
    }
    else if(n==1){
        return 2;
    }
    else{
        int a=1;
        while(a<=n){
            if(a%2==0){
                h=h+1;
            }
            else{
                h=h*2;
            }
            a++;
        }
        return h;
    }
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

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
