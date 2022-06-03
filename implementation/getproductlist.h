#pragma once
#include <iostream>
#include "product.h"

class GetProductList;
class ProductCollection;

class GetProductListUI{
private:
	GetProductList* getProductListControl;

public:
	GetProductListUI(GetProductList*);
	void getMyProductList();
};

class GetProductList {
private:
	GetProductListUI* gplUI;
	ProductCollection* productList;

	ifstream *fin;
	ofstream *fout;

public:
	GetProductList(ProductCollection*, ifstream * if, ofstream * of);
	ProductCollection* getProductCollection() { return this->productList; }
	Product* getMyProductList();

};