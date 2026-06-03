#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <string>
using namespace std;

#include "Product.h"

class ProductManager {
	Product* p[100];
	int numOfProduct;
	int productID;
public:
	ProductManager();
	~ProductManager();
	void run();
	void addProduct(int pType);
	virtual void print() {};
};

#endif