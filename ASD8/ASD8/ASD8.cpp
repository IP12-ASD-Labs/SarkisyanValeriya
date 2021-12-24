#include <iostream>
#include <time.h>
using namespace std;

void generateArr(float**, int, int);
void printArr(float**, int, int);
void createNewArr(float*, float**, int, int);
void printNewArr(float*, int);
void sortNewArr(float*, int);

int main() {
	const int m = 6, n = 5;
	float** arr = new float* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new float[n];
	}
	generateArr(arr, m, n);
	cout << "Initial array:\n";
	printArr(arr, m, n);
	float* newArr = new float[m];
	createNewArr(newArr, arr, m, n);
	cout << "New array:\n";
	printNewArr(newArr, m);
	cout << "\nSorted new array:\n";
	sortNewArr(newArr, m); cout << endl;
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[]newArr;
	system("pause");
}

void generateArr(float** A, int rows, int columns) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			A[i][j] = (float)rand() / RAND_MAX * 2 * 100 - 100;
		}
	}
}

void printArr(float** A, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%8.2f", A[i][j]);
		}
		printf("%s\n", "");
	}
}

void createNewArr(float* B, float** A, int rows, int columns) {
	float average = 0;
	for (int i = 0; i < rows; i++) {
		float sum = 0;
		int kilk = 0;
		for (int j = 0; j < columns; j++) {
			if (A[i][j] < 0) {
				sum = sum + A[i][j];
				kilk++;
			}
		}
		float average = sum / kilk;
		B[i] = average;
	}
}

void printNewArr(float* B, int lengths) {
	for (int i = 0; i < lengths; i++) {
		printf("%8.2f", B[i]);
	}
}

void sortNewArr(float* B, int lengths) {
	for (int i = 0; i < lengths - 1; ++i) {
		for (int j = 0; j < lengths - 1; ++j) {
			if (B[j] < B[j + 1]) {
				float temp = B[j + 1];
				B[j + 1] = B[j];
				B[j] = temp;
			}
		}
	}
	printNewArr(B, lengths);
}