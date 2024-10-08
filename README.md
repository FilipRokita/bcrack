# BCrack: Bcrypt Hash Crackerr

This C program prompts the user for a file path to a wordlist containing potential passwords and a bcrypt hash to crack. It reads each password from the wordlist, generates a bcrypt hash for each password, and compares it with the provided hash. If a match is found, it prints the password. The program assumes the presence of bcrypt-compatible hash and uses the crypt() function for hash generation. If successful, it terminates after finding the password.

## Requirements

- Clang compiler
- Make
- Linux environment (due to the use of `<unistd.h>` for `crypt`)

## How to Use

1. **Compile the Program:**

```
make bcrack
```

2. **Run the Program:**

```
./bcrack
```

3. **Follow the Prompts:**

- Enter the path to the wordlist file containing passwords to test.
- Enter the bcrypt hash that you want to crack.

4. **Outcome:**

- The program will read each password from the wordlist, generate its bcrypt hash, and compare it with the provided hash.
- If a matching password is found, it will be displayed.

## Example
```
$ ./bcrack
Enter the path to the wordlist: example_wordlist.txt
Enter the bcrypt hash to crack: $2a$12$g/Ee8Hm1g1/5spm2V733euokwUNVkOYqLvX8YPCcYBIQohj79L5KO
Password found: 123456
```

## Note

This tool is intended for educational purposes only. Use it responsibly and at your own risk.

For licensing information, refer to the [LICENSE](LICENSE).
