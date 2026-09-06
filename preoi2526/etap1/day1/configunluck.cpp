// #include <iostream>
// #include <vector>
// using namespace std;
// using ll = long long;
// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     ll n;
//     cin >> n;
//     vector<pair<ll,ll> > vek(n);
//     for(ll i = 0; i < n; i++){
//         cin >> vek[i].first;
//     }
//     for(ll i = 0; i < n; i++){
//         cin >> vek[i].second;
//     }
//     if(n==1){
//         cout << max(vek[0].first, vek[0].second) << endl;
//         return 0;
//     }
//     else if(n==2){
//         cout << max(vek[0].first, vek[0].second) + max(vek[1].first, vek[1].second) << endl;
//         return 0;
//     }
//     else if (n==3)
//     {
//         ll p1, p2, p3;
//         p1 = max(vek[0].first, vek[0].second) + max(vek[1].first, vek[1].second);
//         p2 = max(vek[0].first, vek[0].second) + max(vek[2].first, vek[2].second);
//         p3 = max(vek[1].first, vek[1].second) + max(vek[2].first, vek[2].second);
//         cout << max({p1, p2, p3}) << endl;
//         return 0;
//     }
//     long long p3,p2,p1;
//     p3 = 0;
//     p2 = max(vek[0].first, vek[0].second);
//     p1 = max(vek[0].first, vek[0].second) + max(vek[1].first, vek[1].second);
//     for(long long i = 2; i < n; ++i){
//         //cout << sm[i]<<endl;
//         //cout << p1 << " " << p2+sm[i] <<" " << p3 + sm[i]+sm[i-1] << endl;
//         long long c = max(p1,max(p2+sm[i],p3 + sm[i]+sm[i-1]));
//         p3 = p2;
//         p2 = p1;
//         p1 = c;
//         //cout << p3 << " " << p2 << " " << p1 << endl;
//     }
//     cout << p1;

//     return 0;
// }