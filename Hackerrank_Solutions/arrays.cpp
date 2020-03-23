#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;

    int liste[n];

    for(int i=0;i<n;i++){
        cin>>liste[i];
    }
    
    for(int i=n-1;0<=i;i--){
        cout<<liste[i] << " ";
    }
    return 0;
}
