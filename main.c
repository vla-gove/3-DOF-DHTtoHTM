#include <stdio.h>
#include <math.h>

void print(double mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(double a[4][4], double b[4][4], double result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void homogeneous_transformation(double theta1, double theta2, double theta3, double a1, double a2, double a3, double alpha1, double alpha2, double alpha3, double d1, double d2, double d3, double result[4][4]) {
    double T1[4][4] = {{cos(theta1), -sin(theta1)*cos(alpha1), sin(theta1)*sin(alpha1), a1*cos(theta1)},
                       {sin(theta1), cos(theta1)*cos(alpha1), -cos(theta1)*sin(alpha1), a1*sin(theta1)},
                       {0, sin(alpha1), cos(alpha1), d1},
                       {0, 0, 0, 1}};
    double T2[4][4] = {{cos(theta2), -sin(theta2)*cos(alpha2), sin(theta2)*sin(alpha2), a2*cos(theta2)},
                       {sin(theta2), cos(theta2)*cos(alpha2), -cos(theta2)*sin(alpha2), a2*sin(theta2)},
                       {0, sin(alpha2), cos(alpha2), d2},
                       {0, 0, 0, 1}};
    double T3[4][4] = {{cos(theta3), -sin(theta3)*cos(alpha3), sin(theta3)*sin(alpha3), a3*cos(theta3)},
                       {sin(theta3), cos(theta3)*cos(alpha3), -cos(theta3)*sin(alpha3), a3*sin(theta3)},
                       {0, sin(alpha3), cos(alpha3), d3},
                       {0, 0, 0, 1}};
    double T23[4][4];
    multiply(T2, T3, T23);
    multiply(T1, T23, result);
}

int main() {
    //configure dh table parameters here
    double theta1 = M_PI / 3;
    double theta2 = M_PI / 4;
    double theta3 = M_PI / 5;
    double a1 = 1.35;
    double a2 = 1.25;
    double a3 = 1.15;
    double alpha1 = 0;
    double alpha2 = 0;
    double alpha3 = 0;
    double d1 = 0;
    double d2 = 0;
    double d3 = 0.5;
    double result[4][4];
    //calculate and print the transformation matrix
    homogeneous_transformation(theta1, theta2, theta3, a1, a2, a3, alpha1, alpha2, alpha3, d1, d2, d3, result);
    printf("homogenous transformation matrix is:\n");
    print(result);
    return 0;
}