//#include <iostream>
//
//using namespace std; 
//
//#define M 10001
//
//void inputArray(int a[], int& n) {
//	for (int i = 0; i < n; i++) {
//		cout << "a[" << i << "]= ";
//		cin >> a[i];
//	}
//}
//
//void outputArray(int a[], int& n) {
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " "; 
//	}
//	cout << endl;
//}
//
//int cnt[10000001]; 
//void countingSort(int a[], int b[], int& n) {
//	int k = INT_MIN;
//	for (int i = 0; i < n; i++) {
//		k = max(k, a[i]); 
//	}
//
//	for (int i = 0; i < n; i++) {
//		cnt[ a[i] ]++; 
//	}
//	int index = 0; 
//	for (int i = 0; i <= k; i++) {
//		while (cnt[i] > 0) {
//			b[index++] = i; 
//			cnt[i]--;
//		}
//	}
//}
//
//int main()
//{
//	int a[M], b[M], n;
//	do {
//		cout << "\nEnter size of list: "; 
//		cin >> n;
//		if (n <= 0 || n > M) {
//			cout << "\nInvalid Please enter again";
//		} 
//	} while (n <= 0 || n > M);
//	inputArray(a, n); 
//	cout << "\nList before sorting: ";
//	outputArray(a, n); 
//	countingSort(a, b, n); 
//	cout << "\nList after sorting: "; 
//	outputArray(b, n);
//	system("pause"); 
//	return 0; 
//}