#include <vector>

std::vector<int> Merge(const std::vector<int>& first_vector, const std::vector<int>& second_vector){
    std::vector<int> result_vector;
    unsigned int first_index(0);
    unsigned int second_index(0);
    while (first_index < first_vector.size() && second_index < second_vector.size()){
        if (first_vector[first_index] < second_vector[second_index]){
            result_vector.push_back(first_vector[first_index++]);
        } else {
            result_vector.push_back(second_vector[second_index++]);
        }
    }

    while (second_index < second_vector.size()) {
        result_vector.push_back(second_vector[second_index++]);
    }
    while (first_index < first_vector.size()) {
        result_vector.push_back(first_vector[first_index++]);
    }
    return result_vector;
}

int main(){
    return 0;
}
