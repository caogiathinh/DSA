//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <ctime>
//#include <time.h>
//
//using namespace std;
//
//void selectionSort(vector <int>& a)
//{
//	// buoc i chon phan tu nho nhat ch dc sap xep va hoan vi voi a[i]
//	for (int i = 0; i < a.size() - 1; i++)
//	{
//		// coi phan tu thu i la nho nhat 
//		int minPos = i;
//		for (int j = i; j < a.size(); j++)
//		{
//			if (a[j] < a[minPos])
//			{
//				minPos = j;
//			}
//		}
//		swap(a[i], a[minPos]);
//	}
//	//for (int i = 0; i < a.size(); i++) {
//	//	cout << a[i] << " ";
//	//}
//}
//vector <int> bucket[10000001];
//// Useful when input is evenly distributed
//void bucketSort(vector <int> &a, int numOfBucket) {
//	int maxE = INT_MIN, minE = INT_MAX; 
//	for (int i = 0; i < a.size(); i++) {
//		maxE = max(a[i], maxE); 
//		minE = min(a[i], minE); 
//	}
//	int range = (maxE - minE) / numOfBucket; 
//	for (int i = 0; i < a.size(); i++) {
//		int indexBucket = (a[i] - minE) / range; 
//		bucket[indexBucket].push_back(a[i]); 
//	}
//	for (int i = 0; i < numOfBucket; i++) {
//		selectionSort(bucket[i]); 
//	}
//	int index = 0;
//	for (int i = 0; i < a.size(); i++) {
//		for (int j = 0; j < bucket[i].size(); j++) {
//			a[index++] = bucket[i][j]; 
// 		}
//	}
//}
//
//void print(vector <int> a) {
//	for (int i = 0; i < a.size(); i++) {
//		cout << a[i] << " "; 
//	}
//}; 
//
//int main() {
//	int n; cin >> n;
//	vector <int> a(n);
//	
//	srand(time(NULL));
//	
//	clock_t start, end; 
//	double duration; 
//
//	for (int i = 0; i < n; i++) {
//		a[i] = rand(); 
//	}
//	cout << "\nTIME:\n"; 
//	start = clock();
//	bucketSort(a, 100);
//	end = clock();
//	duration = (double)(end - start);
//	cout << "Bucketsort take " << duration << " seconds" << endl;
//
//	start = clock(); 
//	selectionSort(a);
//	end = clock(); 
//	duration = (double)(end - start); 
//	cout << "Seclectionsort take " << duration << " seconds" << endl;
//	return 0;
//}