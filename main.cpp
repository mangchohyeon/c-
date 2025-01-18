#include <iostream>
#include <string>

using namespace std;

//재활용 쓰레기 비용 계산
int cal1(char tr_base_ary [], int tr_cost_ary [], string trash_ary)
{
    string temp = trash_ary;
    int res = 0;
    for(int i = 0; i < 6; i++)
    {
        if(temp[0] == tr_base_ary[i])
        {
            int cost = tr_cost_ary[i];
            res += cost*(temp.length());
            break;
        }
    }

    return res;
}

//일반 쓰레기 비용 계산
int cal2(string trash_ary, int cost)
{
    int res = 0;
    res += ((trash_ary).length()) * cost;
    return res; 
}

int main()
{
    char tr_base_ary[] = {'P', 'C', 'V', 'S', 'G', 'F', 'O'};
    int tr_cost_ary[7];
    char *flag_ary;
    string *trash_ary;
    int N,res = 0;
    
    cin >> N;
    trash_ary = new string[N];
    flag_ary = new char[N];

    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        trash_ary[i] = temp;
        char t = temp[0];
        char flag = 1;
        for(int j = 0; j < temp.length(); j++)
        {
            if(temp[j] != t)
            {
                flag = 0;
                break;
            }
        }
        flag_ary[i] = flag;
    }

    for(int i = 0; i < 7; i++)
    {
        cin >> tr_cost_ary[i];
    }

    for(int i = 0; i < N; i++)
    {
        int temp1;
        //flag_ary[i] == 1
        if(flag_ary[i])
        {
            temp1 = cal1(tr_base_ary, tr_cost_ary, trash_ary[i]);
            int temp2 = cal2(trash_ary, tr_cost_ary[7]);
        }
        else
        {
            res += cal2()
        }
    }




    

    return 0;
}

