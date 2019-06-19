// LeftMaxN.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
һ��nλ������ȥ�����е�kλ��������ȥ��ʹ�����������Ǹ���n-k��λ�������
*/

class Solution
{
public:
    int leftMaxNums(vector<int>nums, int k)
    {
        int n = nums.size();//�ܵ����ָ���
        int count = 1;//��ѡ��Ԫ�ظ���
        int index = -1; //��Բ�ͬλ����Ӧ��������ʼλ��
        int maxNum = 0; //������ɵ��������

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
    cout << len << "λ�����֣�" << endl;

    for (int i = 0; i < len;i++)
    {
        cout << a[i];
    }

    cout << endl << "ɾ��" << k << "��Ԫ�أ����ʣ����Ϊ��" << endl;

    cout << Solution().leftMaxNums(vec, k) << endl;

    system("pause");

	return 0;
}

