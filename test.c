#include <stdio.h>
#include <stdarg.h>

// Variadic function to print given arguments
void print(int n, ...) {
    va_list args;
    va_start(args, n);
    int i = 0;
    int sum = 0;
    while(i < n){
        sum = sum + va_arg(args, int);
        i++;
    }
    printf("%d\n", sum);
    va_end(args);
}
int main() {
  
  	print(5, 1, 2, 3, 4, 5);
    return 0;
}