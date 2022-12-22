#ifndef NEDOZHDII_FI_03_LABS_SPRZOM_FIELD_H
#define NEDOZHDII_FI_03_LABS_SPRZOM_FIELD_H


#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std::chrono;

inline constexpr int MaxPolyLength = 420;
inline constexpr int GeneratorLength = 420;
inline constexpr int MaxMultLength = 840;
inline constexpr int MaxPowLength = 841;

class Field {
public:
    //p(x) = x^419+x^21+x^14+x+1
    std::vector<int> generator;
    std::vector<int> polynom;

    Field();
    explicit Field(std::vector<int>);
    void show();
    void makeEqualSize(std::vector<int>&);
    void add(std::vector<int>);
    int compare(std::vector<int>);
    void mod();
    void mul(std::vector<int>);
    void square();
    void trace();
    void pow(std::vector<int>);
    void reverse();
};

void clean(std::vector<int>&);
std::vector<int> shiftDigitsToHigh(std::vector<int>, int);

#endif //NEDOZHDII_FI_03_LABS_SPRZOM_FIELD_H
