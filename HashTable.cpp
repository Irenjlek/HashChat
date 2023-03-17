#include "HashTable.h"
#include <iostream>

HashTable::HashTable() {
    count = 0;
    mem_size = 24;
    array = new Pair[mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}
int HashTable::hash_func(Name name, int offset) {

    // вычисляем индекс
    int sum = 0, i = 0;
    for (; i < strlen(name); i++) {
        sum += name[i];
    }

    return (sum % mem_size + offset * offset) % mem_size;
}
void HashTable::add(Name name, Password passwd) {
    if (count >= mem_size)
        resize();
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(name, i);
        if (array[index].status == enPairStatus::free) {
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }

    if (i >= mem_size) return; // все перебрали, нет места

    // кладем в свободную ячейку пару
    array[index] = Pair(name, passwd);
    count++;
}

char* HashTable::find(Name name)
{
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(name, i);
        if (array[index].status == enPairStatus::engaged) {
            return array[index]._passwd;
        }
    }
    return nullptr;
}

void HashTable::del(Name name)
{
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(name, i);       
            if (array[index].status == enPairStatus::engaged && strcmp(array[index]._name, name) == 0) {
                array[index].status = enPairStatus::deleted;
                count--;
            }                    
    }
}

void HashTable::show() {
    for (int i = 0; i < count; i++) {
        std::cout << array[i]._name << " - " << array[i]._passwd << std::endl;
    }
}

void HashTable::resize() {
    Pair* prev = array;// запоминаем старый массив
    int oldSize = mem_size;

    mem_size *= 2;  // увеличиваем размер в два раза  
    count = 0; // обнуляем количество элементов
    array = new Pair[mem_size]; // выделяем новую память

    for (int i = 0; i < oldSize; i++) {
        add(prev[i]._name, prev[i]._passwd);
    }
    // чистим за собой
    delete[] prev;
}