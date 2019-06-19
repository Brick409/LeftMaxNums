// LeftMaxN.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
一个n位的数，去掉其中的k位，问怎样去掉使得留下来的那个（n-k）位的数最大？
*/

class Solution
{
public:
    int leftMaxNums(vector<int>nums, int k)
    {
        int n = nums.size();//总的数字个数
        int count = 1;//已选择元素个数
        int index = -1; //针对不同位，对应遍历的起始位置
        int maxNum = 0; //最终组成的最大数字

        if (nums.empty()||k>=nums.size())
        {
            return -1;
        }

        if (k == 0)
        {
            for (int i = 0; i < nums.size();i++)
            {
                maxNum = maxNum * 10 + nums[i];
            }
            return maxNum;
        }

        while (count <= (n-k))
        {
            int temp = 0;

            for (int i = index+1; i < k + count;i++)
            {
                if (nums[i]>temp)
                {
                    temp = nums[i];
                    index = i;
                }
            }

            count++;
            maxNum = maxNum * 10 + nums[index];
        }
        return maxNum;
    }
private:

};


int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = { 3, 3, 2, 4, 6, 8, 1, 3, 5 };
    int len = sizeof(a) / sizeof(a[0]);
    int k = 0;

    vector<int> vec(a, a + len);
    cout << len << "位的数字：" << endl;

    for (int i = 0; i < len;i++)
    {
        cout << a[i];
    }

    cout << endl << "删除" << k << "个元素，最大剩下数为：" << endl;

    cout << Solution().leftMaxNums(vec, k) << endl;

    system("pause");

	return 0;
}

