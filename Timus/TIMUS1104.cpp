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

char s[1000100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int i = 0;
    while (true) {
        int ch = fgetc(stdin);
        if (ch==10) {
            break;
        }
        s[i++] = ch;
    }
    int n = i;

    int in = 1;
    for (int j=0; j<n; j++) {
        int t = 0;
        if (s[j]>='A' && s[j]<='Z') t = (s[j]-'A'+10);
        else t = (s[j]-'0');
        in = max(t,in);
    }

    if (n==1 && (s[0]=='0' || s[0]=='1')) {
        cout<<2<<endl;
        return 0;
    }

    for (int i=in; i<=35; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (s[j]>='A' && s[j]<='Z') sum += (s[j]-'A'+10)%i;
            else sum += (s[j]-'0')%i;
        }
        if (sum%i==0) {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<"No solution."<<endl;

    return 0;

}
