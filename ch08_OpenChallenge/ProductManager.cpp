#include <iostream>
#include <string>

#include "Product.h"
#include "Book.h"
#include "CompactDisc.h"
#include "ConversationBook.h"
#include "ProductManager.h"

using namespace std;

ProductManager::ProductManager() {
	numOfProduct = 0;
	productID = 0;
	for (int i = 0; i < 100; i++) p[i] = NULL;
}
ProductManager::~ProductManager() {
	for (int i = 0; i < numOfProduct; i++) delete p[i];
}
void ProductManager::run() {
	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;;
	int menuNo = 0;
	int pType = 0;

	while (menuNo != 3) {
		cout << endl << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
		cin >> menuNo;
		cin.ignore(); // cin의 버퍼에서 '\n' 제거

		switch (menuNo) {
		case 1:	// 상품 추가
			if (numOfProduct >= 100) {
				cout << "더 이상 추가할 수 없습니다." << endl;
				break;
			}
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
			cin >> pType;
			cin.ignore(); // cin의 버퍼에서 '\n' 제거

			if (pType < 1 || pType > 3) {
				cout << "잘못된  상품 종류입니다." << endl;
				break;
			}
			addProduct(pType);
			numOfProduct++;
			break;
		case 2:	// 모든 상품 조회
			for (int i = 0; i < numOfProduct; i++) {
				p[i]->printProduct();
				cout << endl;
				}
			break;
		case 3:	// 끝내기
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
		}
	}
}
void ProductManager::addProduct(int pType) {
	string descript, maker, title, author, albumTitle, artist, title2, author2, language;
	int price, ISBN;

	cout << "상품설명>>";
	getline(cin, descript);

	cout << "생산자>>";
	getline(cin, maker);

	cout << "가격>>";
	cin >> price; cin.ignore(); // cin의 버퍼에서 '\n' 제거

	switch (pType) {
	case 1: // 책
		cout << "책 제목: ";
		getline(cin, title);
		cout << "저자: ";
		getline(cin, author);
		cout << "ISBN: ";
		cin >> ISBN;
		cin.ignore();
		p[productID] = new Book(pType, productID, descript, maker, price, ISBN, title, author);//업캐스팅
		break;

	case 2: // 음악 CD
		cout << "앨범 제목: ";
		getline(cin, albumTitle);
		cout << "가수: ";
		getline(cin, artist);
		p[productID] = new CompactDisc(pType, productID, descript, maker, price, albumTitle, artist);
		break;

	case 3: // 회화책
		cout << "책 제목: ";
		getline(cin, title2);
		cout << "저자: ";
		getline(cin, author2);
		cout << "언어: ";
		getline(cin, language);
		cout << "ISBN: ";
		cin >> ISBN;
		cin.ignore();
		p[productID] = new ConversationBook(pType, productID, descript, maker, price, ISBN, title2, author2, language);
		break;
	}
	productID++;
}