#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string sum(string &s1, string &s2) {
    if (s1.length()<s2.length()) return sum(s2,s1);

    int r = 0;
    int c;
    for (int i=0; i<s2.length(); i++) {
        int a = s2[s2.length()-1-i] - '0';
        int b = s1[s1.length()-1-i] - '0';
        c = a+b+r;
        r = c/10;
        c = c%10;
        s1[s1.length()-1-i] = char('0'+c);
    }
    for (int i=s2.length(); i<s1.length(); i++) {
        int b = s1[s1.length()-1-i] - '0';
        c = b+r;
        r = c/10;
        c = c%10;
        s1[s1.length()-1-i]  = char('0'+c);
    }
    if (r!=0) s1 = char('0'+r) + s1;
    return s1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    string s1 = "4";
    string s2 = "7";

    int n;
    cin>>n;
    if (n==3) cout<<s1;
    else if (n==4) cout<<s2;
    else {
        for (int i=0; i<n-4; i++) {
            string tmp = s2;
            s2 = sum(s1,s2);
            s1 = tmp;
        }
        cout<<s2;
    }
    return 0;

}
