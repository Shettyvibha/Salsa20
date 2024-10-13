#ifndef SALSA20_H
#define SALSA20_H

#define PLAINTEXT_MAX_LEN 256
#define KEY_LEN 65  // 64 hex characters + null terminator
#define NONCE_LEN 17 // 16 hex characters + null terminator

void salsa20_initialize(const char* key, const char* nonce);
void salsa20_encrypt(const char* plaintext, char* ciphertext);
void salsa20_decrypt(const char* ciphertext, char* decrypted);

#endif // SALSA20_H
