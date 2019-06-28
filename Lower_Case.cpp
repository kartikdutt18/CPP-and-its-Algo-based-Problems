#include <boost/algorithm/string.hpp>  
class Solution {
public:
    string toLowerCase(string str) {
        boost::algorithm::to_lower(str);
        return str;
    }
};