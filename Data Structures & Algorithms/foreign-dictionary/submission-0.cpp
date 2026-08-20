class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //prepare the adjacency list
        unordered_map<char, unordered_set<char>> adjList;
        //we also neee ot maintain the in-degree of each char/ node
        unordered_map<char, int> inDegree;

        //Iterate over each word in the word list
        //and also iterate over each characters
        for (auto& word : words) {
            for (auto& ch : word) {
                if (!adjList.count(ch)) {
                    //insert the character and create an empty set as a value to it
                    adjList[ch] = unordered_set<char>();
                    inDegree[ch] = 0;
                }                
            }
        }

        for (int i = 0; i < words.size()-1; ++i) {
            string s1 = words[i];
            string s2 = words[i+1];

            int minLength = min(s1.size(), s2.size());

            if (s1.size() > s2.size() && s1.substr(0,minLength) == s2.substr(0,minLength)) {
                //This condition will be hit when we cannot form the unique string
                return "";
            }
            //Check if my s1 and s2 diff in which character?
            for (int j = 0; j < minLength; ++j) {
                if (s1[j] != s2[j]) {
                    //This means character s2[j] is dependent on s1[j]
                    if (!adjList[s1[j]].count(s2[j])) {
                        adjList[s1[j]].insert(s2[j]);
                        inDegree[s2[j]] += 1;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto& [ch, degree] : inDegree) {
            if (degree == 0) {
                q.push(ch);
            }
        }

        string resultStr;
        //Perform BFS traversal
        while (!q.empty()) {
            char tempCh = q.front();
            q.pop();

            resultStr += tempCh;

            for (auto& neighbour : adjList[tempCh]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        //This is to check all the unique characters can be used
        return resultStr.size() == inDegree.size() ? resultStr : "";
    }
};
