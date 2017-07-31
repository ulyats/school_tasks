#include <iostream>
#include <vector>

int main(){
    std::vector<int> massive{5, 5};
    int left(0);
    int right(massive.size());
    int middle;
    int x(5);

    while(right >= left + 2){
        middle = (left + right) / 2;
        if (x > massive[middle]) {
            left = middle;
        } else if (x == massive[middle]) {
           std::cout << middle;
            return 0;
        } else  {
            right = middle;
        }
    }
    if (right == left + 1 && x == massive[left]){
        std::cout << left;
    } else {
        std::cout << "-1";
    }
    return 0;
}
