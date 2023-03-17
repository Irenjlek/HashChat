#pragma once
#include "HashTable.h"
#include "string.h"

#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    void reg(char login[LOGINLENGTH], char pass[]);
    bool login(char login[LOGINLENGTH], char pass[]);

private:
    HashTable* data;
};