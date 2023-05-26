/**
 * Author ：Jaryn
 * Time ：2022/4/19 9:45 上午
 * Desc ：
 */#ifndef SORT_JARYNUTILS_H
#define SORT_JARYNUTILS_H

#endif //SORT_JARYNUTILS_H

void printArrayWithGuard(int *num, int len) {
    for (int i = 1; i < len; ++i) {
        std::cout << num[i];
        std::cout << " ";
    }
    std::cout << "\n";
}

void printArray(int *num, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << num[i];
        std::cout << " ";
    }
    std::cout << "\n";
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void printString(char *c) {
    std::cout << c;
}