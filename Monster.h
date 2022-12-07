#pragma once

const int NAME_LENGTH{ 16 };

struct Monster 
{
	char name[NAME_LENGTH];
	int hp;

	Monster* pNext;
};							// 자기 참조 구조체
