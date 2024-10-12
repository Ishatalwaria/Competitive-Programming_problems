class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;  // Set to store all prefixes from arr1

        // Step 1: Build all possible prefixes from arr1
        for (int val : arr1) {
            while (!prefixes.count(val) && val > 0) {
                prefixes.insert(val);  // Insert current value as a prefix
                val /= 10;  // Generate the next shorter prefix by removing the last digit
            }
        }

        int longestPrefix = 0;

        // Step 2: Check each number in arr2 for the longest matching prefix
        for (int val : arr2) {
            while (!prefixes.count(val) && val > 0) {
                val /= 10;  // Reduce val by removing the last digit if not found in the prefix set
            }
            if (val > 0) {
                // Calculate the length of the matched prefix using log10 to determine the number of digits
                longestPrefix = max(longestPrefix, static_cast<int>(log10(val) + 1));
            }
        }

        return longestPrefix;
    }
};
