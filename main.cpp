#include <iostream>
#include "LinkedList.h"		// 이거 하나만 include해도
							// Monster.h를 포함한 모든 것이 include 된다

							// 설령 Monster와 LinkedList를 모두 불러와도
							// #pragma once가 중복을 방지해준다.
							// = 한번만 선언해라!

// Single Linked List


/*	기본 원리

	Monster* monA = new Monster {"demon", 100};
	Monster* monB = new Monster {"wolf", 10};

	monA->pNext = monB;		// monA를 monB에 연결시킴
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
	// -> 화살표 연산자 = 역참조 후 멤버에 접근
	// nullptr이면 역참조가 안되므로 오류가 날것이다
	// 위와 같이 예외를 만들어야 오류가 안난다
	else
	{
		std::cout << pFind->name << " : " << pFind->hp << " FOUND " << std::endl;
	}
	
	DeleteMonster(myList, "Demon");
	PrintMonsterList(myList);
	std::cout << GetCountMonsterList(myList) << std::endl;
}
