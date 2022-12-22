#include "Field.h"

//std::vector<int> createVector(){
//    std::vector<int> result;
//    int power;
//    std::cin >> power;
//    for(int i = 0; i <= power; i++){
//        result.push_back(0);
//    }
//    result[power] = 1;
//    while(true){
//        std::cin >> power;
//        if(power > MaxPolyLength - 1 || power < 0 || power > result.size()) return result;
//        result[power]=1;
//    }
//}

int main(){
//    std::cout << "Enter as many numbers as you want, enter negative or 420 to stop, start with your max power\n";
//    std::vector<int> vector = createVector();


//    std::vector<int> vector = {1, 1, 1, 0, 1};
//    std::vector<int> vector2 = {0, 1, 1};

//    std::cout << "next one\n";
//    std::vector<int> vector2 = createVector();

//    a.polynom = shiftDigitsToHigh(a.polynom, 400);
//    b.polynom = shiftDigitsToHigh(b.polynom, 400);
//    a.show();
//    b.show();
//    a.add(b.polynom);
//    a.show();
//    shiftDigitsToHigh(a.polynom, 2);
//    a.show();
//    std::cout << b.compare(a.polynom) << std::endl;
//    shiftDigitsToHigh(b.polynom, 420);
//    b.mod();
//    a.mul(b.polynom);
//    a.square();
//    a.trace();
//    a.pow(b.polynom);

    srand((unsigned)time(nullptr));
    int len1, len2, len3;
    len1 = ((rand()%420)+15)%420;
    len2 = ((rand()%420)+3)%420;
    len3 = (rand()%420)+1;
    std::vector<int> vector;
    std::vector<int> vector2;
    std::vector<int> vector3;
    for(int i=0; i<len1; i++) {
        vector.push_back(rand()%2);
        vector2.push_back(rand()%2);
        vector3.push_back(rand()%2);
    }

    Field a(vector);
    Field b(vector2);
    Field c(vector3);
    a.show();
    b.show();
    c.show();

    std::cout << '\n';

    std::vector<int> aCopy = a.polynom;
    std::vector<int> bCopy = b.polynom;
    std::vector<int> cCopy = c.polynom;
    std::vector<int> result1;
    std::vector<int> result2;

    auto startdist = high_resolution_clock::now();
    a.add(b.polynom);
    a.mul(c.polynom);
    a.show();

    result1 = a.polynom;

    a.polynom = aCopy;
    b.polynom = bCopy;
    c.polynom = cCopy;
    a.mul(c.polynom);
    b.mul(c.polynom);
    a.add(b.polynom);
    auto stopdist = high_resolution_clock::now();
    a.show();

    result2 = a.polynom;

    if(std::equal(result1.begin(), result1.end(), result2.begin())) std::cout << "equal" << std::endl;
    auto durationdist = duration_cast<microseconds>(stopdist - startdist);
    std::cout << "time: " << durationdist.count() << " microseconds" << std::endl << std::endl;

    a.polynom = aCopy;
    b.polynom = bCopy;
    c.polynom = cCopy;

    std::vector<int> power;
    for(int i = 0; i < 419; i++) power.push_back(1);
    auto startpow = high_resolution_clock::now();
    a.pow(power);
    auto stoppow = high_resolution_clock::now();
    std::cout << std::endl;
    a.show();
    std::vector<int> result3 = {1};
    for(int i=0; i < result3.size(); i++) std::cout << result3[i];
    std::cout << std::endl;
    auto durationpow = duration_cast<microseconds>(stoppow - startpow);
    if(std::equal(a.polynom.begin(), a.polynom.end(), result3.begin())) std::cout << "equal" << std::endl;
    std::cout << "time: " << durationpow.count() << " microseconds" << std::endl << std::endl;

    a.polynom = aCopy;
    b.polynom = bCopy;
    c.polynom = cCopy;

    b.polynom=a.polynom;
    auto startrev = high_resolution_clock::now();
    a.reverse();
    a.show();

    b.mul(a.polynom);
    auto stoprev = high_resolution_clock::now();
    b.show();
    auto durationrev = duration_cast<microseconds>(stoprev - startrev);
    std::cout << "time: " << durationrev.count() << " microseconds" << std::endl << std::endl;

    a.polynom = aCopy;
    b.polynom = bCopy;
    c.polynom = cCopy;

    auto starttrace = high_resolution_clock::now();
    a.trace();
    auto stoptrace = high_resolution_clock::now();
    a.show();
    auto durationtrace = duration_cast<microseconds>(stoptrace - starttrace);
    std::cout << "time: " << durationrev.count() << " microseconds" << std::endl << std::endl;

    return 0;
}