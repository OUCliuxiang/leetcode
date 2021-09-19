#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2) {
        vector<string> permutations;
        sort(s1.begin(), s1.end());
        do{
            permutations.push_back(s1);
        }while(next_permutation(s1.begin(), s1.end()));
        for (vector<string>::iterator it = permutations.begin(); it != permutations.end(); it++){
            printf("%s\n", (*it).c_str());
            if (s2.find(*it)){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solu;
	string s1 = "ab", s2 = "eidboaoo";
    bool flag = solu.checkInclusion(s1, s2);
    if (flag){
        printf("true\n");
    }else{
        printf("false\n");
    }
    int inde = s2.find(s1);
    cout << inde << endl;
}
