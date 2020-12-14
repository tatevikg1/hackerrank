#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
vector<int> sum_reverse(vector<int> h);


int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    h1 = sum_reverse(h1);
    h2 = sum_reverse(h2);
    h3 = sum_reverse(h3);
    
    while(true){
        if(h1.back() > h2.back() || h1.back() > h3.back()){
            h1.pop_back();
        }
        if(h2.back() > h3.back() || h2.back() > h1.back()){
            h2.pop_back();
        }
        if(h3.back() > h1.back() || h3.back() > h2.back()){
            h3.pop_back();
        }
        if((h1.back() == h2.back()) && (h3.back() == h2.back()))
            break;
    }
    return h1.back();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

vector<int> sum_reverse(vector<int> h){
    vector<int> rev_sum;
    int size = h.size();
    rev_sum.push_back(h[size - 1]);
    
    for(int i = 2; i <= size; i++){
        int val = h[size - i] + rev_sum.back();
        rev_sum.push_back(val);
    }
    return rev_sum;
}
