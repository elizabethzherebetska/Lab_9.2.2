#define _CRT_SECURE_NO_WARNINGS // ������ ������������ ��� ��������� �������
#include <stdio.h>
#include <math.h>
#define WAIT_FOR_KEY_PRESS
#define VERIFY_RELATIONSHIP 

// ������� ��� ��������, �� � ��������� �����������
bool is_right_triangle(float a, float b, float c) {
    return fabs(c * c - (a * a + b * b)) < 1e-6;
}

// ������� ��� �������� ������������ 1/H^2 = 1/a^2 + 1/b^2
bool verify_relationship(float a, float b) {
    float c = sqrt(a * a + b * b); // ���������
    float H = (a * b) / c; // ������, ��������� �� ���������

    float leftSide = 1 / (H * H);
    float rightSide = (1 / (a * a)) + (1 / (b * b));

    return fabs(leftSide - rightSide) < 1e-6;
}

int main() {
    float a, b;
    printf("Enter the lengths of the two legs of the right triangle (a and b):\n");

    // ��������, �� ������ ��������� ��� ��������
    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input. Please enter two numeric values.\n");
        return 1; // ���������� � ����� �������
    }

    // ���������� ���������
    float c = sqrt(a * a + b * b);

    // ��������, �� � ��������� �����������
    if (is_right_triangle(a, b, c)) {
        printf("The triangle is a right triangle.\n");

#ifdef VERIFY_RELATIONSHIP
        // �������� ������������ ��� ������ �� ������ �� ���������
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

    // �������� �� ���������� ������, ���� ��������� ������ WAIT_FOR_KEY_PRESS
#ifdef WAIT_FOR_KEY_PRESS
    printf("Press Enter to exit...\n");
    getchar(); // ���� ��������� ����� ����� ���� scanf
    getchar(); // ���� �� ����� ���, ��� ��������� ��������
#endif
    return 0;
}


