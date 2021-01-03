#include <bits/stdc++.h>
using namespace std;
int pageCount(int n, int p) {
    int min=0;
    int count_front=0;
    int count_back=0;
    count_front=p/2;
    count_back=(n-p)/2;
    if(count_back<count_front){
        min=count_back;
    }
    else{
        min=count_front;
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
