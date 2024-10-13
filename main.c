#include <stdio.h>
#include <string.h>
#include "salsa20.h"

int main() {
    char plaintext[PLAINTEXT_MAX_LEN];
    char key[KEY_LEN];
    char nonce[NONCE_LEN];

    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read plaintext, key, and nonce from the file
    if (fgets(plaintext, PLAINTEXT_MAX_LEN, file) == NULL ||
        fgets(key, KEY_LEN, file) == NULL ||
        fgets(nonce, NONCE_LEN, file) == NULL) {
        printf("Error: Could not read input from file.\n");
        fclose(file);
        return 1;
    }

    // Remove any trailing newlines
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    nonce[strcspn(nonce, "\n")] = '\0';

    // Close the file
    fclose(file);

    // Debugging: Print values read from file
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Nonce: %s\n", nonce);

    // Initialize Salsa20 with the key and nonce
    salsa20_initialize(key, nonce);

    // Encrypt the plaintext
    char ciphertext[PLAINTEXT_MAX_LEN * 2];  // Hex output
    salsa20_encrypt(plaintext, ciphertext);

    // Output the encrypted text
    printf("Encrypted: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decrypted[PLAINTEXT_MAX_LEN];
    salsa20_decrypt(ciphertext, decrypted);

    // Output the decrypted text
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
