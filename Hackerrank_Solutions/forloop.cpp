#include <iostream>
#include <cstdio>
using namespace std;

void func(int n,int m){
    for(;n<=m;n++){
        if(n <= 9){
            if(n == 1) cout<<"one";
            else if(n==2) cout<<"two";
            else if(n==3) cout<<"three";
            else if(n==4) cout<<"four";
            else if(n==5) cout<<"five";
            else if(n==6) cout<<"six";
            else if(n==7) cout<<"seven";
            else if(n==8) cout<<"eight";
            else cout<<"nine";
        }else{
            if(n%2) cout << "odd";
            else cout<<"even";
        }

        cout<<endl;
    }
}

int main() {
    int x,y;
    cin >> x;
    cin >> y;
    // Complete the code.
    func(x,y);
    return 0;
}


