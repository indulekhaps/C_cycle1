#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], substring[100];

    // Input the first string
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Input the second string
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Concatenate the two strings
    strcat(str1, str2);

    // Display the concatenated string
    printf("Concatenated string: %s\n", str1);

    // Input the substring to search for
    printf("Enter a substring to search for: ");
    scanf("%s", substring);

    // Search for the substring in the concatenated string
    if (strstr(str1, substring) != NULL) {
        printf("'%s' found in the concatenated string.\n", substring);
    } else {
        printf("'%s' not found in the concatenated string.\n", substring);
    }

    return 0;
}

