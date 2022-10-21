class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;
        
        for (int i = 0; i < n; ++i) {
            // Step 1: find out how many words can fit on line with one space between words
            int begin = i, lineSize = words[i].size();
            while (i + 1 < n && words[i + 1].size() + lineSize + 1 <= maxWidth) {
                lineSize += words[++i].size() + 1; // +1 for space between prev and cur words
            }
            
            // Step 2: determine space size (round-robin distribution)
            int numWords = i - begin + 1, spaceSize = 1, numExtraSpaces = 0;
            if (numWords > 1 && i < n - 1) { // if greater than one word in line and this isn't the last line
                int remaining = maxWidth - lineSize;
                spaceSize = remaining / (numWords - 1) + 1; // +1 since lineSize already includes 1 space betweeen words
                numExtraSpaces = remaining % (numWords - 1);
            }
            
            // Step 3: create line
            string line = words[begin];
            for (int j = 1; j < numWords; ++j) {
                // add space between prev and cur words
                line.append(spaceSize, ' ');
                if (j <= numExtraSpaces) {
                    line.push_back(' ');
                }
                line += words[begin + j];
            }
            if (line.size() < maxWidth) { // add right padding
                line.append(maxWidth - line.size(), ' ');
            }
            
            result.emplace_back(line);
        }
        
        return result;
    }
};