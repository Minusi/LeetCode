class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> result;
        result.resize(n);
        for(auto index = 1; index <=n; ++index)
        {
            if(index % 3 == 0 && index % 5 == 0)
            {
                result[index - 1] = "FizzBuzz";
            }
            else if(index % 3 == 0)
            {
                result[index - 1] = "Fizz";
            }
            else if(index % 5 == 0)
            {
                result[index - 1] = "Buzz";
            }
            else
            {
                result[index - 1] = std::to_string(index);
            }
        }

        return result;
    }
};