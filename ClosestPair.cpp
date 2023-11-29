#include <bits/stdc++.h>
using namespace std;

double closestPair(vector<pair<double, double>> &points, int start, int end); // cal for the bigger size
double bruteForce(vector<pair<double, double>> &points, int n); // calc for smaller size
double distance(pair<double, double> &a, pair<double, double> &b);
bool sortBy_Y(pair<double, double> &a, pair<double, double> &b);
bool sortBy_X(pair<double, double> &a, pair<double, double> &b);
double WindowClosest(vector<pair<double, double>> &points, double n, double &mn);

int main()
{
    /*
    cout << "extra problem \n";
    vector<pair<double, double>> points = {
        {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}
    }; 
    */
    cout << "class problem \n";
    vector<pair<double, double>> points = {
        {1, 8}, {2, 2}, {2, 6}, {3, 1}, {4.3, 6}, {5.5, 3}, {6.5, 5.7}, {7, 9}, {7, 4}, {7.2, 1}, {8, 5}, {9, 7}, {10, 2}, {11, 9}
    };  
    cout << "Points: {\n";
    for(auto i:points) cout << "\t{" << i.first << ", " << i.second << "}\n";
    cout << "\t}\n";
    int n = points.size();
    sort(points.begin(), points.end(), sortBy_X);
    cout << "The Smallest Distance: " << closestPair(points, 0, n-1);
    return 0;
}

double closestPair(vector<pair<double, double>> &points, int start, int end){
    if(end - start <= 3) return bruteForce(points, end);
    int mid = start+(end-start)/2;
    pair<int, int> middle = points[mid];
    double left = closestPair(points, start, mid);
    double right = closestPair(points, mid, end);

    double delta = min(left, right);

    vector<pair<double, double>> window; // consider points int band of delta on both sides
    for (int i = start; i < end; i++)
    {
        double d = abs(points[i].first - middle.first);
        if(d < delta){ // compare acc.. to x-axis
            window.push_back(points[i]);
        }
    }
    return min(delta, WindowClosest(window, window.size(), delta));
}

double bruteForce(vector<pair<double, double>> &points, int n){
    double mn = DBL_MAX;
    for(double i = 0; i < n; i++){
        for(double j = i+1; j < n; j++){
            mn = min(mn, distance(points[i], points[j]));
        }
    }
    return mn;
}

double distance(pair<double, double> &a, pair<double, double> &b){
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2)); // first: x, second: y
}

bool sortBy_Y(pair<double, double> &a, pair<double, double> &b){
    return a.second < b.second;
}

bool sortBy_X(pair<double, double> &a, pair<double, double> &b){
    return a.first < b.first;
}

double WindowClosest(vector<pair<double, double>> &points, double n, double &mn){
    double mini = mn;
    sort(points.begin(), points.end(), sortBy_Y);
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n && (points[j].second - points[i].second) < mini; j++){
            if(distance(points[i], points[j]) < mini) mini = distance(points[i], points[j]);
        }
    }
    return mini;
}