class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        
        for (int i = 0; i < s.length(); ++i) {
            //Check is whether it is opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                my_stack.push(s[i]);
            } else {
                if (my_stack.empty()) {
                    return false;
                }
                if ((s[i] == ')' && my_stack.top() == '(') ||
                    (s[i] == '}' && my_stack.top() == '{') || 
                    (s[i] == ']' && my_stack.top() == '[')) {
                    my_stack.pop();
                } else {
                    return false;
                }
            }
            // if (!my_stack.empty()) {
            //     if (my_stack.top() == s[i]) {
            //         my_stack.pop();
            //     } else {
            //         my_stack.push(s[i]);
            //     }
            // } else {
            //     my_stack.push(s[i]);
            // }            
        }
        return my_stack.empty();
    }
};
