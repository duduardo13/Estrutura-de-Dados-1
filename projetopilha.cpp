#include <iostream>
#include <list>
#include <vector>

template<typename T>
class Stack {
public:
    void push(const T& value) {
        container.push_back(value);
    }

    void pop() {
        if (!container.empty()) {
            container.pop_back();
        }
    }

    T top() const {
        if (!container.empty()) {
            return container.back();
        }
        return T();
    }

    bool empty() const {
        return container.empty();
    }

private:
    std::vector<T> container;
};

int main() {
    Stack<int> evenNumbers;
    Stack<int> oddNumbers;
    int lastNumber = -1;

    for (int i = 0; i < 30; ++i) {
        int num;
        do {
            std::cout << "Digite um numero maior do que " << lastNumber << ": ";
            std::cin >> num;
        } while (num <= lastNumber);

        if (num % 2 == 0) {
            evenNumbers.push(num);
        } else {
            oddNumbers.push(num);
        }

        lastNumber = num;
    }

    std::cout << "Numeros pares em ordem decrescente: ";
    while (!evenNumbers.empty()) {
        std::cout << evenNumbers.top() << " ";
        evenNumbers.pop();
    }

    std::cout << "\nNumeros impares em ordem decrescente: ";
    while (!oddNumbers.empty()) {
        std::cout << oddNumbers.top() << " ";
        oddNumbers.pop();
    }

    return 0;
}
