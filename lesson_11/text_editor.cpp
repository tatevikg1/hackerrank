#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct oper
{
    bool write;
    string text;
};


int main() {
    int Q, k;
    string S, text;
    stack<oper> operations;
    cin >> Q;

    for(; Q > 0; Q--){
        int new_operation;
        cin >> new_operation;

        switch (new_operation){
        case 1:
            cin >> text;
            operations.push({true, text});
            k = S.size();
            S.append(text);
            break;
        case 2:
            cin >> k;
            text = S.substr(S.size()-k, S.size());
            operations.push({false, text});
            S = S.substr(0, S.size()-k);
            break;
        case 3:
            cin >> k;
            cout << S[k-1] << "\n";
            break;
        case 4:
            oper o = operations.top();
            if(o.write){
                k = (o.text).size();
                S = S.substr(0, S.size()-k);
            }else{
                S.append(o.text);
            }
            operations.pop();
        }
    }
    return 0;
}
