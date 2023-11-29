#include <bits/stdc++.h>

using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (double)a.first/(double)a.second > (double)b.first/(double)b.second;
}

void fractinalKnapsackProfitByWeight(int profit[], int weight[], int n, int capacity, vector<pair<double, double>> &ans, int &totalProfit){
    vector<pair<int, int>> pairing;
    for(int i = 0; i < n; i++) pairing.push_back({profit[i], weight[i]});
    sort(pairing.begin(), pairing.end(), cmp);
    for(int i = 0; i < n; i++){
        if(capacity >= pairing[i].second){
            ans.push_back({pairing[i].first, pairing[i].second});
            totalProfit += pairing[i].first;
            capacity -= pairing[i].second;
        }else{
            double frac = (double)capacity/(double)pairing[i].second * (double)pairing[i].first;
            totalProfit += frac;
            ans.push_back({frac, (double)capacity/(double)pairing[i].second * pairing[i].second});
            capacity = 0;
        }
    }
}

void fractinalKnapsackProfit(int profit[], int weight[], int n, int capacity, vector<pair<double, double>> &ans, int &totalProfit){
    vector<pair<int, int>> pairing;
    for(int i = 0; i < n; i++) pairing.push_back({profit[i], weight[i]});
    sort(pairing.begin(), pairing.end(), greater<pair<int, int>>());
    
    for(int i = 0; i < n; i++){
        if(capacity >= pairing[i].second){
            totalProfit += pairing[i].first;
            ans.push_back({pairing[i].first, pairing[i].second});
            capacity -= pairing[i].second;
        }else{
            double ratio = (double)capacity/(double)pairing[i].second;
            double frac = ratio*(double)pairing[i].first;
            totalProfit += frac;
            ans.push_back({frac, ratio*(double)pairing[i].second});
        }
    }
}

void fractinalKnapsackWeight(int profit[], int weight[], int n, int capacity, vector<pair<double, double>> &ans, int &totalProfit){
    vector<pair<int, int>> pairing;
    for(int i = 0; i < n; i++) pairing.push_back({profit[i], weight[i]});
    sort(pairing.begin(), pairing.end());
    
    for(int i = 0; i < n; i++){
        if(capacity >= pairing[i].second){
            totalProfit += pairing[i].first;
            ans.push_back({pairing[i].first, pairing[i].second});
            capacity -= pairing[i].second;
        }else{
            double ratio = (double)capacity/(double)pairing[i].second;
            double frac = ratio*(double)pairing[i].first;
            totalProfit += frac;
            ans.push_back({frac, ratio*(double)pairing[i].second});
        }
    }
}

int main(){
    int profit[3] = {100, 60, 120};
    int weight[3] = {20, 10, 30};
    int n = 3, capacity = 50, totalProfit = 0;

    cout << "According to profit/weight: \n";
    vector<pair<double, double>> ans;
    fractinalKnapsackProfitByWeight(profit, weight, n, capacity, ans, totalProfit);
    cout << "Added items: \n";
    for(auto i:ans) cout << i.first << " " << i.second << "\n";
    cout << "totalProfit: " << totalProfit << endl;

    cout << "\nAccording to maximize profit: \n";
    int totalProfit2 = 0;
    vector<pair<double, double>> _ans;
    fractinalKnapsackProfit(profit, weight, n, capacity, _ans, totalProfit2);
    cout << "Added items: \n";
    for(auto j:_ans) cout << j.first << " " << j.second << "\n";
    cout << "totalProfit2: " << totalProfit2 << endl;
    
    cout << "\nAccording to minimize weight: \n";
    int totalProfit3 = 0;
    vector<pair<double, double>> __ans;
    fractinalKnapsackWeight(profit, weight, n, capacity, __ans, totalProfit3);
    cout << "Added items: \n";
    for(auto k:__ans) cout << k.first << " " << k.second << "\n";
    cout << "totalProfit3: " << totalProfit3 << endl;
    return 0;
}