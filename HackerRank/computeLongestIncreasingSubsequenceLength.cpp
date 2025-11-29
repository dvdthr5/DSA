#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'computeLongestIncreasingSubsequenceLength' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY quality
 */

int computeLongestIncreasingSubsequenceLength(int n, vector<int> quality) {
   
    vector<int> result;
    if (quality.size() == 0){
        return 0;
    }
    result.push_back(quality[0]);
    for (size_t i = 1; i < quality.size(); i++){
        if (quality[i] > result.back()){
            result.push_back(quality[i]);
        }
        else {
            for (int j = 0; j < result.size(); j++){
                if (result[j] >= quality[i]){
                    result[j] = quality[i];
                    break;
                }
            }
        }
    }
    return result.size();
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string quality_count_temp;
    getline(cin, quality_count_temp);

    int quality_count = stoi(ltrim(rtrim(quality_count_temp)));

    vector<int> quality(quality_count);

    for (int i = 0; i < quality_count; i++) {
        string quality_item_temp;
        getline(cin, quality_item_temp);

        int quality_item = stoi(ltrim(rtrim(quality_item_temp)));

        quality[i] = quality_item;
    }

    int result = computeLongestIncreasingSubsequenceLength(n, quality);

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

