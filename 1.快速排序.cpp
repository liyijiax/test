#inlcude <iostream>

void quick_sort(int *a, int l, int r) {
	if (l < r) {
		int mid = partition(a, l, r);
		quick_sort(a, l, mid - 1);
		quick_sort(a, mid + 1, r);
	}
}


int main() {
	int a[7]  = {1, 3, 2, 0, 2, 1, 6};
	quick_sort(a, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
