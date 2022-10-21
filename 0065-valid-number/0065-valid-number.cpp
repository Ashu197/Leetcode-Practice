class Solution {
private:
string makeSchema(string s) {
string schemaS;
for (int i = 0 ; i < s.size() ; i ++ ) {
if( s[i] >= '0' && s[i] <= '9' ) {
if (schemaS == "" || schemaS.at(schemaS.size() - 1) != '5') {
schemaS += '5';
}
}
else if( s[i] == '+' || s[i] == '-' ) {
schemaS += '+';
}
else if( s[i] == 'e' || s[i] == 'E' ) {
schemaS += 'e';
}
else if( s[i] == '.' ) {
schemaS += '.';
} else {
return "X";
}
}
return schemaS;
}

public:
bool isNumber(string s) {
string schemaS = makeSchema(s);
if (schemaS == "X") {
return false;
}
if (schemaS[0] == '+') {
schemaS = schemaS.substr(1, schemaS.size() - 1);
}
if (schemaS == "5" || schemaS == "5." || schemaS == ".5" || schemaS == "5.5" ||
schemaS == "5e5" || schemaS == "5.e5" || schemaS == ".5e5" || schemaS == "5.5e5" ||
schemaS == "5e+5" || schemaS == "5.e+5" || schemaS == ".5e+5" || schemaS == "5.5e+5" ) {
return true;
}
return false;
}
};