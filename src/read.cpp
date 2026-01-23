#include <stdio.h>

struct student {
    int roll;
    char name[30];
    char address[30];
    int mark1, mark2, mark3;
};

int main() {
    struct student s[2];
    int i;

    /* Reading data */
    for(i = 0; i < 2; i++) {
        printf("\nEnter details of student %d\n", i+1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Address: ");
        scanf("%s", s[i].address);
        printf("Marks in 3 subjects: ");
        scanf("%d %d %d", &s[i].mark1, &s[i].mark2, &s[i].mark3);
    }

    /* Printing failed students */
    printf("\n--- Failed Students ---\n");
    for(i = 0; i < 2; i++) {
        if(s[i].mark1 < 40 || s[i].mark2 < 40 || s[i].mark3 < 40) {
            printf("Roll: %d  Name: %s\n", s[i].roll, s[i].name);
        }
    }

    return 0;
}
