#include <spede/stdio.h>

/**
 * Returns the length of a NULL terminated string
 * @param str pointer to the string
 * @return value indicating the length of the string
 */
int strlen(char *str) {
    //Implement me!
    if(str == NULL){
        printf("NULL pointer!");
        return 0;
    }
    char string_char = str[0];
    int str_length = 0;
    int string_iterator = 0;

    while(string_char != '\0'){
        str_length++;
        string_char = str[++string_iterator];
    }
    
    return str_length;
}

/**
 * Prints a string to the screen starting at 0, 0
 * @param str pointer to the string to print
 */
void puts(char *str) {
    if (str == NULL) {
        printf("NULL pointer!\n");
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        *((char *) (0xB8000 + (i * 2))) = str[i];
    }
}

/**
 * Main function
 */
void main(void) {
    char buf[128] = {0};
    int year = 2025;

    *((char *) 0xB8000) = 'W';

    printf("Hello, world!\n");
    printf("Welcome to %s!\n", OS_NAME);

    puts("Hello, World!\n");

    snprintf(buf, sizeof(buf), "welcome to %s!\n", OS_NAME);
    printf("The buffer size is %d bytes\n", strlen(buf));
    puts(buf);

    printf("CPE/CSC 159 for Spring/Fall %d will be fun!\n", year);
}
