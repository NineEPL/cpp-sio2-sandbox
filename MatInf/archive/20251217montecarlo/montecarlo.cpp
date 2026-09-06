#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ifstream in("data.in");
    if (!in.is_open()) {
        cout << "something went terribly wrong\n";
        return 1;
    }

    ll countin = 0;
    ll total = 0;
    const ll r = 200;
    const ll mid = 200;

    double pi_1000 = 0;
    double pi_5000 = 0;

    vector<pair<double,double> > points_on_circle;
    ll wkole = 0;
    vector<double> przyblizenia;

    ll x, y;
    for (ll i = 0; i < 10000; i++) {
        if (!(in >> x >> y)) break;
        total++;

        ll dx = x - mid;
        ll dy = y - mid;
        if(i < 1700){
            przyblizenia.push_back(4.0 * countin / total);
        }
        if (dx*dx + dy*dy <= r*r) {
            countin++;
        }

        if (dx*dx + dy*dy == r*r) {
            points_on_circle.push_back(make_pair(x, y));
        }

        if(dx*dx + dy*dy < r*r) {
            wkole++;
        }

        if (total == 1000) {
            pi_1000 = 4.0 * countin / total;
        }
        if (total == 5000) {
            pi_5000 = 4.0 * countin / total;
        }
    }

    cout << "Zadanie 1:\n";
    cout << points_on_circle.size() << "\nPoints on the circle:\n";
    for (const auto& p : points_on_circle) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    cout << "Number of points inside the circle: " << wkole << endl;

    cout << "\nZadanie 2:\n";
    cout << "Approximation of pi after 1000 points: " << pi_1000 << endl;
    cout << "Approximation of pi after 5000 points: " << pi_5000 << endl;

    double pi = 4.0 * countin / total;
    cout << "Approximation of pi: " << pi << endl;

    in.close();
    ofstream out("przyblizenia.txt");
    for (const auto& val : przyblizenia) {
        out << val << "\n";
    }
    out.close();
    return 0;
}
