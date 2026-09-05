#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(const string& path) const {
        vector<string> file_names;
        string file = "";
        const int n = static_cast<int>(path.size());

        for(int i = 0; i <= n; ++i) {
            
            if(i == n || path[i] == '/') {
                if(file == ".." && !file_names.empty()) {
                    file_names.pop_back();
                }

                else if(file != "." && file != ".." && file != "") {
                    file_names.push_back(file);
                }

                file = "";
            }

            else {
                file += path[i];
            }
        }

        string file_path = "";

        for(const string& name : file_names) {
            file_path += "/" + name;
        }
        
        return file_path == "" ? "/" : file_path;
    }
};