#include <iostream>
#include <vector>

int main() {
    size_t r{}, c{};
    std::cin >> r >> c;
    
    std::vector<std::vector<int>> matrix(r, std::vector<int>(c));
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    int top{ 0 };
    int bottom{ (int)r-1 };
    int left{ 0 };
    int right{ (int)c-1 };
    
    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; ++i) {
            std::cout << matrix[i][left] << ' ';
        }
        ++left;

        for (int i = left; i <= right; ++i) {
            std::cout << matrix[bottom][i] << ' ';
        }
        --bottom;

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                std::cout << matrix[i][right] << ' ';
            }
            --right;
        }
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                std::cout << matrix[top][i] << ' ';
            }
            ++top;
        }
           
    }

	return 0;
}
