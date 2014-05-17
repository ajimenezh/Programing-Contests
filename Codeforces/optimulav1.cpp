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
#include <fstream>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

//Se puede cambiar el numero de lotes cambiando el valor de n
#define n 25
#define recursionLimit 8

struct lote{
    int cuba;
    double tiempo;
    lote() {
        cuba = 0;
        tiempo = 0;
    }
};

double tiempoMinimo[25][8];
double tiempoMaximo[25][8];
double tiempoMovimiento[9];
char buf[10];
int ind[25];

bool not_finished(vector<lote> v) {
    for (int i=0; i<n; i++) if (v[ind[i]].cuba<9) return true;
    return false;
}

bool check(vector<lote> v) {
    for (int i=0; i<n; i++) if (v[ind[i]].cuba<9 && v[ind[i]].cuba>0) {
        if (v[ind[i]].tiempo>tiempoMaximo[ind[i]][v[ind[i]].cuba-1]) {
            return true;
        }
    }
    return false;
}

bool special(vector<lote> v) {
    int c = 0;
    for (int i=0; i<n; i++) if (v[ind[i]].cuba<9 && v[ind[i]].cuba%2==1) c++;
    return c>1;
}

double rec(vector<lote> v, int flag) {
    if (check(v)) return 100000000;
    if (!not_finished(v)) return 0;
    if (flag==0) {
        if (special(v)) return 100000000;
        double t = 0;
        for (int i=0; i<n; i++) if (v[ind[i]].cuba<9) {
            for (int j=0; j<=8; j++) {
                if (v[ind[i]].cuba>j) continue;
                if (v[ind[i]].cuba==j) t += max(0.0,tiempoMinimo[ind[i]][v[ind[i]].cuba-1]-v[ind[i]].tiempo);
                else t += tiempoMinimo[ind[i]][j-1] + tiempoMovimiento[j];
            }
        }
        return t;
    }

    //cout<<"hola "<<v[0].cuba<<" "<<flag<<endl;

    for (int i=0; i<n; i++) if (ind[i]==0 || (ind[i]>0 && (v[ind[i]].cuba+1<v[ind[i-1]].cuba || v[ind[i]].cuba==8))) {
        if (v[ind[i]].cuba<9 && v[ind[i]].cuba!=0 && v[ind[i]].tiempo==tiempoMaximo[ind[i]][v[ind[i]].cuba-1]) {
            v[ind[i]].tiempo = 0;
            v[ind[i]].cuba++;
            for (int j=0; j<n; j++) if (ind[i]!=ind[j]) {
                v[ind[j]].tiempo += tiempoMovimiento[v[ind[i]].cuba];
            }
            if (check(v)) return 100000000;
            return tiempoMovimiento[v[ind[i]].cuba] + rec(v,flag-1);
        }
    }

    //A continuacion probamos todos los posibles movimientos que podemos hacer
    //sin que estos movimientos provoquen la colision inmediata de otros lotes
    vector<int> pos;
    int cnt = 0;
    for (int i=0; i<n; i++) if (v[ind[i]].cuba<9 && (ind[i]==0 || (ind[i]>0 && (v[ind[i]].cuba+1<v[ind[i-1]].cuba || v[ind[i]].cuba==8)))) {
        double tiempoProvisional;
        tiempoProvisional = tiempoMovimiento[v[ind[i]].cuba];
        if (v[ind[i]].cuba!=0) tiempoProvisional += max(tiempoMinimo[ind[i]][v[ind[i]].cuba-1] - v[ind[i]].tiempo,0.0);

        //Comprobamos las colisiones
        bool good = 1;
        for (int j=0; j<n; j++) if (ind[i]!=ind[j] && v[ind[j]].cuba<9 && v[ind[j]].cuba>0) {
            if (tiempoMaximo[ind[j]][v[ind[j]].cuba-1]<tiempoProvisional+v[ind[j]].tiempo) {
                good = 0;
                break;
            }
        }
        if (good) pos.push_back(ind[i]);
    }

    //Se calcula recursivamente cual da menos tiempo previsto y se realiza ese movimiento
    double best = 10000000;

    rep(it,pos) {
        int i = *it;
        double prev = v[i].tiempo;
        double tiempoProvisional;
        tiempoProvisional = tiempoMovimiento[v[i].cuba];
        if (v[i].cuba!=0) tiempoProvisional += max(tiempoMinimo[i][v[i].cuba-1] - v[i].tiempo,0.0);
        v[i].tiempo = 0;
        v[i].cuba++;
        for (int j=0; j<n; j++) if (i!=ind[j]) {
            v[ind[j]].tiempo += tiempoProvisional;
        }

        double tmp = rec(v, flag-1) + tiempoProvisional;

        if (tmp<best) {
            best = tmp;
        }

        for (int j=0; j<n; j++) if (i!=ind[j]) {
            v[ind[j]].tiempo -= tiempoProvisional;
        }
        v[i].tiempo = prev;
        v[i].cuba--;
    }
    return best;
}

double solve(vector<lote> v) {

    double res = 0.0;

    while (not_finished(v)) {
        //Primero se ve si hay algun lote que hay que mover obligatoriamente
        bool pass = 0;
        for (int i=0; i<n; i++) if (ind[i]==0 || (ind[i]>0 && (v[ind[i]].cuba+1<v[ind[i-1]].cuba || v[ind[i]].cuba==8))) {
            if (v[ind[i]].cuba<9 && v[ind[i]].cuba!=0 && v[ind[i]].tiempo==tiempoMaximo[ind[i]][v[ind[i]].cuba-1]) {
                v[ind[i]].tiempo = 0;
                v[ind[i]].cuba++;
                for (int j=0; j<n; j++) if (ind[i]!=ind[j]) {
                    v[ind[j]].tiempo += tiempoMovimiento[v[ind[i]].cuba];
                }
                res += tiempoMovimiento[v[ind[i]].cuba];
                printf("Se mueve el lote %d desde la cuba %d hasta la cuba %d\n",ind[i]+1,v[ind[i]].cuba-1,v[ind[i]].cuba);

                if (check(v)) {
                    cout<<"ERROR: Se ha producido una colision sin opciones"<<endl;
                    for (int i=0; i<n; i++) if (v[ind[i]].cuba>0) cout<<v[ind[i]].cuba<<" "<<v[ind[i]].tiempo<<" "<<tiempoMaximo[ind[i]][v[ind[i]].cuba-1]<<" "<<tiempoMovimiento[v[ind[i]].cuba]<<endl;
                    return 10000000000000;
                }
                pass = 1;
                break;
            }
        }
        if (pass) continue;

        //A continuacion probamos todos los posibles movimientos que podemos hacer
        //sin que estos movimientos provoquen la colision inmediata de otros lotes

        vector<int> pos;
        int cnt = 0;
        for (int i=0; i<n; i++) if (v[ind[i]].cuba<9 && (ind[i]==0 || (ind[i]>0 && (v[ind[i]].cuba+1<v[ind[i-1]].cuba || v[ind[i]].cuba==8)))) {
            double tiempoProvisional;
            tiempoProvisional = tiempoMovimiento[v[ind[i]].cuba];
            if (v[ind[i]].cuba!=0) tiempoProvisional += max(tiempoMinimo[ind[i]][v[ind[i]].cuba-1] - v[ind[i]].tiempo,0.0);

            //Comprobamos las colisiones
            bool good = 1;
            for (int j=0; j<n; j++) if (ind[i]!=ind[j] && v[ind[j]].cuba<9 && v[ind[j]].cuba>0) {
                if (tiempoMaximo[ind[j]][v[ind[j]].cuba-1]<tiempoProvisional+v[ind[j]].tiempo) {
                    good = 0;
                    break;
                }
            }
            if (good) pos.push_back(ind[i]);
        }

        //cout<<pos.size()<<endl;

        //Se calcula recursivamente cual da menos tiempo previsto y se realiza ese movimiento
        int p = -1;
        double best = 100000;

        rep(it,pos) {
            int i = *it;
            double prev = v[i].tiempo;
            double tiempoProvisional;
            tiempoProvisional = tiempoMovimiento[v[i].cuba];
            if (v[i].cuba!=0) tiempoProvisional += max(tiempoMinimo[i][v[i].cuba-1] - v[i].tiempo,0.0);
            v[i].tiempo = 0;
            v[i].cuba++;
            for (int j=0; j<n; j++) if (i!=ind[j]) {
                v[ind[j]].tiempo += tiempoProvisional;
            }

            double tmp = rec(v, recursionLimit) + tiempoProvisional;

            if (tmp<best) {
                best = tmp;
                p = i;
            }

            for (int j=0; j<n; j++) if (i!=ind[j]) {
                v[ind[j]].tiempo -= tiempoProvisional;
            }
            v[i].tiempo = prev;
            v[i].cuba--;
        }

        if (p==-1) {
            cout<<"ERROR: Solucion no encontrada"<<endl;
            for (int i=0; i<n; i++) if (v[i].cuba>0) cout<<v[i].cuba<<" "<<v[i].tiempo<<" "<<tiempoMaximo[i][v[i].cuba-1]<<" "<<tiempoMinimo[i][v[i].cuba-1]<<" "<<tiempoMovimiento[v[i].cuba]<<endl;
            return 10000000000000;
        }

        //Cambiamos el elegido
        double tiempoProvisional;
        tiempoProvisional = tiempoMovimiento[v[p].cuba];
        if (v[p].cuba!=0) tiempoProvisional += max(tiempoMinimo[p][v[p].cuba-1] - v[p].tiempo,0.0);
        v[p].tiempo = 0;
        v[p].cuba++;
        for (int j=0; j<n; j++) if (p!=j) {
            v[j].tiempo += tiempoProvisional;
        }
        res += tiempoProvisional;

        if (check(v)) {
            cout<<"ERROR: Se ha producido una colision"<<endl;
            for (int i=0; i<n; i++) if (v[i].cuba>0) cout<<v[i].cuba<<" "<<v[i].tiempo<<" "<<tiempoMaximo[i][v[i].cuba-1]<<" "<<tiempoMinimo[i][v[i].cuba-1]<<" "<<tiempoMovimiento[v[i].cuba]<<endl;
            return 10000000000000;
        }

        printf("Se mueve el lote %d desde la cuba %d hasta la cuba %d\n",p+1,v[p].cuba-1,v[p].cuba);
    }

    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    FILE *INPUT;
    INPUT = fopen("datos.txt","r");

    for (int i=0; i<25; i++) {
        for (int j=0; j<8; j++) {
            fscanf(INPUT,"%s",buf);
            int a,b;
            a = 0;
            int k = 0;
            while (buf[k]!='.') {a = a*10 + (buf[k]-'0'); k++;}
            b = buf[k+1]-'0';
            tiempoMinimo[i][j] = a + 1.0*b/10.0;
        }
    }

    for (int i=0; i<25; i++) {
        for (int j=0; j<8; j++) {
            fscanf(INPUT,"%s",buf);
            int a,b;
            a = 0;
            int k = 0;
            while (buf[k]!='.') {a = a*10 + (buf[k]-'0'); k++;}
            b = buf[k+1]-'0';
            tiempoMaximo[i][j] = a + 1.0*b/10.0;
        }
    }

    for (int i=0; i<9; i++) {
        fscanf(INPUT,"%s",buf);
        int a,b;
        a = 0;
        int k = 0;
        while (buf[k]!='.') {a = a*10 + (buf[k]-'0'); k++;}
        b = buf[k+1]-'0';
        tiempoMovimiento[i] = a + 1.0*b/10.0;
    }

    for (int i=0; i<n; i++) ind[i] = i;

    for (int i=0; i<3; i++) {
        vector<lote> v(n,lote());
        double res = solve(v);

        printf("%.2f\n",res);

        for (int j=0; j<n; j++) ind[j] = -1;

        for (int j=0; j<n; j++) {
            int a = rand()%50;
            int k = 0;
            while (a>0) {
                k++;
                k %= n;
                if (ind[k]<0) a--;
            }
            ind[k] = j;
        }
        for (int j=0; j<n; j++) cout<<ind[j]<<endl;
    }

    return 0;

}
