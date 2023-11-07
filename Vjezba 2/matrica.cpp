#include <iostream>

struct Matrix {
    int rows;
    int cols;
    float* data;
};

Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new float[rows * cols];
    return mat;
}

void deleteMatrix(Matrix& mat) {
    delete[] mat.data;
}

void inputMatrix(Matrix& mat) {
    std::cout << "Unesite elemente matrice (" << mat.rows << "x" << mat.cols << "):" << std::endl;
    for (int i = 0; i < mat.rows * mat.cols; ++i) {
        std::cin >> mat.data[i];
    }
}

void printMatrix(Matrix& mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            std::cout << mat.data[i * mat.cols + j] << "\t"; // matrix[i][j]
        }
        std::cout << std::endl;
    }
}

Matrix addMatrices(Matrix& mat1, Matrix& mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < result.rows * result.cols; ++i) {
        result.data[i] = mat1.data[i] + mat2.data[i];
    }
    return result;
}

Matrix multiplyMatrices(Matrix& mat1, Matrix& mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; ++i) /*ocekujem da je matrica jednaka*/{
        for (int j = 0; j < mat2.cols; ++j) {
            result.data[i * result.cols + j] = 0;
            for (int k = 0; k < mat1.cols; ++k) {
                result.data[i * result.cols + j] += mat1.data[i * mat1.cols + k] * mat2.data[k * mat2.cols + j];
            }
        }
    }
    return result;
}

Matrix subtractMatrices(Matrix& mat1, Matrix& mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < result.rows * result.cols; ++i) {
        result.data[i] = mat1.data[i] - mat2.data[i];
    }
    return result;
}

Matrix transposeMatrix(Matrix& mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            result.data[j * result.cols + i] = mat.data[i * mat.cols + j];
        }
    }
    return result;
}

Matrix generateRandomMatrix(int rows, int cols, float a, float b) {
    Matrix mat = createMatrix(rows, cols);

    for (int i = 0; i < rows * cols; ++i) {
        mat.data[i] = a + (rand() / (RAND_MAX * 1.0)) * (b - a);;
    }
    return mat;
}


int main() {
    int rows, cols;
    std::cout << "Unesite broj redaka: ";
    std::cin >> rows;
    std::cout << "Unesite broj stupaca: ";
    std::cin >> cols;

    Matrix mat1 = createMatrix(rows, cols);
    inputMatrix(mat1);

    Matrix mat2 = createMatrix(rows, cols);
    inputMatrix(mat2);

    std::cout << "Unesene matrice:" << std::endl;
    std::cout << "Prva matrica:" << std::endl;
    printMatrix(mat1);
    std::cout << "Druga matrica:" << std::endl;
    printMatrix(mat2);

    Matrix sum = addMatrices(mat1, mat2);
    std::cout << "Zbroj matrica:" << std::endl;
    printMatrix(sum);
    deleteMatrix(sum);

    Matrix difference = subtractMatrices(mat1, mat2);
    std::cout << "Razlika matrica:" << std::endl;
    printMatrix(difference);
    deleteMatrix(difference);

    Matrix product = multiplyMatrices(mat1, mat2);
    std::cout << "Umnozak matrica:" << std::endl;
    printMatrix(product);
    deleteMatrix(product);

    Matrix transpose = transposeMatrix(mat1);
    std::cout << "Transponirana prva matrica:" << std::endl;
    printMatrix(transpose);
    deleteMatrix(transpose);

    Matrix randomMatrix = generateRandomMatrix(rows, cols, 1, 10);
    std::cout << "Slucajno generirana matrica:" << std::endl;
    printMatrix(randomMatrix);
    deleteMatrix(randomMatrix);

    deleteMatrix(mat1);
    deleteMatrix(mat2);

    return 0;
}
