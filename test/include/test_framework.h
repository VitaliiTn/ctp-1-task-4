#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Допустима похибка для порівняння дійсних чисел
const double EPSILON = 0.0001;

// Функція для порівняння дійсних чисел з урахуванням похибки
inline bool approx_equal(double a, double b) {
    return std::fabs(a - b) < EPSILON;
}

// Функція для порівняння векторів
template<typename T>
bool vectors_equal(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// Макрос для перевірки умови
#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cout << "Test failed at " << __FILE__ << ":" << __LINE__ << "\n"; \
            std::cout << "Assertion failed: " << #condition << "\n"; \
            return false; \
        } \
    } while (0)

// Макрос для перевірки рівності векторів
#define ASSERT_VECTORS_EQUAL(expected, actual) \
    do { \
        if (!vectors_equal(expected, actual)) { \
            std::cout << "Test failed at " << __FILE__ << ":" << __LINE__ << "\n"; \
            std::cout << "Vectors are not equal\n"; \
            std::cout << "Expected: ["; \
            for (size_t i = 0; i < expected.size(); ++i) { \
                std::cout << expected[i]; \
                if (i < expected.size() - 1) std::cout << ", "; \
            } \
            std::cout << "]\n"; \
            std::cout << "Actual: ["; \
            for (size_t i = 0; i < actual.size(); ++i) { \
                std::cout << actual[i]; \
                if (i < actual.size() - 1) std::cout << ", "; \
            } \
            std::cout << "]\n"; \
            return false; \
        } \
    } while (0)

// Макрос для перевірки рівності дійсних чисел з урахуванням похибки
#define ASSERT_APPROX_EQUAL(expected, actual) \
    do { \
        if (!approx_equal(expected, actual)) { \
            std::cout << "Test failed at " << __FILE__ << ":" << __LINE__ << "\n"; \
            std::cout << "Expected: " << expected << ", Actual: " << actual << "\n"; \
            return false; \
        } \
    } while (0)

#endif // TEST_FRAMEWORK_H