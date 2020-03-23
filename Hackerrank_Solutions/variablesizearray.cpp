#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin >> n >> q;
    vector<int> liste[n];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> list1;
        for(int j=0;j<k;j++){
            int c;
            cin >> c;
            list1.push_back(c);
        }
        liste[i] = list1;
    }

    for(int i=0;i<q;i++){
        int q1,q2;
        cin >> q1;
        cin >> q2;
        cout<<liste[q1][q2]<<endl;
    }


    return 0;
}

