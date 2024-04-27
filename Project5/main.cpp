#include <iostream>
#include <string>
#include <limits>

//���������� �������
int size = 10;
int receiptSize = 1;
int* idArr = new int[size];
double cash = 100000.0;
double cashIncome = 0, cardIncome = 0, totalIncome = 0;
std::string* nameArr = new std::string[size];
int* CountArr = new int[size];
double* priceArr = new double[size];
int totalSum;
template <typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size);
void ShowStorage();

//������� ��� ����
std::string* nameReceiptArr = new std::string[receiptSize];
int* CountReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];

//�������� �������
void ChangePrice();
void Start();
void Selling();
void AddElementToReceipt(int id, int count);
void Shop();
void DeleteMainArr();
void CreateStorage();
void PrintReceipt();
void RemoveFromStorage();
void AddToStorage();
void ChangeStorage();
void AddElementToEnd();
void DeleteElementByIndex();
void CashStatus();
void ApplyDiscounts(int totalSume);
int main()
{
	setlocale(LC_ALL, "ru");
	CreateStorage();
	Start();
	DeleteMainArr();
	return 0;
}

void ShowStorage()
{
	std::cout << "ID\t�������� ������\t\t���-��\t����\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << " " << nameArr[i] << "" << CountArr[i] << "  " << "\t" << priceArr[i] << "\n";
	}
}
void ChangePrice()
{
	int id;
	double newPrice;
	do
	{
		std::cout << "������� Id ������ ��� ��������� ����: ";
		std::cin >> id;


	} while (id < 1 || id > idArr[size - 1]);
	std::cout << "\n\n������ �����: " << nameArr[id - 1] << " = " << priceArr[id - 1];
	do
	{
		std::cout << "\n������� ����� ����: ";
		std::cin >> newPrice;


	} while (newPrice < 0.01 || newPrice > 30000.0);
	priceArr[id - 1] = newPrice;
	std::cout << "\n���� ������� ��������!\n\n";
}
void Start()
{
	std::cout << "\t\t����� ���������� � ������� ��������������� ������� �������� < RAVE > " << "\n" << "\n";

	std::string adminLogin = "1";
	std::string adminPassword = "1";
	std::string login, password;
	int choose;
	bool exit = false;
	do
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login);
		std::cout << "������� ������: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "�������� ����� ��� ������\n";
			std::cout << "����������� ��� ���?\n1 - ��\n - ����� �� ���������\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choose == 2)
			{
				exit = true;
			}
		}
		else
		{
			exit = true;
			int chooseStorageType;
			do
			{
				std::cout << "������� ������ ������: \n1 - ������� �����\n2 - ������� ����� �������: " << "\n";
				std::cin >> chooseStorageType;
			} while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				CreateStorage();
				Shop();
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "� ���������� \n";
			}
			else
			{
				std::cerr << "Error chooseStorageType";
			}
		}

	} while (!exit);



}
void AddElementToReceipt(int id, int count)
{
	std::string* nameReceiptArrTemp = new std::string[receiptSize];

	int* CountReceiptArrTemp = new int[receiptSize];

	double* priceReceiptArrTemp = new double[receiptSize];
	for (int i = 0; i < receiptSize; i++)
	{
		nameReceiptArrTemp[i] = nameReceiptArr[i];
		CountReceiptArrTemp[i] = CountReceiptArr[i];
		priceReceiptArrTemp[i] = priceReceiptArr[i];

	}
	delete[]nameReceiptArr;
	delete[]CountReceiptArr;
	delete[]priceReceiptArr;
	receiptSize++;

	nameReceiptArr = new std::string[receiptSize];
	CountReceiptArr = new int[receiptSize];
	priceReceiptArr = new double[receiptSize];
	for (int i = 0; i < receiptSize - 1; i++)
	{
		nameReceiptArr[i] = nameReceiptArrTemp[i];
		CountReceiptArr[i] = CountReceiptArrTemp[i];
		priceReceiptArr[i] = priceReceiptArrTemp[i];

	}


	nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
	CountReceiptArr[receiptSize - 1] = count;
	priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
	CountArr[id - 1] -= count;

}
void Shop()
{
	while (true)
	{
		int choose;
		do
		{
			std::cout << "\n1 - �������� �����\n";
			std::cout << "2 - ������ �������\n";
			std::cout << "3 - �������� ����\n";
			std::cout << "4 - ������� �����\n";
			std::cout << "5 - ��������� �����\n";
			std::cout << "6 - ��������� ������\n";
			std::cout << "7 - �������� �����\n";
			std::cout << "0 - ��������� �����\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 7);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Selling();
		}
		else if (choose == 3)
		{
			ChangePrice();
		}
		else if (choose == 4)
		{
			RemoveFromStorage();
		}
		else if (choose == 5)
		{
			AddToStorage();
		}
		else if (choose == 6)
		{
			ChangeStorage();
		}
		else if (choose == 0)
		{
			break;
		}
		else if (choose == 7)
		{
			CashStatus();
		}
		else if(choose == 0)
		{
			CashStatus();
			std::cerr << "Error";
		}

	}
}
void DeleteMainArr()
{
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
}
void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{ "\tLunacy Loud\t\t" ,"\tLunacy Night\t\t","\tLunacy x Dark Project\t","\tLunacy DINI\t\t","\tLunacy x HyperX\t\t","\tLunacy x DIOR\t\t","\tLunacy x GUCCI\t\t","\tLunacy x Guess\t\t","\tLunacy Soni\t\t","\tLunacy RAVE\t\t" };
	int count[staticSize]{ 6,7,5,3,5,7,6,7,5,8 };
	double price[staticSize]{ 18000.0, 29000.0, 12000.0, 23000.0, 18000.0, 34000.0, 28000.0, 49000.0, 34000.0, 45000.0 };
	FillArr(id, idArr, staticSize);
	FillArr(name, nameArr, staticSize);
	FillArr(count, CountArr, staticSize);
	FillArr(price, priceArr, staticSize);
}
void PrintReceipt()
{
	std::cout << "\t��������\t\t���-��\t����\n";
	for (int i = 0; i < receiptSize; i++)
	{
		std::cout << "" << nameReceiptArr[i] << "" << CountReceiptArr[i] << "\t" << priceReceiptArr[i] << "\n";
	}
	std::cout << "\n";
}
void RemoveFromStorage()
{
	{
		int id;
		int count;
		do
		{
			std::cout << "������� Id ������ ��� ��������: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\n\n������ �����: " << nameArr[id - 1] << " = " << CountArr[id - 1] << "����\n\n";
		do
		{
			std::cout << "\n������� ���-�� ������: ";
			std::cin >> count;


		} while (count < 0 || count  > CountArr[id - 1]);
		CountArr[id - 1] -= CountArr[id - 1];
		std::cout << "\n����� ������� ������!";
	}
}
void AddToStorage()
{
	{
		int id;
		int count;
		do
		{
			std::cout << "������� Id ������ ��� ����������: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\n\n������ �����: " << nameArr[id - 1] << " = " << priceArr[id - 1];
		do
		{
			std::cout << "\n���������: ";
			std::cin >> count;


		} while (count < 0 || count > 1000);
		priceArr[id + 1] = count;
		std::cout << "\n������� ���������!";
	}
}
void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - �������� ����� � �����\n";
		std::cout << "2 - ������ ����� �� ������\n";
		std::cout << "0 - �����\n";
		std::cin >> choose;
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		AddElementToEnd();
	}
	else if (choose == 2)
	{
		DeleteElementByIndex();
	}
	else
	{
		std::cout << "�����";
	}
}
void AddElementToEnd()
{

	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		CountArrTemp[i] = CountReceiptArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
	size++;

	idArr = new int[size];
	nameArr = new std::string[size];
	CountArr = new int[size];
	priceArr = new double[size];

	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = nameArrTemp[i];
		CountArr[i] = CountArrTemp[i];
		priceArr[i] = priceArrTemp[i];
	}
	idArr[size - 1] = size - 1;
	std::cout << "������� ��� ������ ������: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "������� ���-�� ������ ������: \n";
	std::cin >> CountArr[size - 1];
	std::cout << "\n������� ���� ������ ������: \n";
	std::cin >> priceArr[size - 1];
	delete[]idArrTemp;
	delete[]nameArrTemp;
	delete[]CountArrTemp;
	delete[]priceArrTemp;
}
void DeleteElementByIndex()
{
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		CountArrTemp[i] = CountReceiptArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
	size--;

	idArr = new int[size];
	nameArr = new std::string[size];
	CountArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do
	{
		std::cout << "������� Id ������ ��� ��������: ";
		std::cin >> index;

	} while (index < 1 || index > size);
	for (int i = 0, g = 0; g < size, i < size; g++, i++)
	{

		if (index - 1 == i)
		{
			i++;
			idArr[g] = idArrTemp[i];
			nameArr[g] = nameArrTemp[g];
			CountArr[g] = CountArrTemp[i];
			priceArr[g] = priceArrTemp[i];

		}
		else
		{
			idArr[g] = idArrTemp[g];
			nameArr[g] = nameArrTemp[i];
			CountArr[g] = CountArrTemp[i];
			priceArr[g] = priceArrTemp[i];

		}
	}
	delete[]idArrTemp;
	delete[]nameArrTemp;
	delete[]CountArrTemp;
	delete[]priceArrTemp;



}
void CashStatus()
{
	totalIncome = cashIncome + cardIncome;
	std::cout << "�������� � �����: " << cash << "\n������� �� ��������: " << cashIncome << "\n������� �� �������: " << cardIncome << "\n\n�������� ������� �� �����: " << totalIncome << "\n\n";

}
void Selling()
{
	bool isFirst = true;
	int chooseId, chooseCount;
	char confirm;
	double totalSum = 0;
	while (true)
	{
		totalSum = 0;
		do
		{
			std::cout << "������� id ������: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "������� ������ ���\n";
				continue;
			}
			if (CountArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\n��������� �����: " << nameArr[chooseId - 1] << "\n";
					std::cout << "���-�� ������� ������ ������: " << CountArr[chooseId - 1];
					std::cout << "������� ���-�� ������: ";
					std::cin >> chooseCount;
					if (chooseCount < 1 || chooseCount > CountArr[chooseId - 1])
					{
						std::cerr << "Error\n";
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				std::cerr << "������ �� ������ ���\n";
				continue;
			}
			std::cout << "\n  �����: " << nameArr[chooseId - 1] << "\t ���-��: " << chooseCount;
			std::cout << "\n 1 - ����������\n 2 - ������: ";
			std::cin >> confirm;
			if (confirm == '1')
			{
				if (isFirst)
				{
					nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
					CountReceiptArr[receiptSize - 1] = chooseCount;
					priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
					CountArr[chooseId - 1] -= chooseCount;
					totalSum += priceArr[chooseId - 1] * chooseCount;
					isFirst = false;
				}
				else
				{
					AddElementToReceipt(chooseId, chooseCount);
					totalSum += priceArr[chooseId - 1] * chooseCount;
				}

			}

			else
			{
				continue;
			}
			std::cout << "������ ��� 1 �����?: \n";
			std::cout << "1 - ��\n2 - ��������� �������\n";
			std::cin >> confirm;
			if (confirm == '1')
			{
				continue;
			}
			break;

		} while (true);
		PrintReceipt();
		ApplyDiscounts(totalSum);
		int pay = 0;
		std::cout << "\n\n\n";
		do
		{
			std::cout << "1 - ��������\n2 - ������ ������\n0 - ����\n\n";
			std::cin >> pay;
		} while (pay < 0 || pay > 2);
		if (pay == 1)
		{
			cash += totalIncome;
			cashIncome += totalSum;
		}
		else if (pay == 2)
		{
			cardIncome += totalSum;
		}
		else 
		{
			Shop();
		}
	}
}
	void ApplyDiscounts(int totalSum)
	{
		if (totalSum >= 40000)
		{
			totalSum -= totalSum * 0.20;
		}
		else if (totalSum >= 25000)
		{
			totalSum -= totalSum * 0.10; 
		}
		std::cout << "�������� ����� �� �������: " << totalSum;
	}



	template<typename Arr>
	void FillArr(Arr staticArr, Arr dinArr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			dinArr[i] = staticArr[i];
		}
	}