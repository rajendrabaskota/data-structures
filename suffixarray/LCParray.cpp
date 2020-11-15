#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;

vector<string> suffixArray(string T, int len){
    vector<string>sa;
    for(int i=0; i<len; i++){
        sa.push_back(T.substr(i, T.length()-i));
    }
    sort(sa.begin(), sa.end());
    return sa;
}

vector<int> lcpArrayFunc(vector<string>sa, int len){
    vector<int>arr;
    arr.push_back(0);
    int j;
    for(int i=0; i<len-1; i++){
        j = 0;
        while(sa[i][j] == sa[i+1][j]){
            j++;
        }
        arr.push_back(j);
    }
    return arr;
}

void longestCommonSubstring(vector<string>sa, int len, int totalStrings, char* sentinels){
    int highPointer = 0;
    int lowPointer = 0;
    int window[totalStrings]{0};
    while(highPointer < len){
        
    }

}

int main(){
    int totalStrings = 3;
    char sentinels[totalStrings] = {'#', '$', '&'};
    string s1 = "bcdc";
    string s2 = "bcde";
    string s3 = "aebcd";
    string T = s1 + "#" + s2 + "$" + s3 + "&";
    int len = T.length();
    vector<string>sa = suffixArray(T, len);
    for(int i=0; i<len; i++){
        cout << sa[i] << endl;
    }
    vector<int>lcpArray = lcpArrayFunc(sa, len);
    
    return 0;
}
