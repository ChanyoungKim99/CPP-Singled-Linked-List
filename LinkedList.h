#pragma once
#include "monster.h"		// 이게 있어야 Monster 구조체를 사용 가능


// head, tail을 알아야 어디서 시작하고 끝나는지 알 수 있다.
struct MonsterList
{
	Monster* pHead = nullptr;
	Monster* pTail = nullptr;
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
										// 배열의 수정이 없으므로 const 사용
int GetCountMonsterList(MonsterList& list);
void PrintMonsterList(MonsterList& list);
void PrintMonsterListRecursvie(Monster* monster);
Monster* FindMonster(MonsterList& list, const char* name);
void DeleteList(MonsterList& list);
bool DeleteMonster(MonsterList& list, const char* name);


// 생성, 갯수, 검색, 삭제, 삽입