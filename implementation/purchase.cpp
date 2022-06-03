#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

Purchase::Purchase(ifstream * fs, ofstream * os){
    this->fin = fs;
    this->fout = os;
}

void Purchase::createOrder(string userId, string sellerId, string productName, ProductCollection* pc, OrderCollection* oc) {
	Product* product = pc->getProductByNameAndSellerID(sellerId, productName);

	oc->addOrder(product, sellerId, userId);
}