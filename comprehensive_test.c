int global_var = 100;

int add(int a, int b) {
    return a + b;
}

int subtract(int x, int y) {
    int result = x - y;
    return result;
}

int main() {
    int local1 = 10;
    int local2 = 20;
    
    int sum = add(local1, local2);
    int diff = subtract(local2, local1);
    
    if (sum > diff) {
        return sum;
    } else {
        return diff;
    }
}