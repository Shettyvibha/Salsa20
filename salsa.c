#include <stdio.h>
#include <string.h>
#include "salsa20.h"

// Placeholder for Salsa20 state initialization
void salsa20_initialize(const char* key, const char* nonce) {
    printf("Salsa20 initialized with key: %s and nonce: %s\n", key, nonce);
}

// Placeholder for Salsa20 encryption
void salsa20_encrypt(const char* plaintext, char* ciphertext) {
    strcpy(ciphertext, plaintext);  // For now, we just copy the plaintext
    printf("Salsa20 encryption done. Ciphertext: %s\n", ciphertext);
}

// Placeholder for Salsa20 decryption
void salsa20_decrypt(const char* ciphertext, char* decrypted) {
    strcpy(decrypted, ciphertext);  // For now, we just copy the ciphertext
    printf("Salsa20 decryption done. Decrypted text: %s\n", decrypted);
}
