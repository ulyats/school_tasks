#include <vector>
#include <fstream>
#include <string>

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
std::vector<int> merge_sort(const std::vector<int>& massive){
    std::vector<int> m1;
    std::vector<int> m2;
    unsigned int left(0);
    unsigned int right(massive.size());
    unsigned int mid(massive.size() / 2);
    if(massive.size() == 0 || massive.size() == 1){
        return massive;
    }
    for(unsigned int i = left; i < mid; i++){
        m1.push_back(massive[i]);
    }
    for(unsigned int i = mid; i < right; i++){
        m2.push_back(massive[i]);
    }
    std::vector<int> sorted_m1(merge_sort(m1));
    std::vector<int> sorted_m2(merge_sort(m2));
    return Merge(sorted_m1, sorted_m2);
}

std::vector<int> readvectorfromfile(const std::string& file_name){
    std::ifstream fh(file_name);
    unsigned int massiv_size;
    fh >> massiv_size;
    std::vector<int> massiv(massiv_size, 0);
    for(unsigned int i = 0; i < massiv_size; i++){
        fh >> massiv[i];
    }
    return massiv;
}
void writevectortofile(const std::vector<int>& massiv, const std::string& file_name){
    std::ofstream fh(file_name);
    for(unsigned int i = 0; i < massiv.size(); i++){
        fh << massiv[i] << " ";
    }
}
int main(){
    std::vector<int> massiv(readvectorfromfile("mergesort.in"));
    std::vector<int> sorted_massiv(merge_sort(massiv));
    writevectortofile(sorted_massiv, "mergesort.out");
    return 0;
}

