#include <iostream>
#include "LinkedList.h"		// �̰� �ϳ��� include�ص�
							// Monster.h�� ������ ��� ���� include �ȴ�

							// ���� Monster�� LinkedList�� ��� �ҷ��͵�
							// #pragma once�� �ߺ��� �������ش�.
							// = �ѹ��� �����ض�!

// Single Linked List


/*	�⺻ ����

	Monster* monA = new Monster {"demon", 100};
	Monster* monB = new Monster {"wolf", 10};

	monA->pNext = monB;		// monA�� monB�� �����Ŵ
*/
int main()
{
	MonsterList myList;

	CreateMonster(myList, "Demon", 100);
	CreateMonster(myList, "Wolf", 10);

	std::cout << GetCountMonsterList(myList) << std::endl;
	PrintMonsterList(myList);
	PrintMonsterListRecursvie(myList.pHead);

	Monster* pFind = FindMonster(myList, "Demon");
	if (pFind == nullptr)
	{
		std::cout << "NOT FOUND" << std::endl;
	}
	// -> ȭ��ǥ ������ = ������ �� ����� ����
	// nullptr�̸� �������� �ȵǹǷ� ������ �����̴�
	// ���� ���� ���ܸ� ������ ������ �ȳ���
	else
	{
		std::cout << pFind->name << " : " << pFind->hp << " FOUND " << std::endl;
	}
	
	DeleteMonster(myList, "Demon");
	PrintMonsterList(myList);
	std::cout << GetCountMonsterList(myList) << std::endl;
}
