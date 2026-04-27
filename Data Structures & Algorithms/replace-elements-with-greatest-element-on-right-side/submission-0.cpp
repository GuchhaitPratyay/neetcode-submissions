class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        for (int firstIterator = 0; firstIterator < arr.size(); ++firstIterator) {
            if (firstIterator == (arr.size()-1)) {
                arr[firstIterator] = -1;
            } else {
                int max = INT_MIN;
                for (int secondIterator = firstIterator+1; secondIterator < arr.size(); ++secondIterator) {
                    if (arr[secondIterator] > max) max = arr[secondIterator];
                }
                arr[firstIterator] = max;
            }
        }

        return arr;
    }
};