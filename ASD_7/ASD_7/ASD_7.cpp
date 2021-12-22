#include <iostream>
using namespace std;

void generateArr(char arr1[], char arr2[], int size);
void generateNewArr(char arr3[], int size);

int main() {
	const int size = 10;
	char First[size], Second[size], Third[size];
	generateArr(First, Second, size);
	cout << endl << "Third array:" << endl;
	for (int i = 0; i < size; i++) {
		Third[i] = 0;
		for (int j = 0; j < size; j++) {
			if (First[i] == Second[j]) {
				Third[i] = First[i];
				printf("%3c", Third[i]);
			}
		}
	}
	cout << endl << "New array:" << endl;
	generateNewArr(Third, size);
	system("pause");
}
void generateArr(char arr1[], char arr2[], int size) {
	printf("%-20s\n", "First array: ");
	for (int i = 0; i < size; i++) {
		arr1[i] = 2 * i + 42;
		
		printf("%3c", arr1[i]);
		
	}
	printf("%-20s\n", "\nSecond array: ");
	for (int j = 0; j < size; j++) {
		arr2[j] = 54 - 2 * j;
		printf("%3c", arr2[j]);
	}
}

void generateNewArr(char arr3[], int size) {
	char NewArr[10];
	char max = arr3[0];
	for (int i = 0; i < size; i++) {
		if (arr3[i] > max)
			max = arr3[i];
	}
	for (int i = 0; i < size; i++) {
		if (arr3[i] < max) {
			NewArr[i] = arr3[i];
			printf("%3c", NewArr[i]);
		}
	}
}