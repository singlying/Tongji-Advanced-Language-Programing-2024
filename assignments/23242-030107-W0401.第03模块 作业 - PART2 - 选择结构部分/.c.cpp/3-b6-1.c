
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");

	double num;
	int an_attempt_to_remove_this_warning = scanf("%lf", &num);

	//ÌáÈ¡ÕûÊı²¿·ÖºÍĞ¡Êı²¿·Ö
	long long integer = (long long)num;
	double decimal = num - integer;

	//ÕûÊı²¿·Ö
	int int_10 = (int)(integer / (int)1e9);
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
	printf("´óĞ´½á¹ûÊÇ:\n");

	//ÒÚÎ»
	if (int_10) {  //Ê®ÒÚÎ»
		switch (int_10) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("Ê°");
	}

	if (int_9) { //ÒÚÎ»
		switch (int_9) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
	}

	int yi = 0; //´ú±íÒÚÉÏÓĞÊı×Ö
	if (int_10 || int_9) { //ÒÚ,Ê®ÒÚ·ÇÁã
		printf("ÒÚ");
		yi = 1;
	}

	//ÍòÎ»
	if (int_8) { //Ç§Íò
		switch (int_8) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("Çª");
	}
	else { //ÅĞ¶ÏÊä³öÁã
		if (yi && (int_7 || int_6 || int_5)) {
			printf("Áã");
		}
	}

	if (int_7) { //°ÙÍò
		switch (int_7) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("°Û");
	}
	else {
		if (int_8 && (int_6 || int_5)) {
			printf("Áã");
		}
	}

	if (int_6) { //Ê®Íò
		switch (int_6) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("Ê°");
	}
	else {
		if (int_7 && int_5) {
			printf("Áã");
		}
	}

	if (int_5) {  //Íò
		switch (int_5) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
	}

	int wan = 0;
	if (int_8 || int_7 || int_6 || int_5) {
		printf("Íò");
		wan = 1;
	}
	
	//¸öÎ»
	if (int_4) { //Ç§
		switch (int_4) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("Çª");
	}
	else { //ÅĞ¶ÏÊä³öÁã
		if ((yi || wan) && (int_3 || int_2 || int_1)) {
			printf("Áã");
		}
	}

	if (int_3) { //°Ù
		switch (int_3) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("°Û");
	}
	else {
		if (int_4 && (int_2 || int_1)) {
			printf("Áã");
		}
	}

	if (int_2) { //Ê®
		switch (int_2) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("Ê°");
	}
	else {
		if (int_3 && int_1) {
			printf("Áã");
		}
	}

	if (int_1) {  //¸ö
		switch (int_1) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
	}

	//Êä³ö Ôª
	int yuan = 0;
	if (int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10) {
		printf("Ô²");
		yuan = 1;
		if (!digit_1 && !digit_2) {
			printf("Õû");
		}
	}
	else if (!(int_1 || int_2 || int_3 || int_4 || int_5 || int_6 || int_7 || int_8 || int_9 || int_10 || digit_1 || digit_2)) { //Êä³öÁãÔª
		printf("ÁãÔ²Õû");
	}

	//½Ç·Ö
	if (digit_1) {
		switch (digit_1) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("½Ç");
		if (!digit_2) {
			printf("Õû");
			//return 0;
		}
	}
	else {
		if (yuan && digit_2) {
			printf("Áã");
		}
	}

	if (digit_2) { //·Ö
		switch (digit_2) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		printf("·Ö");
	}

	printf("\n");

	return 0;
}