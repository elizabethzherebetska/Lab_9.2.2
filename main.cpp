#define _CRT_SECURE_NO_WARNINGS // Вимикає попередження про небезпечні функції
#include <stdio.h>
#include <math.h>
#define WAIT_FOR_KEY_PRESS
#define VERIFY_RELATIONSHIP 

// Функція для перевірки, чи є трикутник прямокутним
bool is_right_triangle(float a, float b, float c) {
    return fabs(c * c - (a * a + b * b)) < 1e-6;
}

// Функція для перевірки співвідношення 1/H^2 = 1/a^2 + 1/b^2
bool verify_relationship(float a, float b) {
    float c = sqrt(a * a + b * b); // гіпотенуза
    float H = (a * b) / c; // висота, проведена до гіпотенузи

    float leftSide = 1 / (H * H);
    float rightSide = (1 / (a * a)) + (1 / (b * b));

    return fabs(leftSide - rightSide) < 1e-6;
}

int main() {
    float a, b;
    printf("Enter the lengths of the two legs of the right triangle (a and b):\n");

    // Перевірка, чи успішно прочитано два значення
    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input. Please enter two numeric values.\n");
        return 1; // Завершення з кодом помилки
    }

    // Обчислення гіпотенузи
    float c = sqrt(a * a + b * b);

    // Перевірка, чи є трикутник прямокутним
    if (is_right_triangle(a, b, c)) {
        printf("The triangle is a right triangle.\n");

#ifdef VERIFY_RELATIONSHIP
        // Перевірка співвідношення для катетів та висоти до гіпотенузи
        if (verify_relationship(a, b)) {
            printf("The relationship 1/H^2 = 1/a^2 + 1/b^2 holds true for the given triangle.\n");
        }
        else {
            printf("The relationship 1/H^2 = 1/a^2 + 1/b^2 does not hold for the given triangle.\n");
        }
#endif
    }
    else {
        printf("The triangle is not a right triangle.\n");
    }

    // Затримка до натискання клавіші, якщо визначено макрос WAIT_FOR_KEY_PRESS
#ifdef WAIT_FOR_KEY_PRESS
    printf("Press Enter to exit...\n");
    getchar(); // Читає попередній новий рядок після scanf
    getchar(); // Чекає на новий ввід, щоб завершити програму
#endif
    return 0;
}


