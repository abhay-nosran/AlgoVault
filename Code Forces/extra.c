#include <stdio.h>
#include <math.h>
#include <string.h>

long long mod = 9223372036854775807 ;

long long calculateValue(const char* s, int m) {
    long long value = 1; 
    int len = strlen(s); 

    
    for (int i = 0; i < len; ++i) {
        int ord = (int)s[i]; 
        int power = m - i; 
        value *= pow(ord, power)%mod;
    }
    return value;
}

int main() {
    const char* s = "example"; 
    int m = 5; 
    
    long long result = calculateValue(s, m);
    printf("The calculated value is: %lld\n", result);

    return 0;
}
