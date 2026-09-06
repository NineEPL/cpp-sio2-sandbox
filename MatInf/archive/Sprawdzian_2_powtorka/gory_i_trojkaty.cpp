/*
#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> seemed;
    int x,y;
    cin >> x >> y;
    seemed.push_back(make_pair(x,y));
    for(int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        bool makes = false;
        for(int j = 0; j < seemed.size(); j++){
            if(seemed[j].first < x && seemed[j].second < y){
                seemed.erase(seemed.begin() + j);
                makes = true;
            }
            else if(seemed[j].first <= x){
                if(x+y > seemed[j].first + seemed[j].second){
                    makes = true;
                }
                else{
                    makes = false;
                    break;
                }
            }
            else{
                int newx = x + (seemed[j].first - x) * 2;
                if(newx+y > seemed[j].first + seemed[j].second){
                    makes = true;
                }
                else{
                    makes = false;
                    break;
                }
            }
        }
        if(makes) seemed.push_back(make_pair(x,y));


    }

    for(int i = 0; i < seemed.size(); i++){
        cout << seemed[i].first << " " << seemed[i].second << "\n";
    }

    cout << seemed.size();
    return 0;
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > mountains;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        mountains.push_back(make_pair(x,y));
    }

    sort(mountains.begin(), mountains.end());

    vector<pair<int, int> > visible;

    for (auto &mountain : mountains) {
        bool isVisible = true;
        for (auto &visibleMountain : visible) {
            if (visibleMountain.first < mountain.first && visibleMountain.second < mountain.second) {
                isVisible = false;
                break;
            }
        }

        if (isVisible) {
            visible.push_back(mountain);
        }
    }


    cout << visible.size() << endl;
    return 0;
}

