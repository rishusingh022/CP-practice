#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long taumBday(int b, int w, int bc, int wc, int z) {
    if(bc==wc){
        return b*bc+w*wc;
    }
    else if(z>bc && z>wc){
        return b*bc+ w*wc;
    }
    else if(bc>wc+z){
        return (b+w)*wc +b*z;
    }
    else if(wc>bc+z){
        return (b+w)*bc +w*z;
    }
    else if(b==w){
        vector<int> rip(3);
        rip.push_back(b*bc+w*wc);
        rip.push_back((w+b)*wc+b*z);
        rip.push_back((w+b)*bc+w*z);
        int min=*min_element(rip.begin(),rip.end());
        return min;    
    }
    else{
        if(bc + z < wc){
            wc = bc + z;
        } 
        else if (wc + z < bc){
            bc = wc + z;
        }
        return b*bc + w*wc;
        }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int b = stoi(first_multiple_input[0]);

        int w = stoi(first_multiple_input[1]);

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int bc = stoi(second_multiple_input[0]);

        int wc = stoi(second_multiple_input[1]);

        int z = stoi(second_multiple_input[2]);

        long result = taumBday(b, w, bc, wc, z);

        fout << result << "\n";
    }

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
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
public static void main(String[] args) {
   Scanner in = new Scanner(System.in);
   int t = in.nextInt();
 
   for(int a0 = 0; a0 < t; a0++){
      long b = in.nextLong();
      long w = in.nextLong();
      long bc= in.nextLong();
      long wc= in.nextLong();
      long z = in.nextLong();
 
     int flag=0;
     if(bc+z<wc)
       {
        System.out.println((long)(b*bc)+(w*bc)+(w*z));
       }
     else if(wc+z<bc)
       {
           System.out.println((long)(b*wc)+(w*wc)+(b*z));
       }
       else if(bc==wc)
          { 
            System.out.println((long)(b*bc)+(w*wc));
         }
       else
         {
            System.out.println((long)(b*bc)+(w*wc));
         }
      }
   }
}
*/