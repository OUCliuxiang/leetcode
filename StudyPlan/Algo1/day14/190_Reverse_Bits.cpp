/** 
 * Reverse bits of a given 32 bits unsigned integer.          
 * Note that in some languages, such as Java, there is no unsigned 
 * integer type. In this case, both input and output will be given 
 * as a signed integer type. They should not affect your implemen-
 * tation, as the integer's internal binary representation is the 
 * same, whether it is signed or unsigned.           
 * In Java, the compiler represents the signed integers using 2's 
 * complement notation. Therefore, in Example 2 above, the input 
 * represents the signed integer -3 and the output represents the 
 * signed integer -1073741825.
 * 
 * Example 1:          
 * Input: n = 00000010100101000001111010011100           
 * Output:    964176192 (00111001011110000010100101000000)      
 * Explanation: The input binary string 0000001010010100000111101-
 * 0011100 represents the unsigned integer 43261596, so return 96-
 * 4176192 which its binary representation is 0011100101111000001-
 * 0100101000000.           
 * 
 * Example 2:               
 * Input: n = 11111111111111111111111111111101            
 * Output:   3221225471 (10111111111111111111111111111111)          
 * Explanation: The input binary string 111111111111111111111111111-
 * 11101 represents the unsigned integer 4294967293, so return 3221-
 * 225471 which its binary representation is 1011111111111111111111-
 * 1111111111.        
 * 
 * Constraints:        
 * The input must be a binary string of length 32
 */
 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        reverse(s.begin(), s.end());
        return (uint32_t)bitset<32>(s).to_ullong();
    }
}; 