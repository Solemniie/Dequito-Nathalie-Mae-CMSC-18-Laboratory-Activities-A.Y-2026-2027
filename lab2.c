#include <stdio.h>

int main() {
  // 1. Fix ALL errors and rename any technically legal but unconventional variable names.

    int count = 5;
    float variable = 3.14;
    char letter = 'a';
    int value = 10;
    char currency = '$';
    char percent = '%';
      // I added a new variable (percent).
    int count_two = 100;

  // 2. Print all previous data into one string in a Mad Lib.
  
    printf("There are %d boxes in %c table. You have a %.2f%c chance to win %d%c. Each box costs %d%c.\n", count, letter, 
    variable, percent, count_two, currency, value, currency);

  // 3. Initialize a string variable, assign a value to that variable through user input, and output the value in the console.
    int boxes_bought;
    printf("How many boxes would you like to buy? \n");
    scanf("%d", &boxes_bought);
      if (boxes_bought > 5){
        printf("There are only 5 boxes available.");
      }
      else if (boxes_bought == 1){
        printf("You have bought %d box.\n", boxes_bought);
      }
      else if (boxes_bought > 1){
        printf("You have bought %d boxes.\n", boxes_bought);
      }
      else {
        printf ("You have not bought any boxes.\n");
      }
      
  return 0;
}
