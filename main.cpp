#include <iostream>
#include <algorithm>
typedef long long int huge;

huge g(huge x, huge num);
huge gog(huge y, huge num);
huge pollardsRho(huge num, int* counter);
huge gcd(huge a, huge b);

int main() {
    int num = 0;
    int* counter = &num;
    std::cout<<pollardsRho(88896547541234553, counter)<<"\n";
    std::cout<<"Iterations of While Loop: "<<*counter<<"\n";
}

huge g(huge x, huge num){
    return (x*x+1)%num;
}
huge gog(huge y, huge num){
    y = (y*y+1)%num;
    return (y*y-1)%num;
}
huge pollardsRho(huge num, int* counter){
    huge x = 2;
    huge y = 2;
    huge d = 1;

    while(d==1){
        x = g(x, num);
        y = gog(y, num);
        d = gcd(abs(x - y), num);
        (*counter)++;
    }
    if(d == num)
        return 0;
    else
        return d;
}

huge gcd(huge a, huge b){
    if (!a)
        return b;
    return gcd(b % a, a);
}
