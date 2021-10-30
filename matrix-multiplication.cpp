// Multiplying square matrices. Dynamic memory allocation.
#include <iostream>
#include <time.h>

using namespace std;

int main() {
  const int a = 4096;  // number of rows and columns
  const int b = 3;  // values in matrix 1
  const int c = 2;  // values in matrix 2

  int** MATRIX1 = new int*[a];  // first matrix
  int** MATRIX2 = new int*[a];  // second matrix
  int** MATRIX3 = new int*[a];  // the result of the multiplication
  int i, j, k;
  
  clock_t begin, end;
  double time;

  // dynamically allocate memory for each row (in all matrices)
  for (int i = 0; i < a; i++) {
    MATRIX1[i] = new int[a];
    MATRIX2[i] = new int[a];
    MATRIX3[i] = new int[a];
  }

  // assign values to MATRIX1
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      MATRIX1[i][j] = b;
    }
  }

  // assign values to MATRIX2
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      MATRIX2[i][j] = c;
    }
  }

  begin = clock();
  // matrix multiplication
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      MATRIX3[i][j] = 0;
      for (int k = 0; k < a; k++) {
        MATRIX3[i][j] += MATRIX1[i][k] * MATRIX2[k][j];
      }
    }
  }
  end = clock();

  // results (only a few values)
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      cout << MATRIX3[i][j] << "\t";
    }
  }

  // deallocate memory (in all matrices)
  for (int i = 0; i < a; i++) {
    delete[] MATRIX1[i];
    delete[] MATRIX2[i];
    delete[] MATRIX3[i];
  }
  delete[] MATRIX1;
  delete[] MATRIX2;
  delete[] MATRIX3;

  time = (double)(end - begin) / CLOCKS_PER_SEC;
  cout << endl
       << "The matrix multiplication took " << time << " seconds" << endl;

  return 0;
}
