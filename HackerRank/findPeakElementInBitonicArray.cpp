#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findPeakIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY counts as parameter.
 */

int findPeakIndex(vector<int> counts) {
    int low = 0;
    int high = counts.size() -1;
    
    while (low < high){
        int mid = low+ (high - low)/2; 
        if (counts[mid] < counts[mid+1]){
            low = mid+1;
        }
        else if (counts[mid] > counts[mid+1]){
            high = mid;
        }
    }
    return low;

}

int main()
{
    string counts_count_temp;
    getline(cin, counts_count_temp);

    int counts_count = stoi(ltrim(rtrim(counts_count_temp)));

    vector<int> counts(counts_count);

    for (int i = 0; i < counts_count; i++) {
        string counts_item_temp;
        getline(cin, counts_item_temp);

        int counts_item = stoi(ltrim(rtrim(counts_item_temp)));

        counts[i] = counts_item;
    }

    int result = findPeakIndex(counts);

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

