//Реализация односвязного списка, методы добавление в конец/началосписка, удаление..
#include<iostream>
#include<string>
using namespace std;

template<typename T>   //шаблонный класс List
class List
{
public:
	List();
	~List();
	void push_back(T data); //метод (вставить в конец списка) 
	int GetSize() { return Size; } //можем посмотреть кол-во элементов из скольки состоит наш список
	T& operator[](const int index); // получить доступ к элементу, интерирование по элементам. Перегрузим оператор [], index - номер элемента который мы должны найти в нашем списке
private:

	template<typename T>   //шаблонный класс Node
	class Node //узел
	{
	public:
		Node* pNext;        //указатель на следующий элемент
		T data;
		Node(T data=T(), Node* pNext=nullptr)  //конструктор , указатель для добавления последнего элмента будет указать в никуда(nullptr)
		{
			this->data = data;       //присваевыем значение      
			this->pNext = pNext;          //присваеваем nullptr параметр по умолчанию, чтобы не выйти за границы
		}
	};
	//есть ли у нас первый элемент?
	
	Node<T>*head;  //поле для хранения 1-го элемента в списке head(голова), это указатель т.к все элементы односвязного списка будут выделяться в динамической памяти
	int Size; //количество элементов в односвязном списке

};

template<typename T>
List<T>::List()
{
	Size = 0;        //еще нет элментов как только создали List
	head = nullptr; //список пуст
}
template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data) //реализация добавления элмента в конец списка, T data - параметр который мы получаем, который нужно добавить в конец списка 
{
	if (head == nullptr)    //проверка не пустой ли 1 элмент
	{
		head = new Node <T>(data);     //если пустой, то создаем новый элемент Node
	}
	else   //если в head что-то есть, создаем новый элемент и присваеваем адресс этого нового элемента последнему полю(адресу) pNext односвязного списка
	{
		Node<T>* current = this->head; //присваеваем значение нашего заголовка
		while (current->pNext!=nullptr)  //идем по всем нашим Node и ищем самую последнию
		{
			current = current->pNext;  //если не nullptr идем дальше, когда находим элемент который указывает на NULL...
		}
	
		current->pNext = new Node<T>(data); //когда находим элемент который адрес указывает на NULL, значит можем создавать новый элемент и его адрес присвоить вместо NULL
	
	    
	}
	Size++; //каждый раз после вызова метода push_back будет увелечение на 1 (кол-во элементов)

}

template<typename T>
T& List<T>::operator[](const int index) //нахождение по индеку и возвращение данные
{
	int couner = 0; //счетчик, в каком элменты мы находимся
	Node<T>* current = this->head; //временный объект, в каком элементе мы находимся, чтобы проверить адресс след элемент
	while (current !=nullptr) //работает пока указатель не равен null
	{
		if (couner == index) //если значение счетчика couner = index ,то мы нашли нужный элемент и возвращаем его
		{
			return current->data; //заберем данный из поля data под нужным нам index'ом и возвращаем их
		}
		current = current->pNext; // если условие if (couner == index) не выполнилось, спросим адресс след.элемента
		couner++; //счетчик
	}
}






int main()
{

	List<int> lst;
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);

	//cout << lst[2] << endl;

	for (int i = 0; i < lst.GetSize(); i++) //вывод элементов нашего lst
	{
		cout << lst[i] << endl;
	}

	//заполним рандомными числами
	List<int> lst2;
	int numbersCount;
	cin >> numbersCount;
	for (int i = 0; i < numbersCount; i++)
	{
		lst2.push_back(rand() & 10);
	}
	for (int i = 0; i < lst2.GetSize(); i++)
	{
		cout << lst2[i] << endl;
	}











	return 0;
}
