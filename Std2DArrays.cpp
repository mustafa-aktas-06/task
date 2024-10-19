#include "Std2DArrays.h"
#include <iostream>
#include <stdexcept>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;

    // Fill diagonals starting from the top-right corner
    for (int col = columns - 1; col >= 0; col--) { // Start from the rightmost column
        int j = col;
        for (int i = 0; j < columns && i < rows; i++, j++) {
            arr[i][j] = startValue++;
        }
    }

    // Fill diagonals starting from the first column (except the first row)
    for (int row = 1; row < rows; row++) {
        int i = row;
        int j = 0; // Start from the first column
        while (i < rows && j < columns) {
            arr[i][j] = startValue++;
            i++;
            j++;
        }
    }
}

void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
