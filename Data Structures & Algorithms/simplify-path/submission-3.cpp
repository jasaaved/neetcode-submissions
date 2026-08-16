class Solution {
public:
    string simplifyPath(string path) {
        const int n = static_cast<int>(path.size());
        stack<string> st;
        string file;

        for(int i = 0; i <= n; ++i){
            if(i == n || path[i] == '/'){
                if(file == ".." && !st.empty()){
                    st.pop();
                }

                else if(file != "." && file != "" && file != ".."){
                    st.push(file);
                }

                file = "";
            }

            else{
                file += path[i];
            }
        }

        string simple_path;
        
        while(!st.empty()){
            simple_path = "/" + st.top() + simple_path;
            st.pop();
        }

        return simple_path == "" ? "/" : simple_path;
    }
};