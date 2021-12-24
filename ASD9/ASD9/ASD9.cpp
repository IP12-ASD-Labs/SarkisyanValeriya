#include <iostream>
#include <time.h>
using namespace std;

void generateArr(float**, int, int);
void find_X(float**, int, int, float);
void count_elements(float**, int, int, float);

int main()
{
	int m, n;
	cout << "Enter m: "; cin >> m;
	cout << "Enter n: "; cin >> n;
	float** arr = new float* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new float[n];
	}
	cout << "Initial array:\n";
	generateArr(arr, m, n);
	float X=arr[0][0];
	find_X(arr, m, n, X);
	count_elements(arr, m, n, X);
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	system("pause");
}

void generateArr(float** A, int rows, int columns) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			A[i][j] = (float)rand() / RAND_MAX * 2 * 100 - 100;
			printf("%8.2f", A[i][j]);
		}
		printf("%s\n", "");
	}
}

void find_X(float** A, int rows, int columns, float x) {
	int i = 0, temp, Xm = 0, Xn = 0;
	for (int j = 0; j < columns; j++) {
		if (i == 0 || i == -1){
			i = 0;
			temp = 1;
		}
		else if (i == rows) {
			temp = -1;
			i--;
		}
		for (int k = 0; k < rows; k++) {
			if (A[i][j] > 0) {
				x = A[i][j];
				Xm = i + 1;
				Xn = j + 1;
			}
			i += temp;
		}
	}
	printf("\nLast positive number is %5.2f . Position:\nrow: %d \ncolumn: %d", x, Xm, Xn);
}

void count_elements(float** A, int rows, int columns, float x) {
	int kilk = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if ((i + j < rows - 1) && (A[i][j] > x)) {
				kilk++;
			}
		}
	}
	printf("\nThe amount of numbers situated above the side diagonal that are bigger than X is: %d\n", kilk);
}