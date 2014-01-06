// SUD.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "GameManager.h"
 
// window���� �����ϴ� ����� �����, ���� ���� ����� �ֵ���ǥ. �����쿡�� �����ϴ� ���� .h���� �ȴ�
// ���� �� �� �� ������ Ŭ���ؼ� �ֵ� ��Ŭ��� �ص� �ȴ�

int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

	CGameManager* gameManager = CGameManager::GetInstance();

	gameManager->Init();
	gameManager->Run(); //���� ������ �־��. 
	gameManager->Release();

	//getchar();
	return 0;
}

