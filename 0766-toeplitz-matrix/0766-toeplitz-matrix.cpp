class Solution
{
    public:
        bool isToeplitzMatrix(vector<vector < int>> &matrix)
        {
            for (int t = matrix.size() - 1; t > 0; t--)
            {
                int i = t, j = 0;
                int ele = matrix[t][j];
                while (i < matrix.size() and j < matrix[0].size())
                {
                    if (ele != matrix[i][j])
                    {

                        return false;
                    }

                    i++;
                    j++;
                }
            }
            for (int t = 0; t < matrix[0].size(); t++)
            {
                int i = 0, j = t;
                int ele = matrix[i][t];
                while (i < matrix.size() and j < matrix[0].size())
                {
                    if (ele != matrix[i][j])
                    {

                        return false;
                    }

                    i++;
                    j++;
                }
            }

            return true;
        }
};