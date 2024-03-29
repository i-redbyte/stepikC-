/**Добавьте в класс String реализацию конструктора копирования.
 * Инвариант класса остается тем же (в size хранится размер строки без завершающего 0 символа,
 * str указывает на C-style строку, т. е. с завершающим нулевым символом).*/

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {
    String(const char *str = "") : size(strlen(str)) {
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    String(size_t n, char c) {
        if (n < 0) return;
        this->str = new char[n + 1];
        for (size_t i = 0; i < n; ++i) {
            this->str[i] = c;
        }
        this->str[n] = '\0';
        this->size = n;
    }

    ~String() {
        delete[] str;
    }

    /* Реализуйте конструктор копирования */
    String(const String &other) : size(other.size), str(new char[size + 1]) {
        strcpy(this->str, other.str);
    }

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other) {
        if (this == &other) return *this;
        delete[] str;
        this->size = other.size;
        this->str = new char[size + 1];
        strcpy(this->str, other.str);
        return *this;
    }

    void append(String &other) {
        size_t new_size = size + other.size;
        char *new_ptr = new char[new_size + 1];
        strcpy(new_ptr, str);
        strcat(new_ptr + size, other.str);
        new_ptr[new_size] = '\0';
        delete[] str;
        str = new_ptr;
        size = strlen(str);
    }
    char & at(size_t idx)       {

        return str[idx];
    }
    char   at(size_t idx) const {return str[idx]; }
    size_t size;
    char *str;
};

int main() {
    String s1("123");
    String s2("234");
    s1 = s2;
    std::cout << s1.str << std::endl;
    String greet("Hello");
    char ch1 = greet.at(0);
    String const const_greet("Hello, Const!");
    char const &ch2 = const_greet.at(0);
    std::cout << ch1 << std::endl;
    std::cout << ch2 << std::endl;
    return 0;
}