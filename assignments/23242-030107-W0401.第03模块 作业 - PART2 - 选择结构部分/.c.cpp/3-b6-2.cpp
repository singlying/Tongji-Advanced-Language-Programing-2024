
#include<iostream>
#include <cmath>
using namespace std;

int main()
{

	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;

	double num;
	cin >> num;

	//ÌáÈ¡ÕûÊı²¿·ÖºÍĞ¡Êı²¿·Ö
	long long integer = (long long)num;
	double decimal = num - integer;

	//ÕûÊı²¿·Ö
	int int_10 = (int) (integer / (int)1e9);
	int int_9 = integer % (int)1e9 / (int)1e8;
	int int_8 = integer % (int)1e8 / (int)1e7;
	int int_7 = integer % (int)1e7 / (int)1e6;
	int int_6 = integer % (int)1e6 / (int)1e5;
	int int_5 = integer % (int)1e5 / (int)1e4;
	int int_4 = integer % (int)1e4 / (int)1e3;
	int int_3 = integer % (int)1e3 / (int)1e2;
	int int_2 = integer % (int)1e2 / (int)1e1;
	int int_1 = integer % 10;
	//Ğ¡Êı²¿·Ö
	int digit_1 = (int)(round((num - floor(num)) * 100)) / 10 % 10;
	int digit_2 = (int)(round((num - floor(num)) * 100)) % 10;

	//Êä³ö½á¹û
	cout << "´óĞ´½á¹ûÊÇ:" << endl;

	if (int_10) {  //Ê®ÒÚÎ»
		switch (int_10) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}


	if (int_9) { //ÒÚÎ»
		switch (int_9) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
	}

	int yi = 0; //´ú±íÒÚÉÏÓĞÊı×Ö
	if (int_10 || int_9) { //ÒÚ,Ê®ÒÚ·ÇÁã
		cout << "ÒÚ";
		yi = 1;
	}

	//ÍòÎ»
	if (int_8) { //Ç§Íò
		switch (int_8) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Çª";
	}
	else { //ÅĞ¶ÏÊä³öÁã
		if (yi && (int_7 || int_6 || int_5)) {
			cout << "Áã";
		}
	}

	if (int_7) { //°ÙÍò
		switch (int_7) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "°Û";
	}
	else {
		if (int_8 && (int_6 || int_5)) {
			cout << "Áã";
		}
	}

	if (int_6) { //Ê®Íò
		switch (int_6) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}
	else {
		if (int_7 && int_5) {
			cout << "Áã";
		}
	}

	if (int_5) {  //Íò
		switch (int_5) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
	}

	int wan = 0;
	if (int_8 || int_7 || int_6 || int_5) {
		cout << "Íò";
		wan = 1;
	}

	//¸öÎ»
	if (int_4) { //Ç§
		switch (int_4) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Çª";
	}
	else { //ÅĞ¶ÏÊä³öÁã
		if ((yi || wan) && (int_3 || int_2 || int_1)) {
			cout << "Áã";
		}
	}

	if (int_3) { //°Ù
		switch (int_3) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "°Û";
	}
	else {
		if (int_4 && (int_2 || int_1)) {
			cout << "Áã";
		}
	}

	if (int_2) { //Ê®
		switch (int_2) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "Ê°";
	}
	else {
		if (int_3 && int_1) {
			cout << "Áã";
		}
	}

	if (int_1) {  //¸ö
		switch (int_1) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
	}

	//Êä³ö Ôª
	int yuan = 0;
	if (int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10) {
		cout << "Ô²";
		yuan = 1;
		if (!digit_1 && !digit_2) {
			cout << "Õû";
		}
	}
	else if (!(int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10 || digit_1 || digit_2)) { //Êä³öÁãÔª
		cout << "ÁãÔ²Õû";
	}

	//½Ç·Ö
	if (digit_1) {
		switch (digit_1) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "½Ç";
		if (!digit_2) {
			cout << "Õû";
		}
	}
	else {
		if (yuan && digit_2) {
			cout << "Áã";
		}
	}

	if (digit_2) { //·Ö
		switch (digit_2) {
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		cout << "·Ö";
	}

	cout << endl;

	return 0;
}