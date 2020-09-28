#include <stdio.h>

int letters(int a) {
    if (a == 1 || a == 2 || a == 6) {
        return 3;
    }
    else if (a == 4 || a == 5 || a == 9) {
        return 4;
    }
    else if (a == 3 || a == 7 || a == 8) {
        return 5;
    }
    else {
        printf("Not a valid integer input to letters().\n");
    }
}

int letters_two_digit(int a) {
    if (a == 10) {
        return 3;  
    }
    else if (a == 11 || a == 12) {
        return 6;
    }
    else if (a == 15 || a == 16) {
        return 7;
    }
    else if (a == 13 || a == 14 || a == 18 || a == 19) {
        return 8;
    }
    else if (a == 17) {
        return 9;
    }
    else {
        printf("Not a valid integer input to letters_two_digit.\n");
    }
}

int main() {
    for (int i = 1; i < 1001; i++) {
        char str[4];
        sprintf(str, "%d", i);
        printf("%s\n", str);
        int length = strlen(str);

        int letter_count = 0;

        if (length == 1) {
            int a = str - '0';
            letter_count += letters(a);
        }
        else if (length == 2) {
            int a = str[length] - '0';
            a = a*10;
            a += str[length - 1] - '0';
            letter_count += letters_two_digit(a);
        }
        else if (length > 2) {

        }
        else {
            printf("Error reading string. Input was: %s\n", str);
        }



        for (int j = 0; j < strlen(str); j++) {
            if (str[j] != '\000') {
                int a = str[j] - '0';
                // Thousands
                if (j == 0) {
                    // Ignore zero
                    if (a == 0) {
                        ;
                    }
                    // Three letter words
                    else if (a == 1 || a == 2 || a == 6) {
                        letters += 3;
                    }
                    // Four letter words
                    else if (a == 4 || a == 5 || a == 9) {
                        letters += 4;
                    }
                    // Five letter words
                    else if (a == 3 || a == 7 || a == 8) {
                        letters += 5;
                    }
                    else {
                        printf("Read error: digit in ones column was not in range 0-9");
                    }
                }
                // Hundreds
                else if (j == 1) {
                    // Ignore zero
                    if (a == 0) {
                        ;
                    }
                    else if (a == )
                }
                // Tens
                else if (j == 2) {

                }
                // Ones
                else if (j == 3) {

                }
            }
        }
    }
}