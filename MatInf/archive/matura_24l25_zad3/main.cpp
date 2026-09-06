#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

bool inside(ll x, ll y) {
    return (x > 0 && x < 5000 && y > 0 && y < 5000);
}

ll nwd(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
      return nwd(a - b, b);
    return nwd(a, b - a);
}

int main() {
    ifstream in("dron.txt");
    ofstream out("wyniki3.txt");

    vector<pair<ll, ll>> moves(100);
    vector<pair<ll, ll>> points;
    ll x = 0, y = 0;
    int nwd_c = 0;
    //------------------3.1-----------
    for (int i = 0; i < 100; ++i) {
        ll xc, yc;
        in >> xc >> yc;
        moves[i] = {xc, yc};

        if (nwd(abs(xc), abs(yc)) > 1) {
            nwd_c ++;
        }

        x += xc;
        y += yc;
        points.push_back({x, y});
    }

    out << "3.1 " << nwd_c << endl;

    int icounter = 0;
    for (auto p : points) {
        if (inside(p.first, p.second)) {
            icounter++;
        }
    }
    //------------------3.2 a------------------
    out << "3.2 a) " << icounter << endl;
    bool found = false;
    pair<ll, ll> A, B, C;
    int n = points.size();
    //----------------3.2 b------------------
    for (int i = 0; i < n && !found; ++i) {
        for (int j = i + 1; j < n && !found; ++j) {
            for (int k = j + 1; k < n && !found; ++k) {
                ll x1 = points[i].first, y1 = points[i].second;
                ll x2 = points[j].first, y2 = points[j].second;
                ll x3 = points[k].first, y3 = points[k].second;
                if (x1 + x2 == 2 * x3 && y1 + y2 == 2 * y3) {
                    A = {x1, y1}; B = {x2, y2}; C = {x3, y3}; found = true;
                }
                else if (x1 + x3 == 2 * x2 && y1 + y3 == 2 * y2) {
                    A = {x1, y1}; B = {x3, y3}; C = {x2, y2}; found = true;
                }
                else if (x2 + x3 == 2 * x1 && y2 + y3 == 2 * y1) {
                    A = {x2, y2}; B = {x3, y3}; C = {x1, y1}; found = true;
                }
            }
        }
    }

    if (found) {
        out << "3.2 b) (" << A.first << ", " << A.second << "), ("
                             << B.first << ", " << B.second << "), ("
                             << C.first << ", " << C.second << ")" << endl;
    } else {
        out << "3.2 b) NIE ISTNIEJE !!!" << endl;
    }
    in.close();
    out.close();

    return 0;
}
