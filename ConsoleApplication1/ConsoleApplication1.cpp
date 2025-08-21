﻿#include <iostream>
using namespace std;


void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;

}


int main()
{
    const int SIZE = 4;
    int stat[SIZE] = { 0, };   // stat[0] 체력           stat[1] 마나            stat[2] 공격력           stat[3] 방어력

    while (1)
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (50 < stat[0] && 50 < stat[1])
        {
            break;
        }
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1)
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0)
        {
            break;
        }

        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    setPotion(5, &HPPotion, &MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "==============================================" << endl;
    cout << "==================================\n" << "<스탯 관리 시스템>\n" << "1. HP 회복\n" << "2. MP 회복\n" << "3. HP 강화\n" << "4. MP 강화\n" << "5. 공격 스킬 사용\n" << "6. 필살기 사용\n" << "7. 나가기\n";

    while (1)
    {
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 7)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else if (7 < choice)
        {
            cout << "다시 입력해주세요." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            if (HPPotion <= 0)
            {
                cout << "포션이 부족합니다." << endl;
                continue;
            }

            stat[0] += 20;
            HPPotion -= 1;

            cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP: " << stat[0] << endl;
            cout << "남은 포션 수: " << HPPotion << endl;
            break;

        case 2:
            if (MPPotion <= 0)
            {
                cout << "포션이 부족합니다." << endl;
                continue;
            }

            stat[1] += 20;
            MPPotion -= 1;

            cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;
            cout << "남은 포션 수: " << MPPotion << endl;
            break;

        case 3:

            stat[0] *= 2;

            cout << "* HP가 2배로 증가되었습니다." << endl;
            cout << "현재 HP: " << stat[0] << endl;
            break;

        case 4:

            stat[1] *= 2;

            cout << "* MP가 2배로 증가되었습니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;
            break;

        case 5:
            if (stat[1] < 50)
            {
                cout << "MP가 부족합니다." << endl;
                continue;
            }

            stat[1] -= 50;

            cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;

            break;

        case 6:

            stat[1] /= 2;

            cout << "필살기 발동!" << endl;
            cout << "현재 MP: " << stat[1] << endl;   ///ddfsdf

            break;
        }

    }
}