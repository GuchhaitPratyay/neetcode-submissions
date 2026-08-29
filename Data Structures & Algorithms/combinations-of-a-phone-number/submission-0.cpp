class Solution {
public:
    vector<string> result;
    void helper(string& digits, unordered_map<char, string>& digit_mapping, string& current_string, int digitIndex) {
    	//base case
        if (digits.size() == 0) {
            return;
        }
    	if (digitIndex == digits.size()) {
    		result.push_back(current_string);
    		return;
    	}
    
    	//Get the digit for which you need to find the combinations
    	char tempCh = digits[digitIndex];
    	for (char ch : digit_mapping[tempCh]) {
    		current_string += ch;
    
    		helper(digits, digit_mapping, current_string, digitIndex+1);
    		//backtracking step just to add the character at the current place
    		current_string.pop_back();
    	}
    }
    vector<string> letterCombinations(string digits) {
        /*Intuition:
		I will maintain a map which will track the digits to string mapping
		I will traverse the digits string and for each digit I will look up in the mapping that for its combination with the other
		
		base case:
			if (index == digits.size()) {
				push the current string to result vector
				return
			}
	*/
	
	unordered_map<char, string> digit_mapping;
	digit_mapping.insert({'2', "abc"});
	digit_mapping.insert({'3', "def"});
	digit_mapping.insert({'4', "ghi"});
	digit_mapping.insert({'5', "jkl"});
	digit_mapping.insert({'6', "mno"});
	digit_mapping.insert({'7', "pqrs"});
	digit_mapping.insert({'8', "tuv"});
	digit_mapping.insert({'9', "wxyz"});
	
	string current_string;
	
	helper(digits, digit_mapping, current_string, 0);
	
	return result;

    }
};
