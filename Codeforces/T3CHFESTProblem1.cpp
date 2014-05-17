#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

char buf[200010];

string reverseString ( const string &S ) {
    int n = S.length();
    string s = S;

    for (int i=0; i<n; i++)
      buf[i] = S[n-i-1];
    for (int i=0; i<n; i++)
      s[i] = buf[i];

    return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s = "";

    cout<<reverseString(s);


    return 0;

}
