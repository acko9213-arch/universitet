#include <iostream>
int proverka(int a, int b) {
	return a + b;
}
int proverka1(int a, int b) {
	return a - b;
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	
	int n;
	std::cout << "¬ведите пор€дковый номер студента по списку группы:";
	std::cin >> n;
	//z4
	bool tr = true; //0x0057F6E7 01
	bool fa = false; //0x0057F6DB 00
	//z5
	char lat = 'a'; //0x0057F6CF 61  ASCI
	//z6
	char rus = 'ц'; //0x0057F6C3 f6  win1251
	//z7
	wchar_t lat1 = L'Y'; //0x0057F6B4 59 00 UTF-16
	//z8
	wchar_t rus1 = L'я'; //0x0057F6A8 2f 04 UTF-16
	//z9
	short sh1 = 9 + n; // 18 0x0057F69C 18 00
	short sh2 = -(9 + n); // e8 0x0057F690 e8 ff
	//z10
	short big = 0x7FFF; //32767
	short small = 0x8000; //-32768
	//z11
	unsigned short big1 = 0x0000; //0
	unsigned short small1 = 0xFFFF; //65535
	//z12
	int y1 = 10 + n; // 19 0x0057F654 19 00 00 00
	int y2 = -(10 + n); // e7 0x0057F648 e7 ff ff ff
	//z13
	int big2 = 0x7FFFFFFF; // 2147483647
	int small2 = 0x80000000; // -2147483648
	//z14
	unsigned int big3 = 0xFFFFFFFF; // 4294967295
	unsigned int small3 = 0x00000000; // 0
	//z15
	long z1 = 11 + n; //1а 0x001AFDAC 1a 00 00 00
	long z2 = -(11 + n); //e6 0x001AFDA0 e6 ff ff ff
	//z16
	long big4 = 0x7FFFFFFF;// 2147483647
	long small4 = 0x80000000;// -2147483648;
	//z17
	unsigned long big5 = 0xFFFFFFFF; // 4294967295
	unsigned long small5 = 0x00000000; // 0
	//z18
	float s1 = 1.0f + n;//4180 0x00AFFB40 00 00 80 41 0 10000011 00000000000000000000000
	float s2 = -(1.0f + n);//c180 0x00AFFB34 00 00 80 c1 1 10000011 00000000000000000000000
	//z19
	double nol = 0.0;
	double inf1 = 1.0 / nol, inf2 = -1.0 / nol, ind = nol / nol;
	std::cout << inf1 << std::endl << inf2 << std::endl << ind <<std::endl;
	//z20
	char prov1 = 'A';//41
	char *prov11 = &prov1;
	wchar_t prov2 = L'A';//41 00
	wchar_t *prov22 = &prov2;
	short prov3 = 1;//01 00
	short *prov33 = &prov3;
	int prov4 = 1;//01 00 00 00
	int *prov44 = &prov4;
	float prov5 = 1.0;//00 00 80 3f
	float *prov55 = &prov5;
	double prov6 = 1.0;//00 00 00 00 00 00 f0 3f
	double *prov66 = &prov6;
	*prov11 = *prov11 + 3;//D
	*prov22 = *prov22 + 3;//D
	*prov33 = *prov33 + 3;//4
	*prov44 = *prov44 + 3;//4
	*prov55 = *prov55 + 3;//4.0
	*prov66 = *prov66 + 3;//4.0
	//z21
	char cha = 'A';//41
	char &cha1 = cha;
	wchar_t wcha = L'A';//41 00
	wchar_t &wcha1 = wcha;
	short shor = 1;//01 00
	short &shor1 = shor;
	int in = 1;//01 00 00 00
	int &in1 = in;
	float floa = 1.0;//00 00 80 3f
	float &floa1 = floa;

	double doub = 1.0;//00 00 00 00 00 00 f0 3f
	double &doub1 = doub;
	//z22
	int a=3, b=2;
	
	int (*func)(int, int) = proverka;
	
	std::cout <<func(a, b) <<std::endl;
	func = proverka1;
	std::cout << func(a, b);
	return 0;
}                                                                                                                                                                                                                                                                 