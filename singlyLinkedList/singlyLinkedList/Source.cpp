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
	void push_back(T data); //����� (�������� � ����� ������) 
	void clear(); //����� ������� ������ ���������(������������ ������ � ������������ ������)
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
void List<T>::clear() //����� �������� ��������� � ���������
{
	while (Size) //���� 0 �� �� ������ �� �����, ����� ����������� ���� Size>0
	{
		pop_front(); //������� ������� 
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
	List<int> lst;
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);

	//cout << lst[2] << endl;

	for (int i = 0; i < lst.GetSize(); i++) //����� ��������� ������ lst
	{
		cout << lst[i] << endl;
	}

	//�������� ���������� �������
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
	//////////////////////
	cout << endl;
	List<int> lst3;
	lst3.push_back(55);
	lst3.push_back(11);
	lst3.push_back(2);
	for (int i = 0; i < lst3.GetSize(); i++)
	{
		cout << lst3[i] << endl;
	}
	cout << endl << "��������� � ������ :" << lst3.GetSize() << endl << "�������� �������� clear " << endl << endl;
	lst3.clear();
	cout << endl << "��������� � ������ :" << lst3.GetSize() << endl;






	system("pause");
	return 0;
}
