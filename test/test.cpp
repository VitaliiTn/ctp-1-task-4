#include "test_framework.h"
#include "../src/functions.h"

// Тест для функції factorial
bool test_factorial() {
    // Тест базових випадків
    ASSERT(factorial(0) == 1);
    ASSERT(factorial(1) == 1);
    
    // Тест звичайних випадків
    ASSERT(factorial(3) == 6);
    ASSERT(factorial(4) == 24);
    ASSERT(factorial(5) == 120);
    
    // Тест більших чисел
    ASSERT(factorial(6) == 720);
    ASSERT(factorial(7) == 5040);
    ASSERT(factorial(10) == 3628800);
    
    // Тест від'ємних чисел
    ASSERT(factorial(-1) == 0);
    ASSERT(factorial(-5) == 0);
    
    return true;
}

// Тест для функції isPrime
bool test_isPrime() {
    // Тест випадків, які не є простими числами
    ASSERT(!isPrime(0));
    ASSERT(!isPrime(1));
    ASSERT(!isPrime(4));
    ASSERT(!isPrime(6));
    ASSERT(!isPrime(8));
    ASSERT(!isPrime(9));
    ASSERT(!isPrime(10));
    ASSERT(!isPrime(12));
    ASSERT(!isPrime(15));
    ASSERT(!isPrime(16));
    ASSERT(!isPrime(20));
    ASSERT(!isPrime(21));
    ASSERT(!isPrime(25));
    ASSERT(!isPrime(100));
    
    // Тест простих чисел
    ASSERT(isPrime(2));
    ASSERT(isPrime(3));
    ASSERT(isPrime(5));
    ASSERT(isPrime(7));
    ASSERT(isPrime(11));
    ASSERT(isPrime(13));
    ASSERT(isPrime(17));
    ASSERT(isPrime(19));
    ASSERT(isPrime(23));
    ASSERT(isPrime(29));
    ASSERT(isPrime(31));
    ASSERT(isPrime(97));
    
    // Тест від'ємних чисел
    ASSERT(!isPrime(-2));
    ASSERT(!isPrime(-7));
    ASSERT(!isPrime(-11));
    
    return true;
}

// Тест для функції gcd
bool test_gcd() {
    // Базові тести
    ASSERT(gcd(1, 1) == 1);
    ASSERT(gcd(2, 2) == 2);
    
    // Один з аргументів дорівнює 0
    ASSERT(gcd(5, 0) == 5);
    ASSERT(gcd(0, 7) == 7);
    ASSERT(gcd(0, 0) == 0);
    
    // Звичайні випадки
    ASSERT(gcd(12, 8) == 4);
    ASSERT(gcd(48, 18) == 6);
    ASSERT(gcd(56, 42) == 14);
    ASSERT(gcd(24, 36) == 12);
    ASSERT(gcd(17, 13) == 1);  // Взаємно прості числа
    
    // Перевірка комутативності (gcd(a,b) == gcd(b,a))
    ASSERT(gcd(15, 25) == gcd(25, 15));
    ASSERT(gcd(72, 63) == gcd(63, 72));
    
    // Тест з від'ємними числами
    ASSERT(gcd(-12, 8) == 4);
    ASSERT(gcd(12, -8) == 4);
    ASSERT(gcd(-12, -8) == 4);
    ASSERT(gcd(-48, 18) == 6);
    
    // Більші числа
    ASSERT(gcd(252, 105) == 21);
    ASSERT(gcd(1071, 462) == 21);
    
    return true;
}

int main() {
    int passed = 0;
    int total = 3;
    
    std::cout << "Running tests for Functions Practice\n";
    std::cout << "====================================\n\n";
    
    // Запуск тесту для factorial
    std::cout << "Test 1: factorial function... ";
    if (test_factorial()) {
        std::cout << "PASSED\n";
        passed++;
    } else {
        std::cout << "FAILED\n";
    }
    
    // Запуск тесту для isPrime
    std::cout << "Test 2: isPrime function... ";
    if (test_isPrime()) {
        std::cout << "PASSED\n";
        passed++;
    } else {
        std::cout << "FAILED\n";
    }
    
    // Запуск тесту для gcd
    std::cout << "Test 3: gcd function... ";
    if (test_gcd()) {
        std::cout << "PASSED\n";
        passed++;
    } else {
        std::cout << "FAILED\n";
    }
    
    std::cout << "\n====================================\n";
    std::cout << "Tests passed: " << passed << "/" << total << "\n";
    
    if (passed == total) {
        std::cout << "All tests passed! Great job!\n";
        return 0;
    } else {
        std::cout << "Some tests failed. Please check your implementations.\n";
        return 1;
    }
}