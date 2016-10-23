/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution {
public:
    string simplifyPath(string path) {
    	// store dirs
        stack<string> ps;

        for(auto curr = path.begin(); curr != path.end();){ 
        	// skip the first "/"
        	curr ++;

        	auto j = find(curr, path.end(), '/');
        	// get dir name
        	auto dir  = string(curr, j);

        	// skip null dir and "."
        	if(!dir.empty() && dir != "."){
        		if(dir == ".."){
        			if(ps.size() != 0)
        				ps.pop();
        		}else{
        			ps.push(dir);
        		}
        	}
        	
        	curr = j;
        }

        string newpath;
        if(ps.size() == 0){
        	newpath = "/";
        }else{
        	while(ps.size() > 0){
        		newpath = "/" + ps.top() + newpath;
        		ps.pop();
        	}
        }
        return newpath;
    }
};