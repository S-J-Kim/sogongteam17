#pragma once

#include "getproductlist.h"

GetProductListUI::GetProductListUI(GetProductList* control){
	this->getProductListControl = control;
}

void GetProductListUI::getMyProductList(){
	Product* myProducts = this->getProductListControl->getMyProductList();
	
	
}

GetProductList(ProductCollection*, ifstream * if, ofstream *of){
	this->fin = if;
	this->fout = of;
}

GetProductList::GetProductList(ProductCollection* productList){
	this->productList = productList;
	this->gplUI = new GetProductListUI(this);

	this->gplUI->getMyProductList();
}

Product* GetProductList::getMyProductList(){
	return this->productList->getProducts();
}
