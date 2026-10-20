//DEQUITO M-2L
// 1-BSCS CMSC 18 Lab #4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    START:
    printf("\nMeow. This is the gansta cat boss score computer. Please enter the student name and their score.");

    //loop para makuha ang name & score ng students
    int score[10];
    char student_name[10][100];
    for (int i = 0; i < 10; i++) {
        printf("\nStudent %d Name: ", i + 1);
        fgets(student_name[i], sizeof(student_name[i]), stdin);
        student_name[i][strcspn(student_name[i], "\n")] = 0; 
        printf("Student %d Score: ", i + 1);
        scanf("%d", &score[i]);
        // clear input buffer para walay issue kay fget
        while (getchar() != '\n');
    }

    //establish yung total items of the test or exam
    int totalItems;
    printf("\nEnter the total number of items in the test/exam: \n");
    scanf("%d", &totalItems);
    while (getchar() != '\n');

    printf("_________________________________________________________________________\n");

    //scores entered
    printf("\nScores entered:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d/%d\n", student_name[i], score[i], totalItems);
    }

     printf("_________________________________________________________________________\n");

    //finding the average score
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += score[i];
    }
    float average = (float)sum / 10;
    printf("\n[Average Score]:%.2f\n\n", average);

    //highest
    int size = sizeof(score) / sizeof(score[0]);
    int highest_index = 0;
    for (int i = 1; i < size; i++) {
        if (score[i] > score[highest_index]) {
            highest_index = i;
        }
    }
    //if daghan makakuha highest 
    if (score[highest_index] == score[highest_index]) {
        printf("[Highest Scores]: \n");
        for (int i = 0; i < size; i++) {
            if (score[i] == score[highest_index]) {
                printf("%s, %d/%d\n", student_name[i], score[i], totalItems);
            }
        }
    } 
    else {
    printf("[Highest Score]: \n%s, %d/%d.\n", student_name[highest_index], score[highest_index], totalItems);
    }

    //lowest 
    int lowest_index = 0;
    for (int i = 1; i < size; i++) {
        if (score[i] < score[lowest_index]) {
            lowest_index = i;
        }
    }
    //if daghan makakuha lowest
    if (score[lowest_index] == score[highest_index]) {
        printf("[Lowest Scores]: \n");
        for (int i = 0; i < size; i++) {
            if (score[i] == score[lowest_index]) {
                printf("%s, %d/%d.\n", student_name[i], score[i], totalItems);
            }
        }
    } 
    else {
    printf("\n[Lowest Score]: \n%s, %d/%d.\n", student_name[lowest_index], score[lowest_index], totalItems);
    }

    //separating (for the traversing chuchchu)
    char passing_names[10][100];
    int passing_scores[10];
    char failing_names[10][100];
    int failing_scores[10];
    
    int passing_count = 0;
    int failing_count = 0;
    
    //distinction 
    for (int i = 0; i < size; i++) {
        if (score[i] * 100 >= totalItems * 60) {
            strcpy(passing_names[passing_count], student_name[i]);
            passing_scores[passing_count] = score[i];
            passing_count++;
        } else {
            strcpy(failing_names[failing_count], student_name[i]);
            failing_scores[failing_count] = score[i];
            failing_count++;
        }
    }
    
    //traverse passing & failing arrays
    printf("\n[PASSED (%d)]:\n", passing_count);
    for (int i = 0; i < passing_count; i++) {
        printf("%s : %d/%d\n", passing_names[i], passing_scores[i], totalItems);
    }
    
    printf("\n[FAILED (%d)]:\n", failing_count);
    for (int i = 0; i < failing_count; i++) {
        printf("%s : %d/%d\n", failing_names[i], failing_scores[i], totalItems);
    }

     printf("_________________________________________________________________________\n");

    //if mag ulit or what
    printf("\nDo you want to record another set of scores? (1 for yes): ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n');
    if (choice == 1) {
        goto START;
    } else {
        return 0;
    }

    return 0;
}