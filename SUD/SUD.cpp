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
	CGameManager gameManager;

	gameManager.Init();
	gameManager.Run(); //���� ������ �־��. 
	gameManager.Release();

	//getchar();
	return 0;
}

