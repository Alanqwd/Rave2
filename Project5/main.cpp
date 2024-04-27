#include <iostream>
#include <string>
#include <limits>

//Глобальные массивы
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

//Массивы для чека
std::string* nameReceiptArr = new std::string[receiptSize];
int* CountReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];

//основные функции
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
	std::cout << "ID\tНазвание товара\t\tКол-во\tЦена\n";
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
		std::cout << "Введите Id товара для изменения цены: ";
		std::cin >> id;


	} while (id < 1 || id > idArr[size - 1]);
	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << priceArr[id - 1];
	do
	{
		std::cout << "\nВведите новую цену: ";
		std::cin >> newPrice;


	} while (newPrice < 0.01 || newPrice > 30000.0);
	priceArr[id - 1] = newPrice;
	std::cout << "\nЦена успешно изменена!\n\n";
}
void Start()
{
	std::cout << "\t\tДобро пожаловать в Магазин профессионалных игровых гарнитур < RAVE > " << "\n" << "\n";

	std::string adminLogin = "1";
	std::string adminPassword = "1";
	std::string login, password;
	int choose;
	bool exit = false;
	do
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль\n";
			std::cout << "Попробовать еще раз?\n1 - Да\n - Выход из программы\n";
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
				std::cout << "Введите формат склада: \n1 - готовый склад\n2 - создать склад вручную: " << "\n";
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
				std::cout << "В РАЗРАБОТКЕ \n";
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
			std::cout << "\n1 - Показать склад\n";
			std::cout << "2 - Начать продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменение склада\n";
			std::cout << "7 - Показать кассу\n";
			std::cout << "0 - Закончить смену\n";
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
	std::cout << "\tНазвание\t\tКол-во\tЦена\n";
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
			std::cout << "Введите Id товара для списания: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << CountArr[id - 1] << "Штук\n\n";
		do
		{
			std::cout << "\nВведите кол-во товара: ";
			std::cin >> count;


		} while (count < 0 || count  > CountArr[id - 1]);
		CountArr[id - 1] -= CountArr[id - 1];
		std::cout << "\nТовар успешно списан!";
	}
}
void AddToStorage()
{
	{
		int id;
		int count;
		do
		{
			std::cout << "Введите Id товара для пополнения: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << priceArr[id - 1];
		do
		{
			std::cout << "\nПополнить: ";
			std::cin >> count;


		} while (count < 0 || count > 1000);
		priceArr[id + 1] = count;
		std::cout << "\nУспешно пополнено!";
	}
}
void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - Добавить товар в склад\n";
		std::cout << "2 - Убрать товар из склада\n";
		std::cout << "0 - Выход\n";
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
		std::cout << "Выход";
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
	std::cout << "Введите имя нового товара: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "Введите кол-во нового товара: \n";
	std::cin >> CountArr[size - 1];
	std::cout << "\nВведите цену нового товара: \n";
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
		std::cout << "Введите Id товара для удаления: ";
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
	std::cout << "Наличные в кассе: " << cash << "\nВыручка за наличные: " << cashIncome << "\nВыручка по безналу: " << cardIncome << "\n\nИтоговая выручка за смену: " << totalIncome << "\n\n";

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
			std::cout << "Введите id товара: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "Данного товара нет\n";
				continue;
			}
			if (CountArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\nВыбранный товар: " << nameArr[chooseId - 1] << "\n";
					std::cout << "Кол-во данного товара складе: " << CountArr[chooseId - 1];
					std::cout << "Введите кол-во товара: ";
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
				std::cerr << "Товара на складе нет\n";
				continue;
			}
			std::cout << "\n  Товар: " << nameArr[chooseId - 1] << "\t Кол-во: " << chooseCount;
			std::cout << "\n 1 - Потвердить\n 2 - Отмена: ";
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
			std::cout << "Купить еще 1 товар?: \n";
			std::cout << "1 - Да\n2 - Закончить покупки\n";
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
			std::cout << "1 - Наличные\n2 - Оплата картой\n0 - Меню\n\n";
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
		std::cout << "Итоговая сумма со скидкой: " << totalSum;
	}



	template<typename Arr>
	void FillArr(Arr staticArr, Arr dinArr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			dinArr[i] = staticArr[i];
		}
	}