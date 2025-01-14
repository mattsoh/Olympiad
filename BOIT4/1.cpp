#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    ll no;
    cin >> no;
    string num = to_string(no);
    int n = num.size();
    string firstHalf = num.substr(0, (n + 1)/2);
    string palindrome = firstHalf + string(firstHalf.rbegin() + (n % 2), firstHalf.rend());

    if (palindrome > num) {
        cout<< palindrome;
        return 0;
    }

    for (int i = (firstHalf.size() - 1); i >= 0; --i) {
        if (firstHalf[i] < '9') {
            firstHalf[i]++;
            break;
        }
        firstHalf[i] = '0';
    }

    if (firstHalf[0] == '0') {
        firstHalf = '1' + firstHalf;
    }

    cout<< firstHalf + string(firstHalf.rbegin() + (n % 2), firstHalf.rend())<<endl;
}