#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minTransformationCost' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY A
 *  2. STRING_ARRAY B
 *  3. INTEGER insertCost
 *  4. INTEGER deleteCost
 */

int editDistance(string A, string B){
    int n = A.length();
    int m = B.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <=n; i++){
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++){
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            
            int subCost = 0; int delCost = 0; int addCost = 0;
            if (A[i-1] == B[j-1]){
                subCost = dp[i-1][j-1];
            } else{
                subCost = dp[i-1][j-1] + 1;
            }
            delCost = dp[i-1][j] + 1;
            addCost = dp[i][j-1] + 1;
            
            int mini = subCost;
            if (delCost < mini){
                mini = delCost;
            }
            if (addCost < mini){
                mini = addCost;
            }
            dp[i][j] = mini;
            
        }
    }
    return dp[n][m];
}

long minTransformationCost(vector<string> A, vector<string> B, int insertCost, int deleteCost) {
    int n = A.size();
    int m = B.size();
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
    
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + deleteCost;
    }
    for (int i = 1; i <= m; i++){
        dp[0][i] = dp[0][i-1] + insertCost;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j<= m; j++){
            
            long subCost = 0; long addCost = 0; long delCost = 0;
            subCost = dp[i-1][j-1] + editDistance(A[i-1], B[j-1]);
            delCost = dp[i-1][j] + deleteCost;
            addCost = dp[i][j-1] + insertCost;
            
            long mini = subCost;
            if (delCost < mini){
                mini = delCost;
            }
            if (addCost < mini){
                mini = addCost;
            }
            
            dp[i][j] = mini;
        }
    }
    return dp[n][m];
    
}

int main()
{
    string A_count_temp;
    getline(cin, A_count_temp);

    int A_count = stoi(ltrim(rtrim(A_count_temp)));

    vector<string> A(A_count);

    for (int i = 0; i < A_count; i++) {
        string A_item;
        getline(cin, A_item);

        A[i] = A_item;
    }

    string B_count_temp;
    getline(cin, B_count_temp);

    int B_count = stoi(ltrim(rtrim(B_count_temp)));

    vector<string> B(B_count);

    for (int i = 0; i < B_count; i++) {
        string B_item;
        getline(cin, B_item);

        B[i] = B_item;
    }

    string insertCost_temp;
    getline(cin, insertCost_temp);

    int insertCost = stoi(ltrim(rtrim(insertCost_temp)));

    string deleteCost_temp;
    getline(cin, deleteCost_temp);

    int deleteCost = stoi(ltrim(rtrim(deleteCost_temp)));

    long result = minTransformationCost(A, B, insertCost, deleteCost);

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

