#include "NB.h"

ONB::ONB() {
    for (int i = 0; i < MaxLength; i++){
        element.push_back(0);
    }
}

ONB::ONB(std::deque<int> input) {
    for(int i = 0; i < MaxLength; i++){
        element.push_back(input.at(i));
    }
}

void show(std::deque<int> input) {
    for(int i=0; i<MaxLength; i++) std::cout<<input.at(i);
    std::cout << '\n';
}

std::deque<int> ONB::rightShift(std::deque<int> input, int steps) {
    std::deque<int> result(MaxLength, 0);
    for(int i = 0; i<input.size(); i++) result.at((i+steps)%MaxLength)=input[i];
    return result;
}

std::deque<int> ONB::leftShift(std::deque<int> input, int steps) {
    std::deque<int> result(MaxLength, 0);
    for(int i = 0; i<input.size(); i++) result.at((MaxLength+i-steps)%MaxLength)=input[i];
    return result;
}

std::deque<int> ONB::add(std::deque<int> a, std::deque<int> b) {
    std::deque<int> result(MaxLength, 0);
    for(int i = 0; i<MaxLength; i++) {
        result.at(i)=a.at(i)^b.at(i);
    }
    return result;
}

std::deque<int> ONB::square(std::deque<int> input) {
    return rightShift(input, 1);
}

int ONB::trace(std::deque<int> input) {
    int result = 0;
    for(int i = 0; i<MaxLength; i++) result = result^input.at(i);
    return result;
}

int ONB::mulMtr(std::deque<int> a, std::deque<int> c) {
    std::deque<int> result1(MaxLength, 0);
    int result = 0;
    for(int i = 0; i<MaxLength; i++){
        int cell = 0;
        for(int j = 0; j<MaxLength; j++){
            int q = a.at(j);
            int w = matrixprecalculated[i][j];
            cell = cell^(q&w);
        }
        result1.at(i) = cell;
    }
    for (int i = 0; i < MaxLength; ++i) {
        result ^= result1.at(i)&c.at(i);
    }
    return result;
}

std::deque<int> ONB::mul(std::deque<int> a, std::deque<int> b) {
    std::deque<int> result(MaxLength, 0);
    for(int i = 0; i<MaxLength; i++){
        result.at(i) = mulMtr(leftShift(a,i), leftShift(b,i));
    }
    return result;
}

std::deque<int> ONB::pow(std::deque<int> input, std::deque<int> power) {
    std::deque<int> result(MaxLength, 1);
    for(int i = power.size()-1; i>=0; i--){
        if(power[i] == 1) result = mul(result, input);
        if(i != 0) result = square(result);
    }
    return result;
}

std::deque<int> ONB::reverse(std::deque<int> input) {
    std::deque<int> result(input);
    std::deque<int> m = {0, 1, 0, 0, 0, 1, 0, 1, 1};
    int t = 8;
    int k = 1;
    for(int i = t-1; i>=0; i--){
        result=mul(rightShift(result, k), result);
        k*=2;
        if(m[i]==1) {
            result=mul(square(result), input);
            k++;
        }
    }
    result = square(result);
    return result;
}

std::deque<int> ONB::reverse2(std::deque<int> input) {
    std::deque<int> result(input);
    std::deque<int> power = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    result = pow(input, power);
    return result;
}