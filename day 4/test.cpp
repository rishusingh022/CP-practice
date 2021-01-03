#include <bits/stdc++.h>
using namespace std;
void equalizeArray(vector<int> arr) {
    sort(arr.begin(),arr.end());
    //array to count the frequency of element in arr
    vector<int> array(101);
    for(int i=0;i<101;i++){
        //intialising every element to 0
        array[i]=0;
    }
    //counting frequency of each
    for(int i=0;i<arr.size();i++){
        array[arr[i]]++;
    }
    //element with max count will be stored in result
    vector<int> result;
    int count=0;
    int maxiumum_count=*max_element(array.begin(),array.end());
    int min=arr.size()-maxiumum_count;
    cout<<min;
}
int main(){
    vector<int> arr={10, 27 ,9 ,10, 100 ,38 ,30, 32, 45, 29 ,27 ,29, 32, 38, 32,38, 14 ,38 ,29 ,30 ,63, 29, 63, 91,54,10,63};
    equalizeArray(arr);
}