class Solution {
public:
    template <typename T>
    string to_str(T str){
        stringstream stream;
        stream << str;
        return stream.str();
    }

    // Convert string to int
    template <typename T>
    int to_int(T num){
        int val;
        stringstream stream;
        stream << num;
        stream >> val;
        return val;
    }
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<string>cur;
        for(string s:ops){
            if(s == "+"){
                string a = cur.back();
                string b = cur[(int)cur.size() - 2];
                int A = to_int(a), B = to_int(b);
                string c = to_str(A+B);
                cur.push_back(c);
            }
            else if(s == "D"){
                string a = cur.back();
                int A = to_int(a);
                string c = to_str(A*2);
                cur.push_back(c);
            }
            else if(s == "C"){
                cur.pop_back();
            }
            else cur.push_back(s);
        }
        for(string s: cur){
            int A = to_int(s);
            ans += A;
        }
        return ans;
    }
};
