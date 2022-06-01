#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

class Purchase {
public:
	void createOrder(string userId, string sellerId, string productName, ProductCollection* pc, OrderCollection* oc);
};

class OrderCollection {
private:
	Order* ownedProduct[100]; //�迭 �ʱ�ȭ ��Ŵ
	int cnt = 0; //cnt�� �߰���

public:
	void addOrder(Product* p, string buyer, string userId);
	void removeOrder(string product);
	Order* findFirst();
	Order* getNext();
	string getOrderItem(string product);
	int getTotalPrice(Product*);
	int getTotalRate(Product*);
	int calculateTotalPrice();
	double calculateTotalRate();
};

class Order {
private:
	string buyer;//�ش� �κ��� userRef�������� ��ü �������� ������ �ǹ� -> �ϴ� addOrder �Ķ���ʹ� string���� user(buyer) ���� �޴� ������ ��
	string product; //�ش� �κ��� productRef�� ��ü �����ѵ�
	string company;
	int price;
	int rate = 0;
	int totalPrice;
	int totalRate = 0;
	OrderCollection* ownedProductCollection;
	Product* productRef;

public:
	Order() {};
	Order(string buyer, string userId, OrderCollection* ownedProductCollection, Product* productRef);
	void getOrderItemDetails();
	void rateOrderItem(string product, int rate);
};