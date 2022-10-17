class node
{
    public:

        int data;
    int row;
    int col;
    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
};
class Solution
{
    public:

        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            priority_queue<node*, vector<node*>, compare> minHeap;
            int mini = INT_MAX, maxi = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                mini = min(nums[i][0], mini);
                maxi = max(nums[i][0], maxi);
                node *root = new node(nums[i][0], i, 0);
                minHeap.push(root);
            }
            int start = mini, end = maxi;
            while (!minHeap.empty())
            {
                node *temp = minHeap.top();
                minHeap.pop();

                mini = temp->data;

                int row = temp->row;
                int col = temp->col;

                if (end - start > maxi - mini)
                {
                    start = mini;
                    end = maxi;
                }
                if (col + 1 < nums[row].size())
                {
                    maxi = max(nums[row][col + 1], maxi);
                    node *root = new node(nums[row][col + 1], row, col + 1);
                    minHeap.push(root);
                }
                else
                    break;
            }
            vector<int> ans;
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
};