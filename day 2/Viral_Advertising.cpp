#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int a=1;
    int number_people=5;//6 9
    int sum_of_likes=0;//2 3 4
    while(a<=n){
        sum_of_likes=sum_of_likes+floor(number_people/2);
        number_people=floor(number_people/2)*3;
        a++;
    }
    return sum_of_likes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
