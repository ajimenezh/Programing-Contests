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
int A[] = {1,1,2,6,4};
int B[] = {6,2,4,8};

string div(string str) {
    int r = 0;
    vector<int> v;
    for (int i=0; i<str.length(); i++) {
        int t = (str[i]-'0') + 10*r;

        v.push_back(t/5);
        r = t%5;
        //cout<<r<<" "<<t<<endl;
    }
    string s2;
    int j = 0;
    while (j<v.size()&&v[j]==0) j++;
    for (int i=j; i<v.size(); i++) {
        s2 = s2 + char(v[i]+'0');
    }
    return s2;
}

int mod4(string srt) {
    int r = 0;
    for (int i=0; i<srt.length(); i++) {
        int t = (srt[i]-'0') + 10*r;
        r = t%4;
        //cout<<r<<" "<<t<<endl;
    }
    return r;
}

int f(string srt) {
    if (srt.size()==0) return 1;
    return B[mod4(srt)];
}

int last(string srt) {
    if (srt.size()==0) return A[0];
    if (srt.size()==1 && srt[0]-'0'<5) return A[srt[0]-'0'];
    string s2 = div(srt);
    //cout<<s2<<" "<<f(s2)<<endl;
    return (f(s2)*last(s2)*A[((srt[srt.length()-1]-'0')%5)])%10;
}

#include<iostream>
using namespace std;

int P(int K)
{
        int A[]={6,2,4,8};
        if (K<1) return 1;
        return A[K%4];
}

int L(int N)
{
        int A[]={1,1,2,6,4};
        if (N<5) return A[N];
        return (P(N/5)*L(N/5)*L(N%5))%10;
}

int main()
{
        int N;
        while (scanf("%d", &N) == 1)
                printf("%d\n", L(N));
        return 0;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>s) {
        cout<<last(s)<<endl;
    }


    return 0;

}
