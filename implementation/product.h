#pragma once

#include <string>
#include <vector>
#include "order.h"

using namespace std;

class ProductUI {
	ProductCollection* productCollection;
	OrderCollection* orderCollection;
public:
	ProductUI() {};
	ProductUI(ProductCollection* p, OrderCollection* o) {
		this->productCollection = p;
		this->orderCollection = o;
	}
	void startInterface();
	void showProduct();
	void purchaseProduct();
};

class SearchProduct {
public:
	SearchProduct() {};
	void searchProductByName(ProductCollection * pc, string name);
};

class Product {
private:
	string name;
	string manufacturer;
	int price;
	int quantity;
	double avgRating;
	string sellerID;
	ProductCollection* productCollection;

public:
	void dedeuctStock(int quantity);
	void getProductDetail();
	string getName(); // �ش� �޼ҵ� �߰��� -> �˻��� private �����;���
	string getSellerId(); //�ش� �޼ҵ� �߰��� -> �˻��� private �����;���
	string getManufacturer();//�ش� �޼ҵ� �߰��� -> �˻��� private �����;���
	int getPrice();//�ش� �޼ҵ� �߰��� -> �˻��� private �����;���
};

class ProductCollection {
private:
	Product* ownedProduct[100]; //�迭�� �ʱ�ȭ ��Ŵ
	int cnt; // �ش� �κ� �߰��� -> �˻� ��, iteration���� ����� ����� ��ǰ ��Ͻ� �ش� cnt �ø���!!!!

public:
	ProductCollection();
	bool validateProduct(string name);
	Product* getProductByName(string name);
	Product* getProductByNameAndSellerID(string sellerId, string name); // �ش� �޼ҵ� �߰��� -> ���Ž�, ��ǰ��� ��ǰ�ĸ��� ���̵� �Է¹���
	Product* getSoldoutProduct();
	Product* getProducts();
	Product createProduct(string name, string manufacturer, int price, int quantity, string sellerID);
};