#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, inp, x=0, y;
    cin >> n;
    vector<int> integers;
    vector<int> answer;
    for(int i=0; i<n; i++){
        cin >> inp;
        integers.push_back(inp);
    }
    sort(integers.begin(), integers.end());
    y = n/2;
    int ptr1, ptr2;
    ptr1 = 0;
    ptr2 = y;
    while(ptr1 < y){
        answer.push_back(integers[ptr2]);
        answer.push_back(integers[ptr1]);
        ptr1++;
        ptr2++;
    }
    while(ptr2 < n){
        answer.push_back(integers[ptr2]);
        ptr2++;
    }
    for(int i=1; i<n; i=i+2){
        if(i+1 < n){
            if(answer[i-1] > answer[i] && answer[i+1] > answer[i]){
                x++;
            }
        }
    }
    cout << x << endl;
    for(int i=0; i<n; i++){
        cout << answer[i] << endl;
    }
    return 0;
}
