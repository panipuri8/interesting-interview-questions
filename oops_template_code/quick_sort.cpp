#include<bits/stdc++.h>
using namespace std;

int _partition(int a[], int low, int high) {
    int pivot = a[high];
    int index = low - 1;
    for(int i=low;i<high;i++) {
        if(a[i] <= pivot) {
            index++;
            swap(a[index], a[i]);
        }
    }
    swap(a[index+1], a[high]);
    return index+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = _partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int main() {
    srand(time(NULL));
    int a[100];
    for(int i=0;i<100;i++) {
        a[i] = rand() % 1000;
    }
    for(int i=0;i<100;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    quickSort(a, 0, 99);
    for(int i=0;i<100;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}