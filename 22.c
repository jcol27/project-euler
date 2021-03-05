#include <stdio.h>

/*
SEE 22.py

Using names.txt (right click and 'Save Link/Target As...'), a 46K 
text file containing over five-thousand first names, begin by 
sorting it into alphabetical order. Then working out the alphabetical 
value for each name, multiply this value by its alphabetical position 
in the list to obtain a name score.

What is the total of all the name scores in the file?
*/

int main() {
    FILE *fp;
    char names[60000];
    

    fp = fopen("22_names.txt", "rb");
    fgets(names, 60000, (FILE*)fp);

    

}