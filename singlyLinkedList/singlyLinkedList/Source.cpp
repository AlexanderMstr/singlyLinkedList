//���������� ������������ ������, ������ ���������� � �����/������������, ��������..
#include<iostream>
#include<string>
using namespace std;

template<typename T>   //��������� ����� List
class List
{
public:
	List();
	~List();
	void pop_front(); // ����� �������� ������� �������� ������, �.� 0 �������
	void pop_back(); //����� �������� ���������� ��������
	void push_back(T data); //����� (�������� � ����� ������) 
	void push_front(T data); //����� ������� ������� ������
	void clear(); //����� ������� ������ ���������(������������ ������ � ������������ ������)
	void insert(T value, int index); //����� ���������� ������ �� �������
	void removeAt(int index); //����� �������� �������� �� ���������� �������
	int GetSize() { return Size; } //����� ���������� ���-�� ��������� �� ������� ������� ��� ������
	
	T& operator[](const int index); // �������� ������ � ��������, ������������� �� ���������. ���������� �������� [], index - ����� �������� ������� �� ������ ����� � ����� ������
private:
	template<typename T>   //��������� ����� Node
	class Node //����
	{
	public:
		Node* pNext;        //��������� �� ��������� �������
		T data;
		Node(T data=T(), Node* pNext=nullptr)  //����������� , ��������� ��� ���������� ���������� ������� ����� ������� � ������(nullptr)
		{
			this->data = data;       //����������� ��������      
			this->pNext = pNext;          //����������� nullptr �������� �� ���������, ����� �� ����� �� �������
		}
	};
	
	Node<T>*head;  //���� �� � ��� ������ �������? ���� ��� �������� 1-�� �������� � ������ head(������), ��� ��������� �.� ��� �������� ������������ ������ ����� ���������� � ������������ ������
	int Size; //���������� ��������� � ����������� ������
};

template<typename T>
List<T>::List()
{
	Size = 0;        //��� ��� �������� ��� ������ ������� List
	head = nullptr; //������ ����
}

template<typename T>
List<T>::~List()
{
	clear(); //���������� ���� clear ��� ������� ������, ����� ������ List, ����� �� ���� ������ ������
}

template<typename T>
void List<T>::pop_front() //���������� �������� ������� �������� ���������
{
	//������ ������� head ������ �����, �� �������� ��� ��������, ����� ������� ����.������� hedom
	Node<T> *temp = head; //��������� ������ ������� ������ ����� heda, �.� ������ �� 0-��� ������� ������, ����� �� ����� ��� ������� 
	head = head->pNext; //� ��������� head �������� ������ ����.�������� � �� ����� ��������� ����� 2-�� ��������(1)
	delete temp; //������ ������ head �.� temp, ������� ��������� �� ������ ������� ������ he�d'a �� 0 ������� ���������
	Size--; //��������� ���-�� ��������� � ��������� �� 1
}

template<typename T>
void List<T>::pop_back() //���������� ������ �������� ���������� �������� ������
{
	removeAt(Size - 1);  //��������� ��������� ������� � �������� ����� ������� �� �������.
}

template<typename T>
void List<T>::push_back(T data) //���������� ���������� ������� � ����� ������, T data - �������� ������� �� ��������, ������� ����� �������� � ����� ������ 
{
	if (head == nullptr)    //�������� �� ������ �� 1 ������
	{
		head = new Node <T>(data);     //���� ������, �� ������� ����� ������� Node
	}
	else   //���� � head ���-�� ����, ������� ����� ������� � ����������� ������ ����� ������ �������� ���������� ����(������) pNext ������������ ������
	{
		Node<T>* current = this->head; //����������� �������� ������ ���������
		while (current->pNext!=nullptr)  //���� �� ���� ����� Node � ���� ����� ���������
		{
			current = current->pNext;  //���� �� nullptr ���� ������, ����� ������� ������� ������� ��������� �� NULL...
		}
	
		current->pNext = new Node<T>(data); //����� ������� ������� ������� ����� ��������� �� NULL, ������ ����� ��������� ����� ������� � ��� ����� ��������� ������ NULL

	}
	Size++; //������ ��� ����� ������ ������ push_back ����� ���������� �� 1 (���-�� ���������)
}

template<typename T>
void List<T>::push_front(T data) //���������� �������� ������� ������ (����� ������� �������� � ����������� ������)
{
	head = new Node<T>(data, head); //�������� ������ �������� � �������� �� �� ��� �� ���������� head'��, �������� ���������� data � ������ head
	Size++; //����������� ���-��� ��������� �� 1
}

template<typename T>
void List<T>::clear() //����� �������� ��������� � ���������
{
	while (Size) //���� 0 �� �� ������ �� �����, ����� ����������� ���� Size>0
	{
		pop_front(); //������� ������� 
	}
}

template<typename T>
void List<T>::insert(T value, int index) //����� ���������� ���������� �� �������
{
	if (index==0) //���� ������=0 �� �������� ��� ������ � ������ ������ �.� �� ������� 0
	{
		push_front(value);
	}
	else //���� ������ �� ����� 0, ��...
	{
		Node<T>* previous = this->head; //������� ��������� ��������� previous � ����������� ��� �������� ���� 
		for (int i = 0; i < index-1; i++) //����, ����� ����� ���������� �������, ������� ��������� ����� ��� ��������� �� ������� �������� �� ����� �������� ����� ������
		{
			previous = previous->pNext; //���� 2, �� ���������� �������� ����� ������ ����� ����.��������

		}
		Node<T>* newNode = new Node<T>(value, previous->pNext); //������ ����� ������ ���� Node � �������� ��� � ����������� ������ � � ����������� ������� ����� pNext 
		previous->pNext = newNode; //� ���� pNext ��������� ����� �������� �������
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index) //���������� ������ �������� �������� �� �������
{
	if (index == 0) //���� ������=0, �� ������ ������� 1�� �������
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head; //
		for (int i = 0; i < index-1; i++)  //���� ���������� �������
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext; // ������� ���������� ������ � ������ ��� ���� �������� �������� �� ��������� ���������� toDelete
		previous->pNext = toDelete->pNext;   //����������� ����� � ��������, ������� �� ����� ������� �� ����� ����.��������
		delete toDelete;
		Size--;
	}
}

template<typename T>
T& List<T>::operator[](const int index) //���������� �� ������ � ����������� ������
{
	int couner = 0; //�������, � ����� ������� �� ���������
	Node<T>* current = this->head; //��������� ������, � ����� �������� �� ���������, ����� ��������� ������ ���� �������
	while (current !=nullptr) //�������� ���� ��������� �� ����� null
	{
		if (couner == index) //���� �������� �������� couner = index ,�� �� ����� ������ ������� � ���������� ���
		{
			return current->data; //������� ������ �� ���� data ��� ������ ��� index'�� � ���������� ��
		}
		current = current->pNext; // ���� ������� if (couner == index) �� �����������, ������� ������ ����.��������
		couner++; //�������
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
	cout << "������� ����������� ��������� ��� �������� ������������ ������: " << endl;;
	cin >> size;
	cout << "��������� ������ ���������� ������� - 1 " <<endl
		 << "��������� � ������ - 2" << endl;
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
		cout << "������� �����" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cin>> value2;
			lst.push_back(value2);
		}
		cout << "������ ������ �� �����:" << endl;
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << endl;
		}
	}
	for (int i = 0; true; i++)
	
	{
		cout << endl;
		cout << "�������� ������� � ����� ������ - 1 " << endl
			<< "������� ��������� ������� ������ - 2 " << endl
			<< "������� ��� �������� - 3 " << endl
			<< "�������� ������� ������ ������ - 4" << endl;
		cin >> value3;
		if (value3 == 1)
		{
			cout << "������� ������� ��� ���������� � ����� ������:" << endl;
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
			cout << "������� ������� ��� ���������� � ������ ������:" << endl;
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
