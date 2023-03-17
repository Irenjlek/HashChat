#include "Chat.h"
#include "iostream"
#include "string.h"
#include "HashTable.h"

Chat::Chat() {
    data = new HashTable();
}
void Chat::reg(char login[LOGINLENGTH], char pass[]) {
    data->add(login, pass);
}
bool Chat::login(char login[LOGINLENGTH], char pass[]) {
    return strcmp(pass, data->find(login)) == 0;
}