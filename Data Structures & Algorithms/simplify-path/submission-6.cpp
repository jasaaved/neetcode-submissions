#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        const int n = static_cast<int>(path.size());
        vector<string> vs;
        string file;

        for(int i = 0; i <= n; ++i){
            if(i == n || path[i] == '/'){
                if(file == ".." && !vs.empty()){
                    vs.pop_back();
                }

                else if(file != "." && file != ".." && file != ""){
                    vs.push_back(file);
                }

                file = "";
            }
            else{
                file += path[i];
            }
        }

        string simple_path;
        for(const auto& each : vs){
            simple_path += "/" + each;
        }
        
        return simple_path == "" ? "/" : simple_path;
    }
};