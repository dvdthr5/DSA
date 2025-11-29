#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSmallestMissingPositive' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY orderNumbers as parameter.
 */
 
int findSmallestMissingPositive(vector<int> orderNumbers) {
    int currentSmallestMissing = 1;
    std::unordered_map<int, int> seen; 
    for (size_t i = 0; i < orderNumbers.size(); i ++ ){
        seen[orderNumbers[i]] = i;
    }
    for (size_t i=1; i <= orderNumbers.size(); i++){
        if (seen.find(i) == seen.end()){
            return currentSmallestMissing;
        } else{
            currentSmallestMissing++;
        }
    }
    return currentSmallestMissing;
        
        
}

int main()
{
    string orderNumbers_count_temp;
    getline(cin, orderNumbers_count_temp);

    int orderNumbers_count = stoi(ltrim(rtrim(orderNumbers_count_temp)));

    vector<int> orderNumbers(orderNumbers_count);

    for (int i = 0; i < orderNumbers_count; i++) {
        string orderNumbers_item_temp;
        getline(cin, orderNumbers_item_temp);

        int orderNumbers_item = stoi(ltrim(rtrim(orderNumbers_item_temp)));

        orderNumbers[i] = orderNumbers_item;
    }

    int result = findSmallestMissingPositive(orderNumbers);

    cout << result << "\n";

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

