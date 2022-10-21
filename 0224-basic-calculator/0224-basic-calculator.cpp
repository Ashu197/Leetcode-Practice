class Solution {
public:
    int calculate(string s) {
        int size=s.size(),i=0,ans=0,prevSum=0;
        char prevOperation='+';
        stack<pair<int,char>> sta;
        while(i<size){
            if(s[i]==' '){
                i++;
                continue;
            }
            int num=0;
            while(i<size && isdigit(s[i]))
                num = num*10 + (s[i++]-'0');
            if(prevOperation=='+')
                prevSum += num;
            else if(prevOperation=='-')
                prevSum += -1*num;
            if(s[i]=='('){
                sta.push({prevSum,prevOperation});
                prevSum=0;
                prevOperation='+';
                i++;
                continue;
            }
            else if(s[i]==')'){
                pair<int,char> p=sta.top();
                sta.pop();
                if(p.second=='-')
                    prevSum = -1*prevSum + p.first;
                else
                    prevSum = prevSum + p.first;
            }
            prevOperation=s[i++];
        }
        return prevSum;
    }
};