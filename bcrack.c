#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_HASH_LENGTH 100

int main() {
    char wordlistPath[MAX_PASSWORD_LENGTH];
    char hash[MAX_HASH_LENGTH];

    // Prompt the user for the wordlist path
    printf("Enter the path to the wordlist: ");
    fgets(wordlistPath, sizeof(wordlistPath), stdin);
    wordlistPath[strcspn(wordlistPath, "\n")] = '\0';

    // Prompt the user for the bcrypt hash
    printf("Enter the bcrypt hash to crack: ");
    fgets(hash, sizeof(hash), stdin);
    hash[strcspn(hash, "\n")] = '\0';

    // Open the wordlist file
    FILE* wordlistFile = fopen(wordlistPath, "r");
    if (wordlistFile == NULL) {
        printf("Failed to open the wordlist file.\n");
        return 1;
    }

    // Iterate through each password in the wordlist
    char password[MAX_PASSWORD_LENGTH];
    while (fgets(password, sizeof(password), wordlistFile) != NULL) {
        password[strcspn(password, "\n")] = '\0';

        // Generate the bcrypt hash for the current password
        char* generatedHash = crypt(password, hash);
        
        // Compare the generated hash with the provided hash
        if (strcmp(generatedHash, hash) == 0) {
            printf("Password found: %s\n", password);
            break;
        }
    }

    // Close the wordlist file
    fclose(wordlistFile);

    return 0;
}