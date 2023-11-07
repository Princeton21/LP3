#include <bits/stdc++.h>
using namespace std;

//merge sort
// TC - O(nlogn)
// SC - O(n)

void merge(vector<int> &v, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> lft(n1);
    vector<int> rt(n2);

    for (int i = 0; i < n1; i++) lft[i] = v[left + i];
    for (int i = 0; i < n2; i++) rt[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (lft[i] <= rt[j]){
            v[k] = lft[i];
            i++;
        }
        else{
            v[k] = rt[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        v[k] = lft[i];
        i++;
        k++;
    }
    while (j < n2){
        v[k] = rt[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &elem : v) cin >> elem;

    mergeSort(v, 0, n - 1);

    cout << "Sorted vector : ";
    for (int num : v) cout << num << " ";
}
