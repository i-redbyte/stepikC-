#include <iostream>

/**Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, которые дают полный доступ
 * к этим полям (см. шаблон кода), несмотря на то, что они закрытые.Внимание:
 * предполагаемое решение этого задания существенно опирается на Undefined Behaviour и является исключительно учебным,
 * но полезно для лучшего понимания того, как работают модификаторы доступа.
 * Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), но мы настоятельно не рекомендуем
 * использовать подобные трюки в боевом коде.*/
struct Cls {
    Cls(char c, double d, int i) {
        this->c = c;
        this->d = d;
        this->i = i;
    };

private:
    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *(char*)(&cls);
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *(double*)((char*)(&cls) + 8);
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    return *(int*)((char*)(&cls) + 16);
}
//version 2
char &get_c2(Cls &cls) {
    return (char &) cls;
}

double &get_d2(Cls &cls) {
    return *((double *) &cls + 1);
}

int &get_i2(Cls &cls) {
    return *((int *) ((double *) &cls + 1) + 2);
}

int main() {
    Cls cls('P', 3.14, 1917);
    std::cout << get_c(cls) << std::endl;
    std::cout << get_d(cls) << std::endl;
    std::cout << get_i(cls) << std::endl;
    Cls c('C', 661.881, 888666);
    std::cout << get_c2(c) << std::endl;
    std::cout << get_d2(c) << std::endl;
    std::cout << get_i2(c) << std::endl;

    return 0;
}