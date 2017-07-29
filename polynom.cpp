#include <vector>
#include <iostream>

class Polynom {
private:
    std::vector<int> coefs;
public:
    Polynom(const std::vector<int>& input_coefs)
    : coefs(input_coefs)
    {}

    ~Polynom() {}
    Polynom(const Polynom& polynom)
    : coefs(polynom.coefs)
    {}

    friend std::ostream& operator<<(std::ostream& out, const Polynom& polynom){
        for (size_t i = 0; i < polynom.coefs.size();++i){
            out << polynom.coefs[i] << " ";
            out << polynom.coefs.operator[](i) << " ";
        }
        return out;
    }


};
int main(){
    Polynom polynom{{1, 2, 3}};
    std::cout << polynom;
    return 0;
}
