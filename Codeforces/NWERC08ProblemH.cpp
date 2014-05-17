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

int t;
int n;
int c[] = {6,2,5,5,4,5,6,3,7,6};

bool calc(int a) {
    vector<int> v;
    while (a>0) {v.push_back(a%10); a/= 10;}
    int r = 0;
    for (int i=0; i<v.size(); i++) r += c[v[i]];

    return r==n;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>n;
        int tmp = n;
        string s;
        if (tmp%2!=0) {
            tmp -= 3;
            s = '7';
        }
        while (tmp>0) {
            tmp -= 2;
            s = s + '1';
        }

        if (n<21) {
            int mi = 0;

            while (true) {
                if (calc(mi)) break;
                else mi++;
            }
            cout<<mi<<" "<<s<<endl;
        }
        else {
            tmp = n;
            string s2;
            if (n%7==0) {
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==1) {
                s2 = "10";
                tmp -= 8;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==2) {
                s2 = '1';
                tmp -= 2;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==3) {
                s2 = "200";
                tmp -= 17;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==4) {
                s2 = "20";
                tmp -= 11;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==5) {
                s2 = '2';
                tmp -= 5;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            else if (n%7==6) {
                s2 = '6';
                tmp -= 6;
                while (tmp>0) {
                    tmp -= 7;
                    s2 = s2 + '8';
                }
            }
            cout<<s2<<" "<<s<<endl;
        }

    }

    return 0;

}
