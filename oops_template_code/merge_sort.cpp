#include<bits/stdc++.h>
using namespace std;

void _merge(int a[], int low, int mid, int high) {
    int arr1[mid-low+1];
    int arr2[high-mid];
    for(int ptr = 0, x = low; x <= mid; x++, ptr++) {
        arr1[ptr] = a[x];
    }
    for(int ptr = 0, x = mid + 1; x <= high; x++, ptr++) {
        arr2[ptr] = a[x];
    }
    int l = 0, r = 0;
    int ptr = low;
    while(l <= mid-low && r <= high-mid-1) {
        if(arr1[l] < arr2[r]) {
            a[ptr++] = arr1[l++];
        }
        else {
            a[ptr++] = arr2[r++];
        }
    }
    while(l <= mid-low) {
        a[ptr++] = arr1[l++];
    }
    while(r <= high-mid-1) {
        a[ptr++] = arr2[r++];
    }
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = low + (high - low)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        _merge(a, low, mid, high);
    }
}

int main() {
    int a[100];
    for(int i=0;i<100;i++) {
        a[i] = rand() % 1000;
    }
    for(int i=0;i<100;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    mergeSort(a, 0, 99);
    for(int i=0;i<100;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}