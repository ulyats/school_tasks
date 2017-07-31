#include <iostream>
#include <vector>

int main(){
    std::vector<int> massive{5, 5};
    int left(0);
    int right(massive.size() - 1);
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
    if(right == left){
        if (x == massive[left]) {
            std::cout << left;
        } else {
            std::cout << "-1";
        }
    } else if (right == left + 1){
        if (x == massive[left]) {
            std::cout << left;
        } else if (x == massive[right]) {
            std::cout << right;
        } else {
            std::cout << "-1";
        }
    } else {
        std::cout << "-1";
    }
    return 0;
}
