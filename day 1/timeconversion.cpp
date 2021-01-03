#include <bits/stdc++.h>
using namespace std;
string timeConversion(string s) {
    int hour;
    int minute;
    int second;
    char time[2];
    hour=s[0]*10+s[1];
    minute=s[3]*10+s[4];
    second=s[6]*10+s[7];
    time[0]=s[8];
    time[1]=s[9];
    if(time[0]=='P'){
        if(hour!=12){
            hour=hour+12;
        }
    }    
    else if(time[0]=='A'){
        if(hour==12){
            hour=0;
        }
    }    
    string result[8];
    result[0]='hour/10';
    result[1]='hour%10';
    result[2]=':';
    result[3]='minute/10';
    result[4]='minute%10';
    result[5]=':';
    result[6]='second/10';
    result[7]='second%10';

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
/*
#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    hours = s[0:2]
    hours_am = '00'
    hours_pm = '12'
    if s[8:] == 'PM':
        if s[:8] == '12:00:00':
            return '12:00:00'
        elif s[:2] == '12':
            return hours_pm + s[2:8] 
        else:
            hours = int(hours) + 12
            return str(hours) + s[2:8]
    elif s[8:] == 'AM':
        if s[:8] == '12:00:00':
            return '00:00:00'
        elif s[0:2] == '12':
            return hours_am + s[2:8] 
        else:
            return s[:8]

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()

*/    