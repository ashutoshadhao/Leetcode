class Solution
{
    public:
        bool validUtf8(vector<int> &data)
        {
            int remain = 0;
            for (auto it: data)
            {
                if (remain == 0)
                {
                    if ((it >> 7) == 0b0)
                        remain = 0;
                    else if ((it >> 5) == 0b110)
                        remain = 1;
                    else if ((it >> 4) == 0b1110)
                        remain = 2;
                    else if ((it >> 3) == 0b11110)
                        remain = 3;
                    else 
                        return false ;
                }
                else
                {
                    if ((it >> 6) == 0b10)
                    {
                        remain--;
                    }
                    else
                        return false;
                }
            }
            if (remain == 0)
                return true;
            return false;
        }
};