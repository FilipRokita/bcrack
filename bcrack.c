#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORD_LENGTH 256

int main() {
    char wordlistFile[MAX_PASSWORD_LENGTH];
    char hashToCrack[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    FILE *wordlist;

    // Ask user for wordlist file
    printf("Enter the path to the wordlist file: ");
    fgets(wordlistFile, sizeof(wordlistFile), stdin);
    wordlistFile[strcspn(wordlistFile, "\n")] = '\0';

    // Ask user for hash to crack
    printf("Enter the hash to crack: ");
    fgets(hashToCrack, sizeof(hashToCrack), stdin);
    hashToCrack[strcspn(hashToCrack, "\n")] = '\0';

    // Open wordlist file
    wordlist = fopen(wordlistFile, "r");
    if (wordlist == NULL) {
        printf("Failed to open wordlist file.\n");
        return 1;
    }

    // Read each password from the wordlist file and try to crack the hash
    while (fgets(password, sizeof(password), wordlist) != NULL) {
        password[strcspn(password, "\n")] = '\0';

        // Generate the hash for the current password
        char *hashedPassword = crypt(password, hashToCrack);

        // Compare the generated hash with the hash to crack
        if (strcmp(hashedPassword, hashToCrack) == 0) {
            printf("Password cracked: %s\n", password);
            break;
        }

        printf("Tried password: %s\n", password);
    }

    // Close the wordlist file
    fclose(wordlist);

    return 0;
}