#include <bits/stdc++.h>
#include <stack>
using namespace std;

string isBalanced(string s) {
    if(s.size() % 2 == 1){
        return "NO";
    }
    
    std::stack <char> symboles;
    for (int i = 0; i < s.size(); ++i) { 

        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){ 
            symboles.push(s[i]); 
            continue; 
        } 
        if (symboles.empty()){ 
            return "NO"; 
        }

        char x = symboles.top(); 
        switch (s[i]) { 
            case ')': 
                if (x != '(') 
                    return "NO"; 
                break; 
    
            case '}': 
                if (x != '{') 
                    return "NO"; 
                break; 
    
            case ']': 
                if (x != '[') 
                    return "NO"; 
                break; 
        } 
        symboles.pop();
        
    }

    if(symboles.empty()){
        return "YES";
    }
    return "NO";
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}