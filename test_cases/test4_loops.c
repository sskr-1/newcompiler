int main() {
    int sum = 0;
    
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    
    int j = 1;
    while (j <= 5) {
        sum += j;
        j++;
    }
    
    return sum;
}