//
// Created by 0xtriboulet on 3/30/2023.
//
#include "Strings.h"

#ifndef REVENANT_UTILITIES_H
#define REVENANT_UTILITIES_H

#define XOR_DECRYPT(data, key, output) do { \
    size_t i, len = wcslen(data); \
    for (i = 0; i < len; ++i) { \
        (output)[i] = (data)[i] ^ (key)[i % wcslen(key)]; \
    } \
    (output)[i] = '\0'; \
} while (0)

static const wchar_t GENERATED_PASSWORD[] = S_XK;

#define DECRYPT_USER_AGENT(output) XOR_DECRYPT(CONFIG_USER_AGENT, GENERATED_PASSWORD, output)
#define DECRYPT_HOST(output) XOR_DECRYPT(CONFIG_HOST, GENERATED_PASSWORD, output)


void *mem_set(void *dest, int value, size_t count);
void *mem_cpy(void *dest, const void *src, size_t count);

size_t str_len(const char* str);

char* str_dup(const char* str);
char* mem_cat(const void* ptr1, size_t size1, const void* ptr2, size_t size2);
char** split_first_space(const char* str);
size_t sizeof_w(const wchar_t* str);
wchar_t* wide_concat(const wchar_t* str1, const wchar_t* str2);

#if CONFIG_NATIVE
void normalize_path(char* path);
#endif



#endif //REVENANT_UTILITIES_H
