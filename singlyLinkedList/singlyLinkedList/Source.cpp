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
	void push_back(T data); //����� (�������� � ����� ������) 
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
	//���� �� � ��� ������ �������?
	
	Node<T>*head;  //���� ��� �������� 1-�� �������� � ������ head(������), ��� ��������� �.� ��� �������� ������������ ������ ����� ���������� � ������������ ������
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











	return 0;
}
