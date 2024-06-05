#include <iostream>
#include <vector>
using std::vector;
using namespace std;

void fibonacci_pisano(long long n, long long m) {
    if (n <= 1){
        cout << "余数为" << n << endl;
    }
    long long previous = 0;
    long long current = 1;

    vector<long long> mod;
    mod.push_back(0);
    mod.push_back(1);

    for (long long i = 2; i <= n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        mod.push_back(current);
        if(mod.at(mod.size()-2)==0 && mod.at(mod.size()-1)==1){
            mod.pop_back();
            mod.pop_back();
            break;
        }
        }
    cout << "余数为:";
    for(long long i=0; i < mod.size(); i++){
        cout << mod.at(i) << ", ";
    }
    cout << endl;
    cout << "Pisano周期的长度为" << mod.size() << endl;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    fibonacci_pisano(n, m);
    return 0;
}
