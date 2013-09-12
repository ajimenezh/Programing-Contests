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

string s;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;

    int i;
    int r = 0;
    for (i=0; i<s.length(); i++) {
        if (s[i]<'4') {
            s[i] = '4';
            break;
        }
        else if (s[i]<'7') {
            s[i]='7';
            break;
        }
        else {
            s[i] = '4';
            r = 1;
            break;
        }
    }
    for (int j=i+1; j<s.length(); j++) s[j] = '4';
    for (int j=i-1; j>=0; j--) {
        if (r==0) break;
        if (s[j]=='4') {
            s[j] = '7';
            r = 0;
            break;
        }
        else if (s[j]=='7') {
            s[j]='4';
            r = 1;
        }

    }
    if (r==1) {
        s = '4' + s;
    }

    //cout<<s<<endl;

    int c1=0,c2=0;

    for (int i=0; i<s.length(); i++) s[i]=='4' ? c1++ : c2++;

    if ((c1+c2)%2==0) {
        int i = s.length()-1;
        while (i>=0 && c1!=c2) {
            if (c1<c2 && s[i]=='7') {
                s[i] = '4';
                c1++;
                c2--;
            }
            else if(c1>c2 && s[i]=='4'){
                s[i] = '7';
                c1--;
                c2++;
            }
            i--;
        }
    }
    else {
        int c = c1+c2+1;
        c = c/2;
        s = '4' + s;
        for (int i=1; i<c; i++) s[i] = '4';
        for (int i=c; i<2*c; i++) s[i] = '7';
    }

    cout<<s<<endl;

    return 0;

}
