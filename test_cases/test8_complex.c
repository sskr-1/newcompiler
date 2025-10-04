// Complex test with multiple features
#include <stdio.h>

struct Student {
    int id;
    float grade;
    char name[50];
};

int calculateAverage(int scores[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum / count;
}

int main() {
    struct Student student;
    student.id = 123;
    student.grade = 85.5;
    
    int scores[5] = {90, 85, 88, 92, 87};
    int average = calculateAverage(scores, 5);
    
    if (average >= 90) {
        printf("Excellent!\n");
    } else if (average >= 80) {
        printf("Good!\n");
    } else {
        printf("Needs improvement.\n");
    }
    
    return 0;
}