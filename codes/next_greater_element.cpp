#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> stt;
    vector<long long> ret(n, -1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stt.empty() && stt.top() <= arr[i])
        {
            stt.pop();
        }
        if (!stt.empty())
            ret[i] = stt.top();
        stt.push(arr[i]);
    }
    return ret;
    // Your code here
}

int main(){
    vector<long long>vec = {1,2,41,2,31,53,22};
    vector<long long>nge = nextLargerElement(vec, vec.size());
    for (int i = 0; i < nge.size(); i++)
    {
        cout << nge[i] << " ";
    }
    cout << endl;
}