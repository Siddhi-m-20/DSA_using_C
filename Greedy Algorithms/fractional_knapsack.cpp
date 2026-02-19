#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>   
using namespace std;

double knapsack(vector<int>& wt, vector<int>& val, int w) {
    int n = wt.size();
    vector<double> ratio(n);

    for(int i = 0; i < n; i++){
        ratio[i] = (double)val[i] / wt[i];
    }

    vector<tuple<double,int,int>> items(n);

    for(int i = 0; i < n; i++){
        items[i] = {ratio[i], wt[i], val[i]};
    }

    sort(items.begin(), items.end(), 
         greater<tuple<double,int,int>>());

    double totalValue = 0.0;

    for(int i = 0; i < n; i++){
        auto [r, w_i, v_i] = items[i];

        if(w_i <= w){
            totalValue += v_i;
            w -= w_i;
        }
        else{
            totalValue += r * w;
            break;
        }
    }

    return totalValue;
}

int main(){
    vector<int> weights = {10,20,30};
    vector<int> values  = {60,100,140};
    int capacity = 50;

    double totalValue = knapsack(weights, values, capacity);

    cout << "Total Value in Knapsack = "
         << totalValue << endl;

    return 0;
}
//Total Value in Knapsack = 253.333
