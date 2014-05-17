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

const string t = "0000";

string f(string s) {
    int k = 0;
    for (int i=0; i<s.length(); i++) if (s[i]==':') k++;
        for (int i=0; i<s.length()-1; i++) {
            if (s[i]==':' && s[i+1]==':') {
                string tmp;
                for (int j=0; j<7-k; j++) {
                    tmp = tmp + t + ":";
                }
                if (k<7) {
                    tmp = tmp + t;
                    s = s.substr(0,i+1) + tmp + s.substr(i+1,s.length()-i-1);
                }
                if (k==7) {
                    s = s.substr(0,i+1) + t + s.substr(i+1,s.length()-i-1);
                }
                if (k==8) {
                    if (s[0]==':') s = s.substr(1,i) + t + s.substr(i+1,s.length()-i-1);
                    else s = s.substr(0,i+1) + t + s.substr(i+1,s.length()-i-2);
                }
                break;
            }
        }
    if (s[0]==':') s = t + s;
    if (s[s.length()-1]==':') s = s + t;
    int last = 0;
    for (int i=0; i<s.length(); i++) if (s[i]==':') {
        if (i-last<4) {
            string tmp = "";
            for (int j=0; j<4-(i-last); j++) tmp += "0";
            s = s.substr(0, last) + tmp + s.substr(last, s.length()-last);
        }
        i = last+4;
        last = i+1;
    }
    int i = s.length();
    if (i-last<4) {
        string tmp = "";
        for (int j=0; j<4-(i-last); j++) tmp += "0";
        s = s.substr(0, last) + tmp + s.substr(last, s.length()-last);
    }
    return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        cout<<f(s)<<endl;
    }

    return 0;

}
