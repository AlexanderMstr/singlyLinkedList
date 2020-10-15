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
	void pop_front(); // метод удаления первого элемента списка, т.е 0 элемент
	void pop_back(); //метод удаления последнего элемента
	void push_back(T data); //метод (вставить в конец списка) 
	void push_front(T data); //метод вставки вначало списка
	void clear(); //метод очистки списка коллекции(освобождения данных в динамическом списке)
	void insert(T value, int index); //метод добавления данных по индексу
	void removeAt(int index); //метод удаления элемента по указанному индексу
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
	
	Node<T>*head;  //есть ли у нас первый элемент? поле для хранения 1-го элемента в списке head(голова), это указатель т.к все элементы односвязного списка будут выделяться в динамической памяти
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
	clear(); //используем мето clear для очистки памяти, после вызова List, чтобы не было утечки памяти
}

template<typename T>
void List<T>::pop_front() //реализация удаления первого элемента коллекции
{
	//нельзя удалить head первый элемт, мы потеряем всю колекцию, нужно сделать след.элемент hedom
	Node<T> *temp = head; //временный объект который хранит адрес heda, т.е ссылку на 0-вой элемент списка, чтобы мы могли его удалить 
	head = head->pNext; //в указатель head присвоим адресс след.элемента и он будет указывать адрес 2-го элемента(1)
	delete temp; //удалим бывший head т.е temp, который указывает на данные бывшего нашего heаd'a на 0 элемент коллекции
	Size--; //уменьшаем кол-во элементов в коллекции на 1
}

template<typename T>
void List<T>::pop_back() //реализация метода удаления последнего элемента списка
{
	removeAt(Size - 1);  //вычисляем последний элемент и вызываем метод удаения по индексу.
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
void List<T>::push_front(T data) //добавление элемента вначале списка (самая быстрая операция в односвязном списке)
{
	head = new Node<T>(data, head); //создание нового элемента и указание на то что он становится head'ом, передаем информацию data и старый head
	Size++; //увеличивыем кол-вол элементов на 1
}

template<typename T>
void List<T>::clear() //метод удаления элементов в коллекции
{
	while (Size) //если 0 то мы выйдем из цикла, будет выполняться пока Size>0
	{
		pop_front(); //удаляем элемент 
	}
}

template<typename T>
void List<T>::insert(T value, int index) //метод добавления информации по индексу
{
	if (index==0) //если индекс=0 то передаем эти данные в начало списка т.е по индексу 0
	{
		push_front(value);
	}
	else //если индекс не равен 0, то...
	{
		Node<T>* previous = this->head; //создаем временный указатель previous и присваевыем ему значение хеда 
		for (int i = 0; i < index-1; i++) //цикл, чтобы найти предыдущий элемент, который находится перед тем элементов по индексу которого мы хотим добавить новые данные
		{
			previous = previous->pNext; //если 2, то перебираем элементы пнекс хранит адрес след.элемента

		}
		Node<T>* newNode = new Node<T>(value, previous->pNext); //создам новый объект типа Node и передаем ему в конструктор данные и у предыдущего элемент берем pNext 
		previous->pNext = newNode; //в поле pNext добавляем адрес текущего объекта
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) //реализация метода удаления элемента по индексу
{
	if (index == 0) //если индекс=0, то просто удаляем 1ый элемент
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head; //
		for (int i = 0; i < index-1; i++)  //ищем предыдущий элемент
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext; // находим предыдущий элмент и адресс его след элемента помещаем во временную переменную toDelete
		previous->pNext = toDelete->pNext;   //присваевыем адрес у элемента, который мы хотим удалить на адрес след.элемента
		delete toDelete;
		Size--;
	}
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
	setlocale(LC_ALL, "RU");

	int size;
	int value;
	int value2;
	int value3;
	int value4;
	int value5;
	int value6;
	List<int> lst;
	cout << "Введите колличество элементов для создания односвязного списка: " << endl;;
	cin >> size;
	cout << "Заполнить список рандомными числами - 1 " <<endl
		 << "Заполнить в ручную - 2" << endl;
	cin >> value;
	cout << endl;
	if (value==1)
	{
		for (int i = 0; i < size; i++)
		{
			lst.push_back(rand() & 100);
		}
		for (int i = 0; i < lst.GetSize(); i++)
	    {
		cout << lst[i] << endl;
	    }
	}
	else
	{
		cout << "Введите числа" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cin>> value2;
			lst.push_back(value2);
		}
		cout << "Создан список из чисел:" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << endl;
		}
	}
	for (int i = 0; true; i++)
	
	{
		cout << endl;
		cout << "Добавить элемент в конец списка - 1 " << endl
			<< "Удалить последний элемент списка - 2 " << endl
			<< "Удалить все элементы - 3 " << endl
			<< "Добавить элемент вперед списка - 4" << endl;
		cin >> value3;
		if (value3 == 1)
		{
			cout << "Введите элемент для добавления в конец списка:" << endl;
			cin >> value4;
			lst.push_back(value4);
			cout << endl;
			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
		}
		if (value3 == 2)
		{
			lst.pop_back();
			cout << endl;
			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
		}
		if (value3 == 3)
		{
			lst.clear();
			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
		}
		if (value3 == 4)
		{
			cout << "Введите элемент для добавления в начало списка:" << endl;
			cin >> value6;
			lst.push_front(value6);
			cout << endl;
			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}
		}
		}
	



	system("pause");
		return 0;

	}
