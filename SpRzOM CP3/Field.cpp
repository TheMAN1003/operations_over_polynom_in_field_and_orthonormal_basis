#include "Field.h"

Field::Field() {
    //p(x) = x^419+x^21+x^14+x+1
    for(int i = 0; i < GeneratorLength; i++){
        generator.push_back(0);
    }
    for(int i = 0; i < MaxPolyLength; i++){
        polynom.push_back(0);
    }
    generator[0]=1;
    generator[1]=1;
    generator[14]=1;
    generator[21]=1;
    generator[419]=1;
}

Field::Field(std::vector<int> input) {
    //p(x) = x^419+x^21+x^14+x+1
    for(int i = 0; i < GeneratorLength; i++){
        generator.push_back(0);
    }
    generator[0]=1;
    generator[1]=1;
    generator[14]=1;
    generator[21]=1;
    generator[419]=1;
    for(int i = 0; i < input.size(); i++){
        polynom.push_back(input[i]);
    }
}

void clean(std::vector<int>& input) {
    while (input.size() > 1){
        if(input[input.size()-1] == 1) break;
        input.pop_back();
    }
}

void Field::show() {
    clean(polynom);
    for(int i = polynom.size()-1; i > -1; i--) std::cout << polynom[i];
    std::cout << std::endl;
}

void Field::makeEqualSize(std::vector<int> &b) {
    while(polynom.size() > b.size()) b.push_back(0);
    while(polynom.size() < b.size()) polynom.push_back(0);
}

void Field::add(std::vector<int> b) {
    clean(polynom);
    clean(b);
    bool carry = false;
    makeEqualSize(b);
    for(int i = 0 ; i < polynom.size(); i++){
        polynom[i]=polynom[i]^b[i];
    }
}

int Field::compare(std::vector<int> b) {
    clean(b);
    if(polynom.size()>b.size()) return 1;
    if(polynom.size()<b.size()) return -1;
    int i = b.size()-1;
    while (polynom[i] == b[i]) i--;
    if (i == -1) return 0;
    else {
        if (polynom[i] > b[i]) return 1;
        else return -1;
    }
}

std::vector<int> shiftDigitsToHigh(std::vector<int> input, int length) {
    reverse(input.begin(), input.end());
    for (int i = 0; i < length; i++) input.push_back(0);
    reverse(input.begin(), input.end());
    return input;
}

void Field::mod() {
    clean(polynom);
    if(compare(generator) == -1) return;
    while(polynom.size() >= generator.size()){
        add(shiftDigitsToHigh(generator, polynom.size()-generator.size()));
        clean(polynom);
    }
    return;
}

void Field::mul(std::vector<int> b){
    clean(polynom);
    clean(b);
    std::vector<int> polynomCopy = polynom;
    polynom.clear();
    for(int i = 0; i < b.size(); i++){
        if(b[i]==0) continue;
        add(shiftDigitsToHigh(polynomCopy, i));
    }
    mod();
}

void Field::square() {
    clean(polynom);
    std::vector<int> result;
    for(int i = 0; i<polynom.size(); i++){
        result.push_back(polynom[i]);
        result.push_back(0);
    }
    result.pop_back();
    polynom = result;
    mod();
}

void Field::trace() {
    clean(polynom);
    std::vector <int> temp, temp2, result;
    result = polynom;
    for(int i = 1; i < 419; i++){
        temp = result;
        square();
        temp2 = polynom;
        add(temp);
        clean(polynom);
        result = polynom;
        polynom = temp2;
    }
    polynom = result;
}

void Field::pow(std::vector<int> b) {
    clean(polynom);
    clean(b);
    std::vector<int> polynomCopy = polynom;
    polynom = {1};
    for(int i = b.size()-1; i>=0; i--){
        if(b[i] == 1) mul(polynomCopy);
        if(i != 0) square();
    }
    mod();
}

void Field::reverse() {
    std::vector<int> power = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for(int i = power.size()-1; i>=0; i--){
        std::cout << power[i];
    }
    std::cout << std::endl;
    pow(power);
}

//void Field::pow(int n) {
//    clean(polynom);
//    std::vector<int> polynomCopy = polynom;
//    int odd = n%2;
//    int k = int(n/2);
//    for(int i = 0; i<k; i++) square();
//    if(odd == 1) mul(polynomCopy);
//}



