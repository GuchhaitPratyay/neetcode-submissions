class Solution {
public:
    vector<string> result;

    void helper(string& str, vector<string>& temp, unordered_set<string>& dictionarySet, int strIndex) {
    	//base case
    	if (strIndex == str.size()) {
    		string tempStr;
    		for (int i = 0; i < temp.size(); ++i) {
    			tempStr += temp[i];
    			if (i < temp.size()-1) {
    				tempStr += " ";
    			}
    		}
    		result.push_back(tempStr);
    		return;
    	}
    
    	//self work + recursive intuition
    	string word;
    	for (int i = strIndex; i < str.size(); ++i) {
    		//contact the character in the string
    		word += str[i];
    
    		if (dictionarySet.find(word) != dictionarySet.end()) {
    			//the word is present in the ditionary, now store it in the temp
    			temp.push_back(word);
    
    			helper(str, temp, dictionarySet, i + 1);
    
    			temp.pop_back();
    		}
    	}
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        /*Intuition:
		I have to recursively traverse each index of the string to form a concatenated temporary string.
		The temporary string needs to searched in the ditionary, as seaching in vector might take O(n) complexity need to optimize the search using set.
		if (the temp string is present in the ditionary) {
			store it in temp vector and go ahead and perform the recursive call for next index to form new string
			after the calls is completed, you want to remove it from the temp vector as the temp is already processed and saved
		}
		
		base case: 
		if (the index if already at str.size()) {
			iteratively append the temp vector elements seperated by space and save in global vector<string> and return;
		}
	*/
	vector<string> temp;
	unordered_set<string> dictionarySet;
	
	for (auto element : wordDict) {
		dictionarySet.insert(element);
	}
	//call the helper funtion
	helper(s, temp, dictionarySet, 0);
	
	return result;
    }
};