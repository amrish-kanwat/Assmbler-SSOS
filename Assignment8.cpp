#include <iostream>
#include <pthread.h>

// Maximum size for matrices
const int MAX_SIZE = 10;

// Structure to store matrix information
struct Matrix {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
};

// Structure to store thread information
struct ThreadInfo {
    int threadID;
    Matrix matrixA;
    Matrix matrixB;
    Matrix resultMatrix;
};

// Function to perform matrix multiplication in a single thread
void* multiply(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;

    // Perform matrix multiplication
    for (int i = 0; i < info->matrixA.rows; ++i) {
        for (int j = 0; j < info->matrixB.cols; ++j) {
            info->resultMatrix.data[i][j] = 0;
            for (int k = 0; k < info->matrixA.cols; ++k) {
                info->resultMatrix.data[i][j] += info->matrixA.data[i][k] * info->matrixB.data[k][j];
            }
        }
    }

    // Display thread completion message
    std::cout << "Thread " << info->threadID << " completed!" << std::endl;

    pthread_exit(NULL);
}

int main() {
    // Array of threads and thread information
    pthread_t threads[MAX_SIZE];
    ThreadInfo threadInfo[MAX_SIZE];

    // Input for the first matrix
    std::cout << "Enter size of first matrix (rows cols): ";
    std::cin >> threadInfo[0].matrixA.rows >> threadInfo[0].matrixA.cols;

    // Input for the first matrix
    std::cout << "Enter values for the first matrix:" << std::endl;
    for (int i = 0; i < threadInfo[0].matrixA.rows; ++i) {
        for (int j = 0; j < threadInfo[0].matrixA.cols; ++j) {
            std::cin >> threadInfo[0].matrixA.data[i][j];
        }
    }

    // Input for the second matrix
    std::cout << "Enter size of second matrix (rows cols): ";
    std::cin >> threadInfo[0].matrixB.rows >> threadInfo[0].matrixB.cols;

    // Input for the second matrix
    std::cout << "Enter values for the second matrix:" << std::endl;
    for (int i = 0; i < threadInfo[0].matrixB.rows; ++i) {
        for (int j = 0; j < threadInfo[0].matrixB.cols; ++j) {
            std::cin >> threadInfo[0].matrixB.data[i][j];
        }
    }

    // Check if matrices can be multiplied
    if (threadInfo[0].matrixA.cols != threadInfo[0].matrixB.rows) {
        std::cerr << "Error: Matrix multiplication not possible with given matrices." << std::endl;
        return 1;
    }

    // Set the size for the result matrix
    threadInfo[0].resultMatrix.rows = threadInfo[0].matrixA.rows;
    threadInfo[0].resultMatrix.cols = threadInfo[0].matrixB.cols;

    // Create threads
    for (int i = 0; i < threadInfo[0].resultMatrix.rows; ++i) {
        threadInfo[i].threadID = i;
        pthread_create(&threads[i], NULL, multiply, (void*)&threadInfo[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < threadInfo[0].resultMatrix.rows; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Display the result matrix
    std::cout << "Output matrix: [" << threadInfo[0].resultMatrix.rows << "x" << threadInfo[0].resultMatrix.cols << "]" << std::endl;
    for (int i = 0; i < threadInfo[0].resultMatrix.rows; ++i) {
        for (int j = 0; j < threadInfo[0].resultMatrix.cols; ++j) {
            std::cout << threadInfo[0].resultMatrix.data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}