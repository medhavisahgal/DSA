#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // recipies that are present in someone elses recipies incredients list
        int n = recipes.size();
        int n1 = ingredients.size();
        int n2 = supplies.size();
        unordered_set<string> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                for (int k = 0; k < ingredients[j].size(); k++)
                {
                    if (recipes[i] == ingredients[j][k])
                    {
                        s.insert(recipes[i]);
                    }
                }
            }
        }
        // I have stored it in set because we can do find operation in O(1)
        unordered_set<string> s1(supplies.begin(), supplies.end());
        // now check for those whose supplies are available to make it if yes then add them to supplies
        for (const string &recipe : s)
        {
            int index = -1;
            for (int j = 0; j < n; j++)
            {
                if (recipes[j] == recipe)
                {
                    index = j;
                    break;
                }
            }
            bool present = true;
            for (int j = 0; j < ingredients[index].size(); j++)
            {
                if (s1.find(ingredients[index][j]) == s1.end())
                {
                    present = false;
                    break;
                }
            }
            if (present)
            {
                s1.insert(recipe);
            }
        }
        // now we have all the supplies we need and can make
        vector<string> ans;
        for (int i = 0; i < n1; i++)
        {
            bool present = true;
            for (int j = 0; j < ingredients[i].size(); j++)
            {
                if (s1.find(ingredients[i][j]) == s1.end())
                {
                    present = false;
                    break;
                }
            }
            if (present)
            {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};