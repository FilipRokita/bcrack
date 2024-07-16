#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_HASH_LENGTH 100

int main() {
    char wordlist[MAX_PASSWORD_LENGTH];
    char hash[MAX_HASH_LENGTH];

    printf("Enter the path to the wordlist file: ");
    fgets(wordlist, sizeof(wordlist), stdin);
    wordlist[strcspn(wordlist, "\n")] = '\0';

    printf("Enter the bcrypt hash to crack: ");
    fgets(hash, sizeof(hash), stdin);
    hash[strcspn(hash, "\n")] = '\0';

    FILE *file = fopen(wordlist, "r");
    if (file == NULL) {
        printf("Failed to open wordlist file.\n");
        return 1;
    }

    char password[MAX_PASSWORD_LENGTH];
    while (fgets(password, sizeof(password), file)) {
        password[strcspn(password, "\n")] = '\0';

        char *encrypted = crypt(password, hash);
        if (strcmp(encrypted, hash) == 0) {
            printf("Password found: %s\n", password);
            fclose(file);
            return 0;
        }
    }

    printf("Password not found in the wordlist.\n");
    fclose(file);
    return 0;
}