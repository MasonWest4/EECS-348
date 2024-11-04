
#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE] = {};  // 2D array for matrix data (using int for simplicity) initializes each value to 0.

public:
  // 1. Read values from stdin into a matrix
  void readFromFile(const string& filename, int offset = 0) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        // Skip to the offset (if offset is provided)
        for (int skip = 0; skip < offset; ++skip) {
            int temp;
            file >> temp;  // Read and discard values until the offset
        }

        // Read SIZE x SIZE elements into the matrix
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (!(file >> data[i][j])) {
                    cerr << "Error: Not enough data in file" << endl;
                    file.close();
                    return;
                }
            }
        }

        file.close();
    }


  // 2. Display a matrix
  void display() const{
    for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    Matrix result;
      for (int i = 0; i < SIZE; i++) {
          for (int j = 0; j < SIZE; j++) {
              result.data[i][j] = this->data[i][j] + other.data[i][j];
          }
      }
      return result;
  }


  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];  // Main diagonal
            sum += data[i][SIZE - i - 1];  // Secondary diagonal
        }
        // Adjust for center element if matrix size is odd
        if (SIZE % 2 != 0) {
            sum -= data[SIZE / 2][SIZE / 2];
        }
        return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            swap(data[row1], data[row2]);
            display();
            cout << "\n";
        } else {
            cout << "Error: Invalid row indices" << endl;
        }
    }
};

int main() {
  // Example usage:
  Matrix mat1;
  mat1.readFromFile("matrix-data.txt");  // Reads data from "matrix.txt"
  cout << "Matrix 1:" << endl;
  mat1.display();
  cout << "\n";
  Matrix mat2;
  mat2.readFromFile("matrix-data.txt", SIZE*SIZE);
  cout << "Matrix 2:" << endl;
  mat2.display();
  cout << "\n";

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();
  cout << "\n";

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();
  cout << "\n";

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
  cout << "\n";

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display(); 

  return 0;
}
