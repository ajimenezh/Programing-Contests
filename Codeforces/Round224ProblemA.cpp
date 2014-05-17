#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

string s, str;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a = 0;
    int b = 0;

    cin>>s;

    int i = 0;

    while (i<s.length() && s[i]!='|') {a++; i++;}
    string s1;
    if (i>0) s1 = s.substr(0,i);
    i++;
    int k = i;
    while (i<s.length() && s[i]!='|') {b++; i++;}
    string s2;
    if (k<s.length()) s2 = s.substr(k, s.length()-k);

    cin>>str;


    if (((int)str.length()-abs(a-b))%2!=0 || (int)str.length()<abs(a-b)) {
        cout<<"Impossible";
    }
    else {
        int k = (str.length()-abs(a-b))/2;
        if (a>b) {
            for (int i=0; i<k; i++) s1 += str[i];
            for (int i=k; i<str.length(); i++) s2 += str[i];
        }
        else {
            for (int i=0; i<k; i++) s2 += str[i];
            for (int i=k; i<str.length(); i++) s1 += str[i];
        }
        cout<<s1<<"|"<<s2<<endl;
    }

    return 0;

}
