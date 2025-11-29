#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findNextGreaterElementsWithDistance' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY readings as parameter.
 */

vector<vector<int>> findNextGreaterElementsWithDistance(vector<int> readings) {
    size_t n = readings.size();
    vector<vector<int>> totalResult(n, vector<int>(2, -1));
    stack<int> theStack; 
    
    for (int i = 0; i < n ; i ++){
        while (!theStack.empty() && readings[i] > readings[theStack.top()]){
            int index = theStack.top();
            theStack.pop();
            totalResult[index][0] = readings[i];
            totalResult[index][1] = i - index;
        }
        theStack.push(i);           
    }
    return totalResult;
}

int main()
{
    string readings_count_temp;
    getline(cin, readings_count_temp);

    int readings_count = stoi(ltrim(rtrim(readings_count_temp)));

    vector<int> readings(readings_count);

    for (int i = 0; i < readings_count; i++) {
        string readings_item_temp;
        getline(cin, readings_item_temp);

        int readings_item = stoi(ltrim(rtrim(readings_item_temp)));

        readings[i] = readings_item;
    }

    vector<vector<int>> result = findNextGreaterElementsWithDistance(readings);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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

