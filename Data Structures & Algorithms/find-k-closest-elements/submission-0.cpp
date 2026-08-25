class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Intuition
        //We will maintain a max heap because we want to retain the elements which are closer to x
        //One way is the subtract the all the element of the array
        vector<int> tempArr(arr.size());
        //Subtract all the elements from the given number
        for (int i = 0; i < arr.size(); ++i) {
            tempArr[i] = abs(arr[i] - x);
        }


        priority_queue<pair<int,int>> maxHeap;
        vector<int> result;

        for (int i = 0; i < arr.size(); ++i) {
            maxHeap.push(make_pair(tempArr[i], arr[i]));

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};