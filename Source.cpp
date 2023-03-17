#include "Chat.h"
#include "HashTable.h"
#include <iostream>

int main() {
	Chat chat;
	Name n1 = "irina";
	Name n2 = "roman";
	Password p1 = "qwert";
	Password p2 = "asdfg";


	chat.reg(n1, p1);
	chat.reg(n2, p2);

	std::cout << chat.login(n1, p1) << std::endl;
	std::cout << chat.login(n2, p1) << std::endl;

	return 0;
}