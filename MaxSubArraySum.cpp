// best is kadane's algo

#include <bits/stdc++.h>
using namespace std;

int MaxSubArraySum(vector<int> &a, int low,int high, int &s, int &e);

int main(int argc, char const *argv[])
{
    vector<int> a = {5, -3, 9, 12, -8, 7, 11, -9, 1, -2, 4, 6};
    for(auto i:a) cout << i << " ";
    cout << "\n";
    int s, e;
    cout << "maxSum: " << MaxSubArraySum(a, 0, a.size()-1, s, e);
    cout << "\nRange:" << s << " ----> " << e << "\n";

    /*
        int sum = 0, maxSum = 0;
	    int s = INT_MAX, e = INT_MIN;
	    for(int i = 0; i < n; i++){
	        sum += a[i];
	        if(sum > maxSum) {
	            maxSum =  sum;
	            s = min(s, i);
                e = max(e, i);
	        }
	        if(sum < 0) sum = 0;
	    }
	    cout << maxSum << "\n";
	    return ans;
    */

    return 0;
}

int MaxSubArraySum(vector<int> &a, int low, int high, int &s, int &e){
    if(low == high) return a[low];
    int mid = low+(high-low)/2;
    int left = MaxSubArraySum(a, low, mid, s, e);
    int right = MaxSubArraySum(a, mid+1, high, s, e);

    int crossSum = 0, sum = 0, lSum = 0, rSum = 0;
    int startRange = mid, endRange = mid;
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if(sum > lSum) 
        {
            lSum = sum;
            startRange = i;
        }
    }
    sum = 0;
    for (int i = mid+1; i < high; i++)
    {
        sum += a[i];
        if(sum > rSum) 
        {
            rSum = sum;
            endRange = i;
        }
    }
    crossSum = lSum + rSum;
    s = startRange, e = endRange;

    if(left > right){
        if(left > crossSum){
            return left;
        }else return crossSum;
    }else{
        if(right > crossSum){
            return right;
        }else return crossSum;
    }
}