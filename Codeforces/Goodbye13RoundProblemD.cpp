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

int k;
int x,n,m;

long long s1[55], s2[55], s12[55], s21[55], s22[55], s11[55];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>k>>x>>n>>m;

    int t11 = 1;
    int t12 = 1;
    int t21 = 2;
    int t22 = 2;
    s1[0] = 1;
    s1[1] = 0;
    s2[1] = 1;
    s2[0] = 0;
    s12[0] = 0;
    s12[1] = 0;
    s21[0] = 0;
    s21[1] = 0;
    s11[0] = 0;
    s11[1] = 0;
    s22[0] = 0;
    s22[1] = 0;

    for (int i=2; i<k; i++) {
        s1[i] = s1[i-2]+s1[i-1];
        s2[i] = s2[i-2]+s2[i-1];
        s12[i] = s12[i-2]+s12[i-1];
        s21[i] = s21[i-2]+s21[i-1];
        s12[i] = s12[i-2]+s12[i-1];
        s22[i] = s22[i-2]+s22[i-1];
        int t31 = t11;
        int t32 = t22;
        if (t12==t21) {
            if (t12==1) s11[i]++;
            else s22[i]++;
        }
        else {
            if (t12==1) s12[i]++;
            else s21[i]++;
        }
        t11 = t21;
        t12 = t22;
        t21 = t31;
        t22 = t32;
    }

    bool done = 0;
    if (m==1) {
        if (n==1) {
            if (x==s12[k-1]) {
                cout<<"A"<<endl;
                cout<<"C"<<endl;
                done = 1;
            }
            else if (x==s21[k-1]) {
                cout<<"C"<<endl;
                cout<<"A"<<endl;
                done = 1;
            }
            else {
                cout<<"Happy new year!"<<endl;
                done = 1;
            }
        }
        else {
            int tmp = x;
            for (int j=0; j<=n; j+=2) {
                x = tmp - s1[k-1]*j/2;
                if (x<0) continue;
                if (n-j>0 && (x-s12[k-1])%s2[k-1]==0 && (x-s12[k-1])/s2[k-1]<=(m-1)/2) {
                    for (int i=0; i<j/2; i++) cout<<"AC";
                    for (int i=0; i<n-j-1; i++) cout<<"K";
                    cout<<"A"; cout<<endl;
                    cout<<"C";
                    for (int i=0; i<(x-s12[k-1])/s2[k-1]; i++) cout<<"AC";
                    for (int i=0; i<m-1-2*((x-s12[k-1])/s2[k-1]); i++) cout<<"K";
                    cout<<endl;
                    done = 1;
                }
                else if (n-j>0 && (x-s21[k-1])%s2[k-1]==0 && (x-s21[k-1])/s2[k-1]<=(m-1)/2) {
                        cout<<"C";
                        for (int i=0; i<j/2; i++) cout<<"AC";
                        for (int i=0; i<n-j-1; i++) cout<<"K"; cout<<endl;
                        for (int i=0; i<(x-s21[k-1])/s2[k-1]; i++) cout<<"AC";
                        for (int i=0; i<m-1-2*((x-s21[k-1])/s2[k-1]); i++) cout<<"K";
                        cout<<"A"<<endl;
                        done = 1;
                    }
                if (done) break;
            }
        }
    }
    else {
        int tmp = x;
        for (int j=0; j<=n; j+=2) {
            x = tmp - s1[k-1]*j/2;
            if (x<0) continue;
            if (x%s2[k-1]==0 && x/s2[k-1]<=m/2) {
                for (int i=0; i<j/2; i++) cout<<"AC";
                for (int i=0; i<n-j; i++) cout<<"K"; cout<<endl;
                for (int i=0; i<x/s2[k-1]; i++) cout<<"AC";
                for (int i=0; i<m-2*(x/s2[k-1]); i++) cout<<"K"; cout<<endl;
                done = 1;
            }
            else if (n-j>0 && (x-s12[k-1])%s2[k-1]==0 && (x-s12[k-1])/s2[k-1]<=(m-1)/2) {
                for (int i=0; i<j/2; i++) cout<<"AC";
                for (int i=0; i<n-j-1; i++) cout<<"K";
                cout<<"A"; cout<<endl;
                cout<<"C";
                for (int i=0; i<(x-s12[k-1])/s2[k-1]; i++) cout<<"AC";
                for (int i=0; i<m-1-2*((x-s12[k-1])/s2[k-1]); i++) cout<<"K";
                cout<<endl;
                done = 1;
            }
            else if ((x-s22[k-1])%s2[k-1]==0 && (x-s22[k-1])/s2[k-1]<=(m-2)/2) {
                for (int i=0; i<j/2; i++) cout<<"AC";
                for (int i=0; i<n-j; i++) cout<<"K"; cout<<endl;
                cout<<"C";
                for (int i=0; i<(x-s22[k-1])/s2[k-1]; i++) cout<<"AC";
                for (int i=0; i<m-2-2*((x-s22[k-1])/s2[k-1]); i++) cout<<"K";
                cout<<"A"<<endl;
                done = 1;
            }
            else if (n-j>0 && (x-s21[k-1])%s2[k-1]==0 && (x-s21[k-1])/s2[k-1]<=(m-1)/2) {
                    cout<<"C";
                    for (int i=0; i<j/2; i++) cout<<"AC";
                    for (int i=0; i<n-j-1; i++) cout<<"K"; cout<<endl;
                    for (int i=0; i<(x-s21[k-1])/s2[k-1]; i++) cout<<"AC";
                    for (int i=0; i<m-1-2*((x-s21[k-1])/s2[k-1]); i++) cout<<"K";
                    cout<<"A"<<endl;
                    done = 1;
                }
            else if (n-j>0 && (x-s22[k-1]-s21[k-1])%s2[k-1]==0 && (x-s22[k-1]-s21[k-1])/s2[k-1]<=(m-2)/2) {
                    cout<<"C";
                    for (int i=0; i<j/2; i++) cout<<"AC";
                    for (int i=0; i<n-j-1; i++) cout<<"K"; cout<<endl;
                    cout<<"C";
                    for (int i=0; i<(x-s22[k-1]-s21[k-1])/s2[k-1]; i++) cout<<"AC";
                    for (int i=0; i<m-2-2*((x-s22[k-1]-s21[k-1])/s2[k-1]); i++) cout<<"K";
                    cout<<"A"<<endl;
                    done = 1;
                }
                else if (n-j>0 && (x-s22[k-1]-s21[k-1]-s12[k-1])%s2[k-1]==0 && (x-s22[k-1]-s21[k-1]-s12[k-1])/s2[k-1]<=(m-2)/2) {
                    cout<<"C";
                    for (int i=0; i<j/2; i++) cout<<"AC";
                    for (int i=0; i<n-j-2; i++) cout<<"K"; cout<<"A"; cout<<endl;
                    cout<<"C";
                    for (int i=0; i<(x-s22[k-1]-s21[k-1])/s2[k-1]; i++) cout<<"AC";
                    for (int i=0; i<m-2-2*((x-s22[k-1]-s21[k-1])/s2[k-1]); i++) cout<<"K";
                    cout<<"A"<<endl;
                    done = 1;
                }
            if (done) break;
        }
    }

    //cout<<s1[k-1]<<" "<<s2[k-1]<<" "<<s12[k-1]<<" "<<s11[k-1]<<" "<<s22[k-1]<<" "<<s21[k-1]<<endl;

    if (!done) {
        cout<<"Happy new year!"<<endl;
    }

    return 0;

}
