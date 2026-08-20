class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Intuition:
        //I can only change one character at a time of of the string.
        // I have to check my sting by changing one character
        //Can I represent this in the form of a graph, where one character changed string will be my neighbour
        //If I represent it as a graph, now BFS traversal will provide me the shortest path to reach the target

        //Same as BFS I will maintain a queue where I need to store string and it level 
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        //maintain a unordered_set to check wether the modified string is present in the set in O(1)
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            //I have found the end word with number of transformation as the second element
            if (word == endWord) {
                return level;
            }
            //iterate over each character of the string
            for (int i = 0; i < word.length(); ++i) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    //changing the character
                    word[i] = ch;
                    //check if the string is present in the set or not
                    if (wordSet.count(word)) {
                        //first remove the string from the set, which will act as visited array logic
                        wordSet.erase(word);
                        //update the level and push the word, level into the queue for further BFS
                        q.push(make_pair(word, level+1));
                    }

                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};
