#pragma once

#include <string.h>

#define NAMELENGTH 10  // ���������� ����� �����
#define PASSLENGTH 10  // ���������� ����� �����

typedef char Name[NAMELENGTH]; // ��� ���
typedef char Password[PASSLENGTH]; // ��� ���

class HashTable { // ��� �������
public:

    HashTable();
    ~HashTable();
    void add(Name name, Password passwd);
    char* find(Name name);
    void del(Name name);
    void show();

private:

    enum enPairStatus {
        free,
        engaged,
        deleted
    };

    struct Pair { // ���� ����-��������

        Pair() :
            _name(""),
            _passwd(""),
            status(enPairStatus::free)
        {}
        Pair(Name name, Password passwd) :
            status(enPairStatus::engaged) {
            strcpy_s(_name, name);
            strcpy_s(_passwd, passwd);
        }
        Pair& operator = (const Pair& other) {
            strcpy_s(_passwd, other._passwd);
            strcpy_s(_name, other._name);
            status = other.status;

            return *this;
        }

        bool operator == (const Pair& other) {
            return  status == other.status &&
                (status != enPairStatus::engaged || (_passwd == other._passwd && !strcmp(_name, other._name)));
        }

        Name _name;
        Password _passwd;

        enPairStatus status;
    };

    void resize();
    int hash_func(Name name, int offset);

    Pair* array;
    int mem_size;
    int count;
};