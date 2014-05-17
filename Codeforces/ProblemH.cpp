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

int n;
string s;
string crib;

bool check(string str) {
    for (int i=0; i<str.length()-crib.length()+1; i++) {
        bool done = 1;
        for (int j=i; j<i+crib.length(); j++) {
            if (crib[j-i]!=str[j]) {
                done = 0;
                break;
            }
        }
        if (done) {
            return 1;
        }
    }
    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n;
        s = "";
        for (int j=0; j<(n-1)/5+1; j++) {
            string str;
            cin>>str;
            s += str;
        }
        cin>>crib;

        bool done = 0;
        for (int i=1; i<=25; i++) {
            for (int j=5; j<=20; j++) {
                string s2 = s;
                for (int k=0; k<(s.length()-1)/j+1; k++) {
                    reverse(s2.begin()+k*j, s2.begin()+min((k+1)*j,(int)s.length()));
                }
                for (int k=0; k<s.length(); k++) {
                    int l = 'A';
                    int h = 'Z';
                    int t = s2[k]-i;
                    if (t<l) t += 26;
                    s2[k] = char(t);
                }
                if (check(s2)) {
                    cout<<i<<" "<<j<<endl;
                    i = 30;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) cout<<"Crib is not encrypted."<<endl;
    }

    return 0;

}

