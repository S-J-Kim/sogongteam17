// ��� ����

#include "user.h"
#include "signup.h"
#include "withdraw.h"

#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();

// ���� ����
FILE *in_fp, *out_fp;

// �ֻ������� �� Ŭ������ vector�� �����ؼ� ������ �ִ´� (repository)
// CRUD�� �Ͼ�� ������ control class�� �ش� repository ���۷����� �����ؼ�
// ���ϴ� object ã�� �� �ֵ��� �Ѵ�

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	FILE *in_fp = fopen(INPUT_FILE_NAME, "r+");
	FILE *out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask(in_fp, out_fp);

	return 0;
}

void doTask(FILE *fin, FILE *fout)
{
	// entity class repository
	UserRepository *userlist = new UserRepository();

	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		scanf_s("%d %d", &menu_level_1, &menu_level_2);

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:

			switch (menu_level_2)
			{
			case 1:
				new Signup(userlist, fin, fout);
				break;

			case 2:
				new WithdrawAccount(userlist);
			}

		case 7:

			switch (menu_level_2)
			{
			case 1: // "6.1. ���ᡰ �޴� �κ�

				is_program_exit = 1;
				break;
				;
			}

			return;
		}
	}
}