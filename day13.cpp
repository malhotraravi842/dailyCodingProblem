// Problem Link: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/

#include<bits/stdc++.h>
using namespace std;
#define MAX_CHARS 26


// Brute Force Solution

// Iterative
// Time Complexity : O(N^3)
void validString(string s, int x) {
    int n = s.size();
    int maxm = -1;
    string ans;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            string substr;
            set<char> setStr;
            for(int k=i;k<=j;k++){
                substr += s[k];
                setStr.insert(s[k]);
            }
            if(setStr.size() == x && (j-i) > maxm) {
                maxm = j - i;
                ans = substr;
            }
        }
    }

    cout<<ans<<endl;
}

// Recursive
// Time Complexity : O(N^2)
void allSubArrays(string s, int curr_start, int curr_end,string &ans, int k, int &maxm) {
    if(curr_end == s.size()){
        return;
    }else if(curr_start > curr_end) {
        allSubArrays(s, 0, curr_end+1, ans, k, maxm);
    }else {
        string substr;
        set<char> setStr;
        for(int i=curr_start;i<=curr_end;i++) {
            substr += s[i];
            setStr.insert(s[i]);
        }
        int size = substr.size();
        if(setStr.size() == k && size > maxm) {
            maxm = size;
            ans = substr;
        }
        allSubArrays(s, curr_start+1, curr_end, ans, k, maxm);
    }

    return;
}

void validString2(string s, int k) {
    int maxm = -1;
    string ans = "";
    allSubArrays(s, 0, 0, ans, k, maxm);
    cout<<ans<<endl;
}

// End of Brute Force Solution

// Optimized Solution

bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;
 
    // Return true if k is greater than or equal to val
    return (k >= val);
}
 
// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int u = 0; // number of unique characters
    int n = s.length();
 
    // Associative array to store the count of characters
    int count[MAX_CHARS];
    memset(count, 0, sizeof(count));
 
    // Traverse the string, Fills the associative array
    // count[] and count number of unique characters
    for (int i=0; i<n; i++)
    {
        if (count[s[i]-'a']==0)
            u++;
        count[s[i]-'a']++;
    }
 
    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        cout << "Not enough unique characters";
        return;
    }
 
    // Otherwise take a window with first element in it.
    // start and end variables.
    int curr_start = 0, curr_end = 0;
 
    // Also initialize values for result longest window
    int max_window_size = 1, max_window_start = 0;
 
    // Initialize associative array count[] with zero
    memset(count, 0, sizeof(count));
 
    count[s[0]-'a']++;  // put the first character
 
    // Start from the second character and add
    // characters in window according to above
    // explanation
    for (int i=1; i<n; i++)
    {
        // Add the character 's[i]' to current window
        count[s[i]-'a']++;
        curr_end++;
 
        // If there are more than k unique characters in
        // current window, remove from left side
        while (!isValid(count, k))
        {
            count[s[curr_start]-'a']--;
            curr_start++;
        }
 
        // Update the max window size if required
        if (curr_end-curr_start+1 > max_window_size)
        {
            max_window_size = curr_end-curr_start+1;
            max_window_start = curr_start;
        }
    }
 
    cout << "Max sustring is : "
         << s.substr(max_window_start, max_window_size)
         << " with length " << max_window_size << endl;
}

int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;

    // validString(s, k);
    // validString2(s, k);
    
    kUniques(s, k);

    return 0;
}