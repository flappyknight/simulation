#include "utils.h"

double mod(double num1, double num2){
    return num1 - num2 * (int)(num1 / num2);
}