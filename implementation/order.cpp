#include <iostream>
#include "order.h"
#include "product.h"

using namespace std;

void Purchase::createOrder(string userId, string sellerId, string productName, ProductCollection* pc, OrderCollection* oc) {
	Product* product = pc->getProductByNameAndSellerID(sellerId, productName);

	oc->addOrder(product, sellerId, userId);
}

void OrderCollection::addOrder(Product* p, string buyer, string userId) {
	this->ownedProduct[this->cnt] = new Order(buyer, userId, this, p);
	this->cnt++;
}

Order::Order(string buyer, string userId, OrderCollection* ownedProductCollection, Product* productRef) {
	this->buyer = buyer;//�ش� �κ��� userRef�������� ��ü �������� ������ �ǹ� -> �ϴ� addOrder �Ķ���ʹ� string���� user(buyer) ���� �޴� ������ ��
	this->product = productRef->getName();
	this->company = productRef->getManufacturer();
	this->price = productRef->getPrice();
	this->totalPrice = productRef->getPrice();
	this->ownedProductCollection = ownedProductCollection;
	this->productRef = productRef;
}
