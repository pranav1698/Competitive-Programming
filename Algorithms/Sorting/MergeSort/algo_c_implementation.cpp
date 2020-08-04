#include <bits/stdc++.h>
using namespace std;

void merge(int *Arr, int start, int mid, int end) {
	int temp[end - start + 1];

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

  while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}

void MergeSort(int* a, int low, int high) {
  if(low >= high) return;

  int mid = low + (high - low) / 2;
  MergeSort(a, low, mid);
  MergeSort(a, mid+1, high);

  merge(a, low, mid, high);
}

int main() {
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  MergeSort(a, 0, 9);

  for(int i=0; i<9; i++)
    cout << a[i] << endl;
}
