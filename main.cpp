#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cout << "�������AA��������" << endl;
    cin >> n;

    vector<string> names(n);
    vector<vector<float>> bill(n, vector<float>());

    float sum = 0;
    for(int i=0; i<n; i++)
    {
        printf("�����%d���˵����֣�\n", i+1);
        cin >> names[i];

        printf("����%s�������Ʒ�۸��Կո�ָ�����\n", names[i].c_str());
        float price = 0.;

        cin >> price;
        bill[i].push_back(price);
        sum += price;
        while(cin.get() != '\n')
        {
            cin >> price;
            bill[i].push_back(price);
            sum += price;
        }
    }

    float discount = 0.;
    cout << "�����Żݵļ۸�Ԫ����" << endl;
    cin >> discount;

    printf("\n AA�˵��������£�\n");
    for(int i=0; i<n; i++)
    {
        printf("---------------------------------------------------\n");
        printf("|%*s    |", 6, names[i].c_str());
        printf("  ��Ʒԭ��  |    �ֿ�    |    ʵ��    |\n");
        printf("---------------------------------------------------\n");

        float i_sum = 0.;
        for(int j=0; j<bill[i].size(); j++)
        {
            float price = bill[i][j];
            float i_dis = price / sum * discount;
            i_sum += price;
            printf("|  ��Ʒ%2d  |%9.2f   |%9.2f   |%9.2f   |\n", j+1, price, -i_dis, price-i_dis);
        }
        float i_sum_dis = i_sum / sum * discount;

        printf("---------------------------------------------------\n");
        printf("|   С��   |%9.2f   |%9.2f   |%9.2f   |\n", i_sum, -i_sum_dis, i_sum-i_sum_dis);
        printf("---------------------------------------------------\n");
    }
    printf("---------------------------------------------------\n");
    printf("|   �ܼ�   |%9.2f   |%9.2f   |%9.2f   |\n", sum, -discount, sum-discount);
    printf("---------------------------------------------------\n");

    system("pause");
    return 0;
}

