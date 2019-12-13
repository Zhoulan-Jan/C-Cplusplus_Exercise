#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<string>
//using namespace std;
//
//º¯ÊýÄ£°å
//template<class T>
//void bubble(T * item, int len) {
//	int i = 0;
//	int j = 0;
//	T t;
//	for (; i < len - 1; i++) {
//		for (j = 0; j < len - i - 1; j++) {
//			if (item[j] > item[j + 1]) {
//				t = item[j];
//				item[j] = item[j + 1];
//				item[j + 1] = t;
//			}
//		}
//	}
//}
//
//int main() {
//	char str[] = "HUTREADHGKLP";
//	bubble(str, strlen(str));
//	cout << str << endl;
//
//	int nums1[] = { 7, 5, 1, 2, 3, 9, 6, 1 };
//	int len1 = sizeof(nums1) / sizeof(nums1[0]);
//	bubble(nums1, len1);
//	for (int i = 0; i < len1; i++) {
//		printf("%d ", nums1[i]);
//	}
//
//	double nums2[] = { 2.3, 5.3, 7.8, 3.9, 1.5 };
//	int len2 = sizeof(nums2) / sizeof(nums2[0]);
//	bubble(nums2, len2);
//	for (int i = 0; i < len2; i++) {
//		printf("%f ", nums2[i]);
//	}
//
//	system("pause");
//	return 0;
//}