#include <iostream>
#include"List.h"
#include<string>

template<typename T>
void Display(List<T>& list, int& operationNum, int& displayOperationNum);

template<typename T>
void Insert(List<T>& list, int& operationNum);

template<>
void Insert(List<char*>& list, int& operationNum);

template<typename T>
void Edit(List<T>& list, int& operationNum);

template<>
void Edit(List<char*>& list, int& operationNum);

template<typename T>
void Delete(List<T>& list, int& operationNum);

template<typename T>
void Change(List<T>& list, int& operationNum);

int main()
{
	List<int> list;

	//—v‘f‚Ì‘€ì‚Ì‘€ì”Ô†
	int operationNum = 0;

	//—v‘f‚Ì•\¦‚Ì‘€ì”Ô†
	int displayOperationNum = 0;

	while (true)
	{
		std::cout << "[—v‘f‚Ì‘€ì]" << std::endl;
		std::cout << "1.—v‘f‚Ì•\¦" << std::endl;
		std::cout << "2.—v‘f‚Ì‘}“ü" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.—v‘f‚Ì•ÒW" << std::endl;
			std::cout << "4.—v‘f‚Ìíœ" << std::endl;
		}

		std::cout << "5.—v‘f‚Ì•À‚Ñ‘Ö‚¦(ƒIƒvƒVƒ‡ƒ“)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

		std::cout << std::endl;

		if (operationNum == 0)
		{
			//‘€ì”Ô†‚ğæ“¾
			std::cin >> operationNum;
		}
		system("cls");

		switch (operationNum)
		{
		case 1://—v‘f‚Ì•\¦

			Display(list, operationNum, displayOperationNum);

			break;

		case 2://ÅŒã”ö‚É—v‘f‚ğ’Ç‰Á

			Insert(list, operationNum);

			break;

		case 3://”CˆÓ‚ÌêŠ‚Ì’l‚ğ•ÏX

			Edit(list, operationNum);

			break;

		case 4://”CˆÓ‚ÌêŠ‚Ìíœ

			Delete(list, operationNum);

			break;

		case 5://”CˆÓ‚ÌêŠ‚Æ”CˆÓ‚ÌêŠ‚ğ“ü‚ê‘Ö‚¦

			Change(list, operationNum);

			break;
		}
	}

	return 0;
}

template<typename T>
void Display(List<T>& list, int& operationNum, int& displayOperationNum)
{
	std::cout << "[—v‘f‚Ì•\¦]" << std::endl;
	std::cout << "1.—v‘f‚Ìˆê——•\¦" << std::endl;
	std::cout << "2.‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;
	std::cout << std::endl;
	std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	//‘€ì”Ô†‚ğæ“¾
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:

		std::cout << "[—v‘f‚Ìˆê——•\¦]" << std::endl;

		//ˆê——•\¦
		list.Dump();

		std::cout << "—v‘f”:" << list.Size() << std::endl;

		break;

	case 2:

		std::cout << "[‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦]" << std::endl;
		std::cout << "•\¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		//w’è‚·‚é”Ô†‚ğæ“¾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//w’è‚µ‚Ä•\¦
		list.Specifyvalue(specifyNum);

		break;

	case 9:

		operationNum = 0;
		break;
	}

	//—v‘f‘€ì‚É–ß‚ç‚È‚©‚Á‚½‚ç
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << std::endl;
		std::cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << std::endl;

		//‘€ì”Ô†‚ğæ“¾
		std::cin >> displayOperationNum;

		system("cls");
		switch (displayOperationNum)
		{
		case 1:

			operationNum = 1;

			break;

		case 2:

			operationNum = 0;

			break;

		default:
			break;
		}
	}
}

template<typename T>
void Insert(List<T>& list, int& operationNum)
{
	std::cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << std::endl;
	std::cout << std::endl;
	std::cout << "—v‘f‚ğ’Ç‰Á‚·‚éêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		T value{};

		std::cin >> value;

		list.PushBack(value);

		std::cout << "—v‘f" << value << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		T value{};

		std::cin >> value;

		list.Insert(value, index);

		std::cout << "—v‘f" << value << "‚ª" << index << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template<>
void Insert(List<char*>& list, int& operationNum)
{
	std::cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << std::endl;
	std::cout << std::endl;
	std::cout << "—v‘f‚ğ’Ç‰ÁêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		char value[64];

		std::cin >> value;

		list.PushBack(value);

		std::cout << "—v‘f" << value << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		char value[64];

		std::cin >> value;

		list.Insert(value, index);

		std::cout << "—v‘f" << value << "‚ª" << index << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template<typename T>
void Edit(List<T>& list, int& operationNum)
{
	std::cout << "[—v‘f‚Ì•ÒW]" << std::endl;
	std::cout << std::endl;
	std::cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		T changeValue{};
		std::cin >> changeValue;

		list.ChangeValue(changeValue, valueNum);
		std::cout << std::endl;

		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª" << '"' << changeValue << '"' << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}
}

template<>
void Edit(List<char*>& list, int& operationNum)
{
	std::cout << "[—v‘f‚Ì•ÒW]" << std::endl;
	std::cout << std::endl;
	std::cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		char changeValue[64];
		std::cin >> changeValue;

		list.ChangeValue(changeValue, valueNum);
		std::cout << std::endl;

		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª" << '"' << changeValue << '"' << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}
}

template<typename T>
void Delete(List<T>& list, int& operationNum)
{
	std::cout << "[—v‘f‚Ìíœ]" << std::endl;
	std::cout << std::endl;
	std::cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f" << '"' << list.Getvalue(valueNum) << '"' << "íœ‚µ‚Ü‚µ‚½" << std::endl;

		list.Delete(valueNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << valueNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 4;
	}
}

template<typename T>
void Change(List<T>& list, int& operationNum)
{
	std::cout << "[—v‘f‚Ì•À‚Ñ‘Ö‚¦]" << std::endl;
	std::cout << std::endl;
	std::cout << "•À‚Ñ‘Ö‚¦•û–@‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
	std::cout << "1.¸‡‚Å•À‚Ñ‘Ö‚¦‚é" << std::endl;
	std::cout << "2.~‡‚Å•À‚Ñ‘Ö‚¦‚é" << std::endl;

	int changeOperationNum;

	std::cin >> changeOperationNum;

	switch (changeOperationNum)
	{
	case 1:

		list.Sort();
		std::cout << "ƒŠƒXƒg‚Ì—v‘f‚ğ¸‡‚Å•À‚Ñ‘Ö‚¦‚Ü‚µ‚½" << std::endl;

		break;

	case 2:

		list.Sort(false);
		std::cout << "ƒŠƒXƒg‚Ì—v‘f‚ğ~‡‚Å•À‚Ñ‘Ö‚¦‚Ü‚µ‚½" << std::endl;

		break;

	default:
		break;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 5;
	}
}