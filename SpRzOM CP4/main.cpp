#include "NB.h"

int main(){
    srand((unsigned)time(nullptr));
    std::deque<int> deque;
    std::deque<int> deque2;
    std::deque<int> deque3;
    for(int i=0; i<MaxLength; i++) {
        deque.push_back(rand()%2);
        deque2.push_back(rand()%2);
        deque3.push_back(rand()%2);
    }

    std::deque<int> deque4(MaxLength, 1);
    ONB a(deque);
    ONB b(deque2);
    ONB c(deque3);
    ONB d(deque4);

    show(a.element);
    show(b.element);
    show(c.element);
    std::cout << "\n";

    std::cout << "distibution\n" ;
    show(a.mul(a.add(a.element, b.element), c.element));
    show(a.add(a.mul(b.element, c.element), a.mul(c.element, a.element)));
    std::cout << "\n";

    std::cout << "a*a^-1=1\n" ;
    show(a.mul(a.element, a.reverse(a.element)));
    show(d.element);
    std::cout << "\n";

    std::cout << "a^2=a*a\n" ;
    show(a.square(a.element));
    show(a.mul(a.element, a.element));
    std::cout << "\n";

    std::cout << "a^1=a\n" ;
    std::deque<int> deque5(1, 1);
    show(a.pow(a.element, deque5));
    show(a.element);
    std::cout << "\n";

    std::cout << "a.pow(2)=a.square()\n" ;
    std::deque<int> deque6 = {0, 1};
    show(a.pow(a.element, deque6));
    show(a.square(a.element));
    std::cout << "\n";

    auto startadd = high_resolution_clock::now();
    a.add(a.element, b.element);
    auto stopadd = high_resolution_clock::now();
    auto durationadd = duration_cast<microseconds>(stopadd - startadd);
    std::cout << "time: " << durationadd.count() << " microseconds" << std::endl << std::endl;

    auto startsquare = high_resolution_clock::now();
    a.square(a.element);
    auto stopsquare = high_resolution_clock::now();
    auto durationsquare = duration_cast<microseconds>(stopsquare - startsquare);
    std::cout << "time: " << durationsquare.count() << " microseconds" << std::endl << std::endl;

    auto starttrace = high_resolution_clock::now();
    a.trace(a.element);
    auto stoptrace = high_resolution_clock::now();
    auto durationtrace = duration_cast<microseconds>(stoptrace - starttrace);
    std::cout << "time: " << durationtrace.count() << " microseconds" << std::endl << std::endl;

    auto startmul = high_resolution_clock::now();
    a.mul(a.element, c.element);
    auto stopmul = high_resolution_clock::now();
    auto durationmul = duration_cast<microseconds>(stopmul - startmul);
    std::cout << "time: " << durationmul.count() << " microseconds" << std::endl << std::endl;

    std::deque<int> power = {1, 1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1, 1, 1};
    auto startpow = high_resolution_clock::now();
    a.pow(a.element, power);
    auto stoppow = high_resolution_clock::now();
    auto durationpow = duration_cast<microseconds>(stoppow - startpow);
    std::cout << "time: " << durationpow.count() << " microseconds" << std::endl << std::endl;

    auto startreverse = high_resolution_clock::now();
    a.reverse(a.element);
    auto stopreverse = high_resolution_clock::now();
    auto durationreverse = duration_cast<microseconds>(stopreverse - startreverse);
    std::cout << "time: " << durationreverse.count() << " microseconds" << std::endl << std::endl;


    return 0;
}
