

class Solution
{
public:
    int count_sub_occurance(string sub)
    {
        if (sub.length() == 0)
            return 0;
        int occ = 0;
        int ind = 0;
        int sub_length = sub.length();
        for (auto c : valid_chars)
        {
            if (sub[ind] == c)
            {
                ind++;
                if (ind >= sub_length)
                {
                    ind = 0;
                    occ++;
                    if (kk <= occ)
                        return occ;
                }
            }
        }
        return occ;
    }
    void rec_on_valid_Chars(string sub, int start_from)
    {
        if (count_sub_occurance(sub) < kk)
            return;
        if (longest.length() < sub.length())
            longest = sub;
        else if (longest.length() == sub.length() && longest < sub)
            longest = sub;

        char chars[50];
        memset(chars, 0, 50 * sizeof(char));
        for (int t = start_from; t < valid_chars.length(); t++)
        {
            char c = valid_chars[t];
            if (chars[c - 'a'])
                continue;
            rec_on_valid_Chars(sub + c, t + 1);
            chars[c - 'a']++;
        }
    }
    string valid_chars;
    string longest;
    string input;
    int kk;

    string longestSubsequenceRepeatedK(string s, int k)
    {
        int char_count[50];
        memset(char_count, 0, sizeof(int) * 50);
        for (auto c : s)
            char_count[c - 'a']++;
        for (auto c : s)
            if (char_count[c - 'a'] >= k)
                valid_chars += c;
        if (valid_chars.length() == 0)
            return "";
        if (s.length() < k)
            return "";
        input = s;
        kk = k;
        string empty;
        char chars[50];
        memset(chars, 0, 50 * sizeof(char));

        for (int t = 0; t < valid_chars.length(); t++)
        {
            char c = valid_chars[t];
            if (chars[c - 'a'])
                continue;

            rec_on_valid_Chars(empty + valid_chars[t], t + 1);
            chars[c - 'a']++;
        }

        return longest;
    }
};