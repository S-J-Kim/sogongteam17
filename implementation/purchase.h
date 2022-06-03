#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

class Purchase
{
private:
    ifstream *fin;
	ofstream *fout;
public:
    Purchase(ifstream *, ofstream *);
	void createOrder(string userId, string sellerId, string productName, ProductCollection *pc, OrderCollection *oc);
};
