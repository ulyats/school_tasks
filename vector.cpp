#include <iostream>
#include <vector>

int main(){
    std::vector<int> sosiska{1, 2, 3};
    std::cout << sosiska[0];
    sosiska.push_back(10);
    std::cout << sosiska[3];
    return 0;
}
