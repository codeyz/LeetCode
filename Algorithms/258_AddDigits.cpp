class Solution {
public:
    int addDigits(int num) 
    {
        if(!num)
			return num;
		// the results comes with a periodicity of 9
        return num % 9 ? num % 9 : 9;
    }
};
