#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s){
    vector<int> cost={0,0,0,0,0,0,0,0};
    int sq1[3][3] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    int sq2[3][3] = {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
    int sq3[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    int sq4[3][3] = {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
    int sq5[3][3] = {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
    int sq6[3][3] = {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
    int sq7[3][3] = {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}};
    int sq8[3][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cost[0]=cost[0]+abs(s[i][j]-sq1[i][j]);
            cost[1]=cost[1]+abs(s[i][j]-sq2[i][j]);
            cost[2]=cost[2]+abs(s[i][j]-sq3[i][j]);
            cost[3]=cost[3]+abs(s[i][j]-sq4[i][j]);
            cost[4]=cost[4]+abs(s[i][j]-sq5[i][j]);
            cost[5]=cost[5]+abs(s[i][j]-sq6[i][j]);
            cost[6]=cost[6]+abs(s[i][j]-sq7[i][j]);
            cost[7]=cost[7]+abs(s[i][j]-sq8[i][j]);
        }
    }
    return *min_element(cost.begin(),cost.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
