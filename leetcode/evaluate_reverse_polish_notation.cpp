/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> sk;

        for(auto token: tokens){
        	// is operator
        	if(token == "-" ||
        		token == "+"||
        		token == "*" ||
        		token == "/"){

        		int x = stoi(sk.top());
        		sk.pop();
        		int y = stoi(sk.top());
        		sk.pop();
        		
        		if(token[0] == '+')
        			y += x;
        		else if(token[0] == '-')
        			y -= x;
        		else if(token[0] == '*')
        			y *= x;
        		else
        			y /= x;

        		sk.push(to_string(y));
        	}else{
        		sk.push(token);
        	}
		}
        return stoi(sk.top());
    }
};