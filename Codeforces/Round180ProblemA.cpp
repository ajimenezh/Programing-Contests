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

string s,t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>t;

    int par = 0;

    for (int i=0; i<s.length(); i++) par = (par+s[i]=='1')%2;

    for (int i=0; i<s.length(); i++) {
        bool good = 1;
        for (int j=0; j<min(t.length(),s.length()-i); j++) if (s[i+j]!=t[j]) good = 0;
        if (!good) continue;
        if (t.length()<=s.length()-i) {
            cout<<"YES"<<endl;
            return 0;
        }
        int p = par;
        int k = 0;
        good = 1;
        for (int j=s.length()-i; j<t.length(); j++) {
            if (t[j]=='1' && p==1) {
                p = 0;
            }
            else if (t[j]=='1' && p==0) {
                while (k<i && s[k]=='0') k++;
                if (k==i) {
                    good = 0;
                    break;
                }
                k++;
            }
            else if (t[j]=='0' && p==1) {
                while (k<i && s[k]=='0') k++;
                if (k==i) {
                    good = 0;
                    break;
                }
                k++;
                p = 0;
            }
        }
        if (good) {
            cout<<"YES"<<endl;
            return 0;
        }
    }

    int k = 0;
    bool good = 1;
    int p = par;
    for (int j=0; j<t.length(); j++) {
        if (t[j]=='1' && p==1) {
            p = 0;
        }
        else if (t[j]=='1' && p==0) {
            while (k<s.length() && s[k]=='0') k++;
            if (k==s.length()) {
                good = 0;
                break;
            }
            k++;
        }
        else if (t[j]=='0' && p==1) {
            while (k<s.length() && s[k]=='0') k++;
            if (k==s.length()) {
                good = 0;
                break;
            }
            k++;
            p = 0;
        }
    }
    if (good) {
        cout<<"YES"<<endl;
        return 0;
    }

    if (par) s = s + '1';
    else s = s + '0';
    par = 0;

    k = 0;
    good = 1;
    p = par;
    for (int j=0; j<t.length(); j++) {
        if (t[j]=='1' && p==1) {
            p = 0;
        }
        else if (t[j]=='1' && p==0) {
            while (k<s.length() && s[k]=='0') k++;
            if (k==s.length()) {
                good = 0;
                break;
            }
            k++;
        }
        else if (t[j]=='0' && p==1) {
            while (k<s.length() && s[k]=='0') k++;
            if (k==s.length()) {
                good = 0;
                break;
            }
            k++;
            p = 0;
        }
    }
    if (good) {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;

    return 0;

}
