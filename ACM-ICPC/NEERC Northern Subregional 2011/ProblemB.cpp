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

int m,n,s,k;
string str;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m>>n>>s>>k>>str;

    bool exist = 0;

    for (int i=0; i<str.length(); i++) if (str[i]=='*') {
        exist = 1;
        int c = 0;
        int j = i;
        while (j<str.length() && str[j]=='*') {
            j++;
            c++;
        }
        if (c!=s) {
            cout<<"Impossible"<<endl;
            return 0;
        }
        while (j<str.length()) {
            j++;
            if (str[j]=='*') {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }

        break;
    }

    if (exist) {
        if (s==1) cout<<"Unique"<<endl;
        else {
            if (m==s) cout<<"Unique"<<endl;
            else if (m<s) cout<<"Impossible"<<endl;
            else if (m>s) cout<<"Ambiguous";
        }
    }
    else {
        if (n==s) {
            if ((k-1==s && m-k<s) || (m-k==s && k-1<s)) cout<<"Unique"<<endl;
            else if (k-1>=s || m-k>=s) cout<<"Ambiguous"<<endl;
            else cout<<"Impossible"<<endl;
        }
        else {
            if (n>s) {
                if (k-1>=s || m-k>=s) cout<<"Ambiguous"<<endl;
                else cout<<"Impossible"<<endl;
            }
            else cout<<"Impossible"<<endl;
        }
    }

    return 0;

}
