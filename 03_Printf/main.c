#include "ft_printf.h"

int main()
{
	ft_printf("%f", 0.1);
	return (0);
}

// int main() {

// 	//No Speicifiers Tests
// 	ft_printf("hello, world!");
// 	ft_printf("");
// 	ft_printf("\t\n\r\v\f\n");
// 	ft_printf("hello");
// 	ft_printf("world");
// 	ft_printf("he");
// 	ft_printf(" is alive");
// 	//%% Tests
// 	ft_printf("%%");
// 	ft_printf("%5%");
// 	ft_printf("%-5%");
// 	ft_printf("%05%");
// 	ft_printf("%-05%");
// 	//Null specifier tests
// 	ft_printf("%");
// 	ft_printf("%5");
// 	ft_printf("%05");
// 	ft_printf("%-05");
// 	ft_printf("%-5");
// 	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
// 	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
// 	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
// 	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
// 	ft_printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
// 	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
// 	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','?');
// 	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
// 	ft_printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
// 	ft_printf("%c", '\0');
// 	ft_printf("%5c", '\0');
// 	ft_printf("%-5c", '\0');
// //%s STRING TESTS
// 	ft_printf("hello, %s.", "gavin");
// 	ft_printf("%s", "testing testing");
// 	ft_printf("%s%s", "hello", "world");
// 	ft_printf("..%s stuff %s", "a", "b");
// 	ft_printf("this %s is empty", "");
// 	ft_printf("this %s is %s", "hello", "");
// 	ft_printf("this %s is %s", "", "hello");
// 	ft_printf("%s%s%s", "1", "2", "3's a charm");
// //String specifiers with field_width, space- or zero-padded
// 	ft_printf("%32s", "abc");
// 	ft_printf("%16s", "nark nark");
// 	ft_printf("%5s", "goes over");
// //String specifiers with field_width, space- or zero-padded, left-justified
// 	ft_printf("%-32s", "abc");
// 	ft_printf("%-16s", "nark nark");
// 	ft_printf("%-5s", "goes over");
// //String specifiers with precision
// 	ft_printf("%.7s", "hello");
// 	ft_printf("%.3s", "hello");
// 	ft_printf("%.s", "hello");
// 	ft_printf("%.0s", "hello");
// 	ft_printf("%.3s%.2s", "holla", "bitch");
// 	ft_printf("%.2s%.7s", "hello", "world");
// 	ft_printf("%.7s%.2s", "hello", "world");
// 	ft_printf("%.5s%7s", "yo", "boi");
// //String specifiers with both precision and field width
// 	ft_printf("%7.5s", "yolo");
// 	ft_printf("%7.5s", "bombastic");
// 	ft_printf("%-7.5s", "yolo");
// 	ft_printf("%-7.5s", "tubular");
// 	ft_printf("%7.7s%7.7s", "hello", "world");
// 	ft_printf("%3.7s%7.7s", "hello", "world");
// 	ft_printf("%7.7s%3.7s", "hello", "world");
// 	ft_printf("%3.7s%3.7s", "hello", "world");
// 	ft_printf("%7.3s%7.7s", "hello", "world");
// 	ft_printf("%3.3s%7.7s", "hello", "world");
// 	ft_printf("%7.3s%3.7s", "hello", "world");
// 	ft_printf("%3.3s%3.7s", "hello", "world");
// 	ft_printf("%7.7s%7.3s", "hello", "world");
// 	ft_printf("%3.7s%7.3s", "hello", "world");
// 	ft_printf("%7.7s%3.3s", "hello", "world");
// 	ft_printf("%3.7s%3.3s", "hello", "world");
// 	ft_printf("%7.3s%7.3s", "hello", "world");
// 	ft_printf("%3.3s%7.3s", "hello", "world");
// 	ft_printf("%7.3s%3.3s", "hello", "world");
// 	ft_printf("%3.3s%3.3s", "hello", "world");
// 	ft_printf("%3s%3s", "hello", "world");
// 	//String specifiers, other tests
// 	ft_printf("%-7s%5s", "hello", "world");
// 	ft_printf("%7s%-5s", "hello", "world");
// 	//String specifiers - NULL strings
// 	ft_printf("hello, %s.", NULL);
// 	ft_printf("%s", NULL);
// 	ft_printf("%32s", NULL);
// 	ft_printf("%2s", NULL);
// 	ft_printf("%-32s", NULL);
// 	ft_printf("%-16s", NULL);
// 	ft_printf("%-3s", NULL);
// //String specifiers with precision
// 	ft_printf("%.9s", "NULL");
// 	ft_printf("%.3s", "NULL");
// 	ft_printf("%.s", "NULL");
// 	ft_printf("%.0s", "NULL");
// //String s_hidden tests
// static char *s_hidden = "hi low\0don't print me lol\0";
// 	ft_printf("%s", s_hidden);
// // width pad
// 	ft_printf("%3s", s_hidden);
// 	ft_printf("%9s", s_hidden);
// // precision no width
// 	ft_printf("%.s", s_hidden);
// 	ft_printf("%.9s", s_hidden);
// // precision  0 before number
// 	ft_printf("%.03s", s_hidden);
// 	ft_printf("%.09s", s_hidden);
// 	ft_printf("%.03s", NULL);
// 	ft_printf("%.09s", NULL);
// 	ft_printf("%.00s", "\0");
// 	ft_printf("%.01s", "\0");
// 	ft_printf("%.03s", "\0");
// 	ft_printf("%.09s", "\0");
// // width  no precision
// 	ft_printf("%3.s", s_hidden);
// 	ft_printf("%10.s", s_hidden);
// 	ft_printf("%3.s", NULL);
// 	ft_printf("%10.s", NULL);
// 	ft_printf("%1.s", "\0");
// 	ft_printf("%2.s", "\0");
// 	ft_printf("%9.s", "\0");
// // lj flag width  no precision
// 	ft_printf("%-3.s", s_hidden);
// 	ft_printf("%-8.s", s_hidden);
// 	ft_printf("%-3.s", NULL);
// 	ft_printf("%-8.s", NULL);
// 	ft_printf("%-1.s", "\0");
// 	ft_printf("%-2.s", "\0");
// 	ft_printf("%-6.s", "\0");
// // width  precision 1
// 	ft_printf("%3.1s", s_hidden);
// 	ft_printf("%10.1s", s_hidden);
// 	ft_printf("%3.1s", NULL);
// 	ft_printf("%9.1s", NULL);
// // lj flag width  precision 1
// 	ft_printf("%-3.1s", s_hidden);
// 	ft_printf("%-10.1s", s_hidden);
// 	ft_printf("%-3.1s", NULL);
// 	ft_printf("%-9.1s", NULL);
// 	ft_printf("%-3.1s", "\0");
// 	ft_printf("%-6.1s", "\0");
// // width  exact precision
// 	ft_printf("%3.6s", s_hidden);
// 	ft_printf("%20.6s", s_hidden);
// 	ft_printf("%3.6s", NULL);
// 	ft_printf("%20.6s", NULL);
// 	ft_printf("%3.6s", "\0");
// 	ft_printf("%6.6s", "\0");
// // lj flag width exact precision
// 	ft_printf("%-3.6s", s_hidden);
// 	ft_printf("%-20.6s", s_hidden);
// // lj flag width excess precision
// 	ft_printf("%-3.8s", s_hidden);
// 	ft_printf("%-10.8s", s_hidden);
// 	ft_printf("%-3.8s", NULL);
// 	ft_printf("%-10.8s", NULL);
// // decoy lj flag
//    	ft_printf("%-.00s", s_hidden);
//    	ft_printf("%-.09s", s_hidden);
// // multiple flags diff order same width and precision
// 	 ft_printf("%+- 06.06s", s_hidden);
// 	 ft_printf("% 0+-6.06s", s_hidden);
// 	 ft_printf("%0 +-6.06s", s_hidden);
// 	 ft_printf("%+-0 6.06s", s_hidden);
// 	 ft_printf("%-+ 06.06s", s_hidden);
// 	 ft_printf("% -+06.06s", s_hidden);
//  // multiple flags diff order width > precision
// 	 ft_printf("%+- 07.06s", s_hidden);
// 	 ft_printf("% 0+-8.06s", s_hidden);
// 	 ft_printf("%0 +-9.06s", s_hidden);
// 	 ft_printf("%+-0 10.06s", s_hidden);
// 	 ft_printf("%-+ 011.06s", s_hidden);
// 	 ft_printf("% -+012.06s", s_hidden);
// // multiple flags diff order width > precision, truncated string
// 	 ft_printf("%+- 06.04s", s_hidden);
// 	 ft_printf("% 0+-6.04s", s_hidden);
// 	 ft_printf("%0 +-6.04s", s_hidden);
// 	 ft_printf("%+-0 6.04s", s_hidden);
// 	 ft_printf("%-+ 06.04s", s_hidden);
// 	 ft_printf("% 0-+6.04s", s_hidden);
// // multiple flags diff order width < precision, excess precision
// 	 ft_printf("%+- 06.09s", s_hidden);
// 	 ft_printf("% 0+-6.09s", s_hidden);
// 	 ft_printf("%0 +-6.09s", s_hidden);
// 	 ft_printf("%+-0 6.09s", s_hidden);
// 	 ft_printf("%-+ 06.09s", s_hidden);
// 	 ft_printf("% 0-+6.09s", s_hidden);
//  // multi zeros
// 	 ft_printf("%00s", s_hidden);
// 	 ft_printf("%000s", s_hidden);
// 	 ft_printf("%0000s", s_hidden);
// 	 ft_printf("%-00s", s_hidden);
// 	 ft_printf("%0-0s", s_hidden);
// 	 ft_printf("%00-s", s_hidden);
// // zero and width
// 	 ft_printf("%03s", s_hidden);
// 	 ft_printf("%09s", s_hidden);
// // as and zero flags  width
// 	 ft_printf("%+03s", s_hidden);
// 	 ft_printf("%+09s", s_hidden);
//  // flag cancelling
// 	 ft_printf("%-03s", s_hidden);
// 	 ft_printf("%-09s", s_hidden);
// 	 ft_printf("%+ 3s", s_hidden);
// 	 ft_printf("%+ 6s", s_hidden);
// /* -----------------------------------------------------------------------------
// **                                              %p POINTERS TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Pointers - Basic
// static char     a01;
// static unsigned char a02;
// static short a03;
// static unsigned short a04;
// static int a05;
// static unsigned int a06;
// static long a07;
// static unsigned long a08;
// static long long a09;
// static unsigned long long a10;
// static char *a11;
// static void *a12;
// 	ft_printf("%p", NULL);

// 	 ft_printf("%9.2p\n", 1234);
// 	 ft_printf("%2.9p\n", 1234);
// 	 ft_printf("%.5p", 0);
// 	 ft_printf("%.0p", 0);
// 	ft_printf("%5p", 0);
// 	ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
//    	ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
//    	ft_printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
// 	ft_printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

// /* -----------------------------------------------------------------------------
// **                                              %d INTEGER TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Signed integers - no modifers
//    	ft_printf("this %d number", 17);
// 	ft_printf("this %d number", -267);
// 	ft_printf("this %d number", 0);
//    	ft_printf("%d", 3);
// 	ft_printf("%d", -1);
// 	ft_printf("%d", 0);
//    	ft_printf("%d",  2147483647);
//    	ft_printf("%d", (int)(-2147483678));
// //Signed integers with field width
// 	ft_printf("%7d", 33);
// 	ft_printf("%7d", -14);
// 	ft_printf("%3d", 0);
// 	ft_printf("%5d", 52625);
// 	ft_printf("%5d", -2562);
// 	ft_printf("%4d", 94827);
// 	ft_printf("%4d", -2464);
// 	ft_printf("%-7d", 33);
//    	ft_printf("%-7d", -14);
// 	ft_printf("%-3d", 0);
// 	ft_printf("%-5d", 52625);
// 	ft_printf("%-5d", -2562);
// 	ft_printf("%-4d", 94827);
//    	ft_printf("%-4d", -2464);
// //signed integers with precision
// 	ft_printf("%.5d", 2);
//    	ft_printf("%.6d", -3);
// 	ft_printf("%.3d", 0);
//    	ft_printf("%.4d", 5263);
//    	ft_printf("%.4d", -2372);
// 	ft_printf("%.3d", 13862);
// 	ft_printf("%.3d",-23646);
// //Signed integers with zero field width padding
//    	ft_printf("%05d", 43);
// 	ft_printf("%07d", -54);
// 	ft_printf("%03d", 0);
// 	ft_printf("%03d", 634);
// 	ft_printf("%04d", -532);
// 	ft_printf("%04d", -4825);
// //Signed integers with field width and precision
// 	ft_printf("%8.5d", 34);
// 	ft_printf("%10.5d", -216);
// 	ft_printf("%8.5d", 0);
// 	ft_printf("%8.3d", 8375);
//    	ft_printf("%8.3d", -8473);
// 	ft_printf("%3.7d", 3267);
//    	ft_printf("%3.7d", -2375);
//    	ft_printf("%3.3d", 6983);
//    	ft_printf("%3.3d", -8462);
// //Signed integers with field width and precision, left-justified
// 	ft_printf("%-8.5d", 34);
// 	ft_printf("%-10.5d", -216);
//    	ft_printf("%-8.5d", 0);
//    	ft_printf("%-8.3d", 8375);
//    	ft_printf("%-8.3d", -8473);
//    	ft_printf("%-3.7d", 3267);
//    	ft_printf("%-3.7d", -2375);
//    	ft_printf("%-3.3d", 6983);
//    	ft_printf("%-3.3d", -8462);
// //Signed integers with field width and precision with zeropadding
//    	ft_printf("%08.5d", 34);
//    	ft_printf("%010.5d", -216);
//    	ft_printf("%08.5d", 0);
//    	ft_printf("%08.3d", 8375);
//    	ft_printf("%08.3d", -8473);
//    	ft_printf("%03.7d", 3267);
//    	ft_printf("%03.7d", -2375);
//    	ft_printf("%03.3d", 6983);
//    	ft_printf("%03.3d", -8462);
// //Signed integers with field width and precision, left-justified with zeropadding
//    	ft_printf("%0-8.5d", 34);
//    	ft_printf("%0-10.5d", -216);
//    	ft_printf("%0-8.5d", 0);
//    	ft_printf("%0-8.3d", 8375);
//    	ft_printf("%0-8.3d", -8473);
//    	ft_printf("%0-3.7d", 3267);
//    	ft_printf("%0-3.7d", -2375);
//    	ft_printf("%0-3.3d", 6983);
//    	ft_printf("%0-3.3d", -8462);
// //Signed integers - zero precision zero value
//    	ft_printf("%.0d", 0);
//    	ft_printf("%.d", 0);
//    	ft_printf("%5.0d", 0);
//    	ft_printf("%5.d", 0);
//    	ft_printf("%-5.0d", 0);
//    	ft_printf("%-5.d", 0);
// /* -----------------------------------------------------------------------------
// **                                              %i INTEGER TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Signed integers - no modifers
//    	ft_printf("this %i number", 17);
//    	ft_printf("this %i number", -267);
//    	ft_printf("this %i number", 0);
//    	ft_printf("%i", 3);
//    	ft_printf("%i", -1);
//    	ft_printf("%i", 0);
//    	ft_printf("%i",  2147483647);
//    	ft_printf("%i", (int)(-2147483678));
// //Signed integers  field width
//    	ft_printf("%7i", 33);
// 	ft_printf("%3i", 0);
//    	ft_printf("%5i", 52625);
//    	ft_printf("%5i", -2562);
//    	ft_printf("%4i", 94827);
//    	ft_printf("%4i", -2464);
//    	ft_printf("%-7i", 33);
//    	ft_printf("%-7i", -14);
//    	ft_printf("%-3i", 0);
//    	ft_printf("%-5i", 52625);
// 	ft_printf("%-5i", -2562);
//    	ft_printf("%-4i", 94827);
//    	ft_printf("%-4i", -2464);
// //signed integers with precision
//    	ft_printf("%.5i", 2);
//    	ft_printf("%.6i", -3);
//    	ft_printf("%.3i", 0);
//    	ft_printf("%.4i", 5263);
//    	ft_printf("%.4i", -2372);
// 	ft_printf("%.3i", 13862);
// 	ft_printf("%.3i",-23646);
// //Signed integers with zero field width padding
//    	ft_printf("%05i", 43);
// 	ft_printf("%07i", -54);
//    	ft_printf("%03i", 0);
//    	ft_printf("%03i", 634);
//    	ft_printf("%04i", -532);
//    	ft_printf("%04i", -4825);
// //Signed integers with field width and precision
//    	ft_printf("%8.5i", 34);
// 	ft_printf("%10.5i", -216);
//    	ft_printf("%8.5i", 0);
//    	ft_printf("%8.3i", 8375);
//    	ft_printf("%8.3i", -8473);
//    	ft_printf("%3.7i", 3267);
//    	ft_printf("%3.7i", -2375);
//    	ft_printf("%3.3i", 6983);
//    	ft_printf("%3.3i", -8462);
// //Signed integers with field width and precision, left-justified
// 	ft_printf("%-8.5i", 34);
//    	ft_printf("%-10.5i", -216);
//    	ft_printf("%-8.5i", 0);
// 	ft_printf("%-8.3i", 8375);
// 	ft_printf("%-8.3i", -8473);
// 	ft_printf("%-3.7i", 3267);
// 	ft_printf("%-3.7i", -2375);
// 	ft_printf("%-3.3i", 6983);
// 	ft_printf("%-3.3i", -8462);
// //Signed integers with field width and precision with zeropadding
//    	ft_printf("%08.5i", 34);
// 	ft_printf("%010.5i", -216);
// 	ft_printf("%08.5i", 0);
// 	ft_printf("%08.3i", 8375);
// 	ft_printf("%08.3i", -8473);
// 	ft_printf("%03.7i", 3267);
// 	ft_printf("%03.7i", -2375);
// 	ft_printf("%03.3i", 6983);
// 	ft_printf("%03.3i", -8462);
// //Signed integers with field width and precision, left-justified with zeropadding
// 	ft_printf("%0-8.5i", 34);
// 	ft_printf("%0-10.5i", -216);
// 	ft_printf("%0-8.5i", 0);
// 	ft_printf("%0-8.3i", 8375);
// 	ft_printf("%0-8.3i", -8473);
// 	ft_printf("%0-3.7i", 3267);
// 	ft_printf("%0-3.7i", -2375);
// 	ft_printf("%0-3.3i", 6983);
// 	ft_printf("%0-3.3i", -8462);
// //Signed integers - zero precision zero value
// 	ft_printf("%.0i", 0);
// 	ft_printf("%.i", 0);
// 	ft_printf("%5.0i", 0);
// 	ft_printf("%5.i", 0);
// 	ft_printf("%-5.0i", 0);
// 	ft_printf("%-5.i", 0);
// /* -----------------------------------------------------------------------------
// **                                              %u UNSIGNED INTEGERS TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Unsigned integers - no modifers
// 	ft_printf("this %u number", 17);
// 	ft_printf("this %u number", 0);
// 	ft_printf("%u", 3);
// 	ft_printf("%u", 4294967295u);
// //Unsigned integers with field width
// 	ft_printf("%7u", 33);
// 	ft_printf("%3u", 0);
//    	ft_printf("%5u", 52625);
//    	ft_printf("%4u", 94827);
//    	ft_printf("%-7u", 33);
//    	ft_printf("%-3u", 0);
//    	ft_printf("%-5u", 52625);
//    	ft_printf("%-4u", 94827);
// //unsigned integers with precision
//    	ft_printf("%.5u", 2);
// 	ft_printf("%.3u", 0);
//    	ft_printf("%.4u", 5263);
//    	ft_printf("%.3u", 13862);
// //Unsigned integers with zero field width padding
//    	ft_printf("%05u", 43);
//    	ft_printf("%03u", 0);
//    	ft_printf("%03u", 634);
// //Unsigned integers with field width and precision
//    	ft_printf("%8.5u", 34);
// 	ft_printf("%8.5u", 0);
//    	ft_printf("%8.3u", 8375);
//    	ft_printf("%3.7u", 3267);
//    	ft_printf("%3.3u", 6983);
// //Unsigned integers with field width and precision, left-justified
//    	ft_printf("%-8.5u", 34);
//    	ft_printf("%-8.5u", 0);
//    	ft_printf("%-8.3u", 8375);
//    	ft_printf("%-3.7u", 3267);
//    	ft_printf("%-3.3u", 6983);
// //Unsigned integers with field width and precision with zeropadding
// 	ft_printf("%08.5u", 34);
//    	ft_printf("%08.5u", 0);
// 	ft_printf("%08.3u", 8375);
// 	ft_printf("%03.7u", 3267);
// 	ft_printf("%03.3u", 6983);
// //Unsigned integers with field width and precision, left-justified with zeropadding
//    	ft_printf("%0-8.5u", 34);
//    	ft_printf("%0-8.5u", 0);
//    	ft_printf("%0-8.3u", 8375);
//    	ft_printf("%0-3.7u", 3267);
//    	ft_printf("%0-3.3u", 6983);
// //Unsigned integers - zero precision zero value
// 	ft_printf("%.0u", 0);
//    	ft_printf("%.u", 0);
//    	ft_printf("%5.0u", 0);
//    	ft_printf("%5.u", 0);
//    	ft_printf("%-5.0u", 0);
//    	ft_printf("%-5.u", 0);
// // /* -----------------------------------------------------------------------------
// // **                                              %x HEXADECIMAL LOWERS TESTS (MANDATORY)
// // ** ---------------------------------------------------------------------------*/
// //Hexadecimal lowers - no modifers
//    	ft_printf("this %x number", 17);
// 	ft_printf("this %x number", 0);
// 	ft_printf("%x", 3);
//    	ft_printf("%x", 4294967295u);
// //Hexadecimal lowers with field width
// 	ft_printf("%7x", 33);
//    	ft_printf("%3x", 0);
//    	ft_printf("%5x", 52625);
//    	ft_printf("%2x", 94827);
// 	ft_printf("%-7x", 33);
// 	ft_printf("%-3x", 0);
//    	ft_printf("%-5x", 52625);
//    	ft_printf("%-4x", 9648627);
// //Hexadecimal lowers with precision
// 	ft_printf("%.5x", 21);
//    	ft_printf("%.3x", 0);
//    	ft_printf("%.4x", 5263);
//    	ft_printf("%.3x", 938862);
// //Hexadecimal lowers with zero
// //field width padding
// 	ft_printf("%05x", 43);
// 	ft_printf("%03x", 0);
//    	ft_printf("%03x", 698334);
// //Hexadecimal lowers with field width and precision
//    	ft_printf("%8.5x", 34);
// 	ft_printf("%8.5x", 0);
//    	ft_printf("%8.3x", 8375);
//    	ft_printf("%2.7x", 3267);
//    	ft_printf("%3.3x", 6983);
// //Hexadecimal lowers with field width and precision, left-justified
// 	ft_printf("%-8.5x", 34);
//    	ft_printf("%-8.5x", 0);
//    	ft_printf("%-8.3x", 8375);
//    	ft_printf("%-2.7x", 3267);
//    	ft_printf("%-3.3x", 6983);
// //Hexadecimal lowers with field width and precis
// //ion with zeropadding
//    	ft_printf("%08.5x", 34);
//    	ft_printf("%08.5x", 0);
//    	ft_printf("%08.3x", 8375);
//    	ft_printf("%02.7x", 3267);
//    	ft_printf("%03.3x", 6983);
// //Hexadecimal lowers with field width and precision, left-justified with zeropadding
//    	ft_printf("%0-8.5x", 34);
// 	ft_printf("%0-8.5x", 0);
//    	ft_printf("%0-8.3x", 8375);
//    	ft_printf("%0-2.7x", 3267);
//    	ft_printf("%0-3.3x", 6983);
// //Hexadecimal lower - zero precision zero value
//    	ft_printf("%.0x", 0);
// ft_printf("%.x", 0);
// ft_printf("%5.0x", 0);
// ft_printf("%5.x", 0);
// ft_printf("%-5.0x", 0);
// ft_printf("%-5.x", 0);
// /* -----------------------------------------------------------------------------
// **                                              %X HEXADECIMAL UPPERS TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Hexadecimal uppers - no modifers
// ft_printf("this %X number", 17);
// ft_printf("this %X number", 0);
// ft_printf("%X", 3);
// ft_printf("%X", 4294967295u);
// //Hexadecimal uppers with field width
// ft_printf("%7X", 33);
// ft_printf("%3X", 0);
// ft_printf("%5X", 52625);
// ft_printf("%2X", 94827);
// ft_printf("%-7X", 33);
// ft_printf("%-3X", 0);
// ft_printf("%-5X", 52625);
// ft_printf("%-4X", 9648627);
// //Hexadecimal uppers with precision
// ft_printf("%.5X", 21);
// ft_printf("%.3X", 0);
// ft_printf("%.4X", 5263);
// ft_printf("%.3X", 938862);
// //Hexadecimal uppers with zero field width padding
// ft_printf("%05X", 43);
// ft_printf("%03X", 0);
// ft_printf("%03X", 698334);
// //Hexadecimal uppers with field width and precision
// ft_printf("%8.5X", 34);
// ft_printf("%8.5X", 0);
// ft_printf("%8.3X", 8375);
// ft_printf("%2.7X", 3267);
// ft_printf("%3.3X", 6983);
// //Hexadecimal uppers with field width and precision, left-justified
// ft_printf("%-8.5X", 34);
// ft_printf("%-8.5X", 0);
// ft_printf("%-8.3X", 8375);
// ft_printf("%-2.7X", 3267);
// ft_printf("%-3.3X", 6983);
// //Hexadecimal uppers with field width and precision with zeropadding
// ft_printf("%08.5X", 34);
// ft_printf("%08.5X", 0);
// ft_printf("%08.3X", 8375);
// ft_printf("%02.7X", 3267);
// ft_printf("%03.3X", 6983);
// //Hexadecimal uppers with field width and precision, left-justified with zeropadding
// ft_printf("%0-8.5X", 34);
// ft_printf("%0-8.5X", 0);
// ft_printf("%0-8.3X", 8375);
// ft_printf("%0-2.7X", 3267);
// ft_printf("%0-3.3X", 6983);
// //Hexadecimal uppers - zero precision zero value
// ft_printf("%.0X", 0);
// ft_printf("%.X", 0);
// ft_printf("%5.0X", 0);
// ft_printf("%5.X", 0);
// ft_printf("%-5.0X", 0);
// ft_printf("%-5.X", 0);
// /* -----------------------------------------------------------------------------
// **                                                      STAR TESTS (MANDATORY)
// ** ---------------------------------------------------------------------------*/
// //Taken from https://github.com/cclaude42/PFT_2019
// ft_printf("%*s", 32, "abc");
// ft_printf("%-*s", 32, "abc");
// ft_printf("%*s", 3, "hello");
// ft_printf("%.*s", 3, "hello");
// ft_printf("%.*s", 0, "hello");
// ft_printf("%-*.*s", 7, 3, "yolo");
// ft_printf("%*i", 4, 94827);
// ft_printf("%*i", 14, 94827);
// ft_printf("%.*i", 6, -3);
// ft_printf("%0*i", 7, -54);
// ft_printf("%*s", -32, "abc");
// ft_printf("%-*s", -32, "abc");
// ft_printf("%*s", -3, "hello");
// ft_printf("%.*s", -3, "hello");
// ft_printf("%-*.*s", -7, -3, "yolo");
// ft_printf("%*i", -4, 94827);
// ft_printf("%*i", -14, 94827);
// ft_printf("%.*i", -6, -3);
// ft_printf("%0*i", -7, -54);
// /* -----------------------------------------------------------------------------
// **                                                      MOULINETTE TESTS - MANDATORY
// ** ---------------------------------------------------------------------------*/

// ft_printf("%c", 42);
// ft_printf("Kashim a %c histoires à raconter", 1001);
// ft_printf("Il fait au moins %c\n", -8000);
// ft_printf("%c", -0);
// ft_printf("%c", 0);
// ft_printf("%c\n", 'c');
// ft_printf("%c\n", '\n');
// ft_printf("%c", 'l');
// ft_printf("%c", 'y');
// ft_printf("%c", ' ');
// ft_printf("%c", 'e');
// ft_printf("%c", 's');
// ft_printf("%c", 't');
// ft_printf("%c", ' ');
// ft_printf("%c", 'f');
// ft_printf("%c", 'a');
// ft_printf("%c", 'n');
// ft_printf("%c", 't');
// ft_printf("%c", 'a');
// ft_printf("%c", 's');
// ft_printf("%c", 't');
// ft_printf("%c", 'i');
// ft_printf("%c", 'q');
// ft_printf("%c", 'u');
// ft_printf("%c", 'e');
// ft_printf("%c\n", '!');
// ft_printf("%c\n", '\r');
// ft_printf("%c\n", '\t');

// ft_printf(" pouet %s !!", "camembert");
// ft_printf("%s !", "Ceci n'est pas un \0 exercice !");
// ft_printf("%s!", "Ceci n'est toujours pas un exercice !");
// ft_printf("%s",
//                 "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaissparaissepourtoujourstexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
// ft_printf("%d", 42);
// ft_printf("Kashim a %d histoires à raconter", 1001);
// ft_printf("Il fait au moins %d\n", -8000);
// ft_printf("%d", -0);
// ft_printf("%d", 0);
// ft_printf("%%d 0000042 == |%d|\n", 0000042);
// ft_printf("%%d \t == |%d|\n", '\t');
// ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

// ft_printf("%i", 42);
// ft_printf("Kashim a %i histoires à raconter", 1001);
// ft_printf("Il fait au moins %i\n", -8000);
// ft_printf("%i", -0);
// ft_printf("%i", 0);
// ft_printf("%%i 0000042 == |%i|\n", 0000042);
// ft_printf("%%i \t == |%i|\n", '\t');
// ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
// ft_printf("%u", 42);
// ft_printf("Kashim a %u histoires à raconter", 1001);
// ft_printf("Il fait au moins %u\n", -8000);
// ft_printf("%u", -0);
// ft_printf("%u", 0);
// ft_printf("%%u 0000042 == |%u|\n", 0000042);
// ft_printf("%%u \t == |%u|\n", '\t');
// ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

// ft_printf("%x", 42);
// ft_printf("Kashim a %x histoires à raconter", 1001);
// ft_printf("Il fait au moins %x\n", -8000);
// ft_printf("%x", -0);
// ft_printf("%x", 0);
// ft_printf("%%x 0000042 == |%x|\n", 0000042);
// ft_printf("%%x \t == |%x|\n", '\t');
// ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

// ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
// ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
// ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
// ft_printf("%%04.2i 42 == |%04.2i|\n", 42);

// ft_printf("%%04i 42 == |%04i|\n", 42);
// ft_printf("%%05i 42 == |%05i|\n", 42);
// ft_printf("%%0i 42 == |%0i|\n", 42);
// ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

// ft_printf("%%-i 42 == %-i\n", 42);
// ft_printf("%%-i -42 == %-i\n", -42);
// ft_printf("%%-4d 42 == |%-4d|\n", 42);
// ft_printf("%%-5d -42 == |%-5d|\n", -42);
// ft_printf("|%3i|%-3i|\n", 42, 42);
// ft_printf("%%-4i 42 == |%-4i|\n", 42);
// ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
// ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
// ft_printf("%%*i 42 == |%*i|\n", 5, 42);
// ft_printf("%%*i 42 == |%*i|\n", 3, 42);
// ft_printf("%%*i 42 == |%*i|\n", 2, 42);
// /* -----------------------------------------------------------------------------
// **                                                      MIXED TESTS - MANDATORY
// ** ---------------------------------------------------------------------------*/
// //Mix tests
// static unsigned int             mx_u = 235;
// static char                             mx_c = 'G';
// static char                        *mx_s = "Hello, World!";
// static int                              mx_i = 42;

// ft_printf(
//                         "  %u    %%    %p    %x    %s    %i  ",
//                         mx_u, &mx_i, mx_u, mx_s, mx_i);
// ft_printf(
//                         "  %x    %c    %X    %s    %u    %p  ",
//                         mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);
// ft_printf(
//                         "  %%    %i    %X    %p    %c    %s  ",
//                         mx_i, mx_u, &mx_i, mx_c, mx_s);
// ft_printf(
//                         "  %u    %%    %s    %c    %x    %X  ",
//                         mx_u, mx_s, mx_c, mx_u, mx_u);
// ft_printf(
//                         "  %i    %c    %x    %u    %%    %X  ",
//                         mx_i, mx_c, mx_u, mx_u, mx_u);
// ft_printf(
//                         "  %c    %X    %i    %%    %s    %p  ",
//                         mx_c, mx_u, mx_i, mx_s, &mx_i);
// ft_printf(
//                         "  %p    %x    %i    %c    %s    %u  ",
//                         &mx_i, mx_u, mx_i, mx_c, mx_s, mx_u);
// ft_printf(
//                         "  %i    %s    %%    %u    %c    %x  ",
//                         mx_i, mx_s, mx_u, mx_c, mx_u);
// ft_printf(
//                         "  %X    %p    %s    %%    %u    %x  ",
//                         mx_u, &mx_i, mx_s, mx_u, mx_u);
// ft_printf(
//                         "  %c    %%    %u    %i    %x    %X  ",
//                         mx_c, mx_u, mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %i    %p    %X    %u    %s    %x  ",
//                         mx_i, &mx_i, mx_u, mx_u, mx_s, mx_u);
// ft_printf(
//                         "  %X    %c    %p    %x    %i    %u  ",
//                         mx_u, mx_c, &mx_i, mx_u, mx_i, mx_u);
// ft_printf(
//                         "  %%    %i    %u    %s    %c    %X  ",
//                         mx_i, mx_u, mx_s, mx_c, mx_u);
// ft_printf(
//                         "  %u    %c    %x    %s    %X    %i  ",
//                         mx_u, mx_c, mx_u, mx_s, mx_u, mx_i);
// ft_printf(
//                         "  %s    %p    %X    %c    %i    %x  ",
//                         mx_s, &mx_i, mx_u, mx_c, mx_i, mx_u);
// ft_printf(
//                         "  %u    %c    %X    %x    %p    %s  ",
//                         mx_u, mx_c, mx_u, mx_u, &mx_i, mx_s);
// ft_printf(
//                         "  %c    %%    %i    %X    %u    %x  ",
//                         mx_c, mx_i, mx_u, mx_u, mx_u);
// ft_printf(
//                         "  %s    %%    %x    %X    %c    %u  ",
//                         mx_s, mx_u, mx_u, mx_c, mx_u);
// ft_printf(
//                         "  %x    %s    %X    %%    %p    %i  ",
//                         mx_u, mx_s, mx_u, &mx_i, mx_i);
// ft_printf(
//                         "  %%    %p    %i    %c    %x    %X  ",
//                         &mx_i, mx_i, mx_c, mx_u, mx_u);
// ft_printf(
//                         "  %c    %s    %%    %u    %p    %x  ",
//                         mx_c, mx_s, mx_u, &mx_i, mx_u);
// ft_printf(
//                         "  %c    %i    %u    %s    %p    %x  ",
//                         mx_c, mx_i, mx_u, mx_s, &mx_i, mx_u);
// ft_printf(
//                         "  %X    %x    %s    %c    %i    %u  ",
//                         mx_u, mx_u, mx_s, mx_c, mx_i, mx_u);
// ft_printf(
//                         "  %x    %c    %X    %p    %s    %p  ",
//                         mx_u, mx_c, mx_u, &mx_i, mx_s, &mx_i);
// ft_printf(
//                         "  %X    %%    %i    %s    %p    %x  ",
//                         mx_u, mx_i, mx_s, &mx_i, mx_u);
// ft_printf(
//                         "  %i    %p    %x    %c    %X    %p  ",
//                         mx_i, &mx_i, mx_u, mx_c, mx_u, &mx_i);
// ft_printf(
//                         "  %X    %c    %i    %u    %x    %p  ",
//                         mx_u, mx_c, mx_i, mx_u, mx_u, &mx_i);
// ft_printf(
//                         "  %i    %u    %c    %%    %X    %p  ",
//                         mx_i, mx_u, mx_c, mx_u, &mx_i);
// ft_printf(
//                         "  %s    %i    %c    %p    %x    %u  ",
//                         mx_s, mx_i, mx_c, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %p    %%    %x    %X    %i    %c  ",
//                         &mx_i, mx_u, mx_u, mx_i, mx_c);
// ft_printf(
//                         "  %X    %i    %s    %%    %u    %p  ",
//                         mx_u, mx_i, mx_s, mx_u, &mx_i);
// ft_printf(
//                         "  %%    %u    %p    %i    %X    %c  ",
//                         mx_u, &mx_i, mx_i, mx_u, mx_c);
// ft_printf(
//                         "  %x    %X    %p    %s    %i    %c  ",
//                         mx_u, mx_u, &mx_i, mx_s, mx_i, mx_c);
// ft_printf(
//                         "  %c    %%    %s    %X    %x    %p  ",
//                         mx_c, mx_s, mx_u, mx_u, &mx_i);
// ft_printf(
//                         "  %x    %X    %p    %s    %i    %u  ",
//                         mx_u, mx_u, &mx_i, mx_s, mx_i, mx_u);
// ft_printf(
//                         "  %p    %u    %s    %X    %c    %p  ",
//                         &mx_i, mx_u, mx_s, mx_u, mx_c, &mx_i);
// ft_printf(
//                         "  %X    %s    %x    %p    %%    %i  ",
//                         mx_u, mx_s, mx_u, &mx_i, mx_i);
// ft_printf(
//                         "  %x    %s    %%    %p    %i    %c  ",
//                         mx_u, mx_s, &mx_i, mx_i, mx_c);
// ft_printf(
//                         "  %s    %u    %x    %%    %i    %c  ",
//                         mx_s, mx_u, mx_u, mx_i, mx_c);
// ft_printf(
//                         "  %p    %i    %x    %%    %u    %X  ",
//                         &mx_i, mx_i, mx_u, mx_u, mx_u);
// ft_printf(
//                         "  %%    %c    %X    %p    %u    %x  ",
//                         mx_c, mx_u, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %u    %c    %%    %p    %i    %s  ",
//                         mx_u, mx_c, &mx_i, mx_i, mx_s);
// ft_printf(
//                         "  %%    %i    %s    %u    %c    %X  ",
//                         mx_i, mx_s, mx_u, mx_c, mx_u);
// ft_printf(
//                         "  %%    %i    %u    %s    %X    %p  ",
//                         mx_i, mx_u, mx_s, mx_u, &mx_i);
// ft_printf(
//                         "  %s    %c    %X    %%    %i    %p  ",
//                         mx_s, mx_c, mx_u, mx_i, &mx_i);
// ft_printf(
//                         "  %x    %X    %u    %i    %%    %s  ",
//                         mx_u, mx_u, mx_u, mx_i, mx_s);
// ft_printf(
//                         "  %x    %u    %s    %i    %p    %p  ",
//                         mx_u, mx_u, mx_s, mx_i, &mx_i, &mx_i);
// ft_printf(
//                         "  %X    %i    %s    %x    %u    %p  ",
//                         mx_u, mx_i, mx_s, mx_u, mx_u, &mx_i);
// ft_printf(
//                         "  %c    %i    %%    %X    %p    %u  ",
//                         mx_c, mx_i, mx_u, &mx_i, mx_u);
// ft_printf(
//                         "  %s    %u    %i    %X    %%    %c  ",
//                         mx_s, mx_u, mx_i, mx_u, mx_c);
// ft_printf(
//                         "  %%    %p    %X    %i    %s    %x  ",
//                         &mx_i, mx_u, mx_i, mx_s, mx_u);
// ft_printf(
//                         "  %i    %x    %p    %c    %u    %X  ",
//                         mx_i, mx_u, &mx_i, mx_c, mx_u, mx_u);
// ft_printf(
//                         "  %X    %c    %%    %i    %x    %s  ",
//                         mx_u, mx_c, mx_i, mx_u, mx_s);
// ft_printf(
//                         "  %x    %c    %u    %X    %p    %p  ",
//                         mx_u, mx_c, mx_u, mx_u, &mx_i, &mx_i);
// ft_printf(
//                         "  %p    %u    %c    %s    %i    %p  ",
//                         &mx_i, mx_u, mx_c, mx_s, mx_i, &mx_i);
// ft_printf(
//                         "  %x    %p    %s    %u    %%    %c  ",
//                         mx_u, &mx_i, mx_s, mx_u, mx_c);
// ft_printf(
//                         "  %%    %i    %X    %p    %u    %s  ",
//                         mx_i, mx_u, &mx_i, mx_u, mx_s);
// ft_printf(
//                         "  %%    %u    %c    %s    %i    %x  ",
//                         mx_u, mx_c, mx_s, mx_i, mx_u);
// ft_printf(
//                         "  %c    %i    %u    %x    %s    %p  ",
//                         mx_c, mx_i, mx_u, mx_u, mx_s, &mx_i);
// ft_printf(
//                         "  %c    %i    %s    %u    %x    %p  ",
//                         mx_c, mx_i, mx_s, mx_u, mx_u, &mx_i);
// ft_printf(
//                         "  %u    %%    %x    %i    %X    %c  ",
//                         mx_u, mx_u, mx_i, mx_u, mx_c);
// ft_printf(
//                         "  %x    %s    %u    %i    %c    %X  ",
//                         mx_u, mx_s, mx_u, mx_i, mx_c, mx_u);
// ft_printf(
//                         "  %%    %c    %i    %p    %s    %X  ",
//                         mx_c, mx_i, &mx_i, mx_s, mx_u);
// ft_printf(
//                         "  %s    %x    %%    %X    %i    %c  ",
//                         mx_s, mx_u, mx_u, mx_i, mx_c);
// ft_printf(
//                         "  %x    %X    %u    %c    %%    %i  ",
//                         mx_u, mx_u, mx_u, mx_c, mx_i);
// ft_printf(
//                         "  %c    %%    %i    %p    %u    %X  ",
//                         mx_c, mx_i, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %i    %c    %%    %u    %X    %p  ",
//                         mx_i, mx_c, mx_u, mx_u, &mx_i);
// ft_printf(
//                         "  %s    %i    %x    %u    %c    %p  ",
//                         mx_s, mx_i, mx_u, mx_u, mx_c, &mx_i);
// ft_printf(
//                         "  %s    %x    %c    %p    %u    %X  ",
//                         mx_s, mx_u, mx_c, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %%    %s    %p    %i    %X    %c  ",
//                         mx_s, &mx_i, mx_i, mx_u, mx_c);
// ft_printf(
//                         "  %x    %X    %i    %%    %s    %u  ",
//                         mx_u, mx_u, mx_i, mx_s, mx_u);
// ft_printf(
//                         "  %s    %i    %X    %c    %%    %p  ",
//                         mx_s, mx_i, mx_u, mx_c, &mx_i);
// ft_printf(
//                         "  %x    %p    %c    %s    %X    %u  ",
//                         mx_u, &mx_i, mx_c, mx_s, mx_u, mx_u);
// ft_printf(
//                         "  %%    %X    %u    %x    %p    %c  ",
//                         mx_u, mx_u, mx_u, &mx_i, mx_c);
// ft_printf(
//                         "  %p    %c    %s    %u    %i    %x  ",
//                         &mx_i, mx_c, mx_s, mx_u, mx_i, mx_u);
// ft_printf(
//                         "  %i    %c    %%    %p    %u    %x  ",
//                         mx_i, mx_c, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %X    %%    %u    %c    %p    %s  ",
//                         mx_u, mx_u, mx_c, &mx_i, mx_s);
// ft_printf(
//                         "  %X    %i    %c    %u    %p    %s  ",
//                         mx_u, mx_i, mx_c, mx_u, &mx_i, mx_s);
// ft_printf(
//                         "  %p    %%    %c    %X    %u    %i  ",
//                         &mx_i, mx_c, mx_u, mx_u, mx_i);
// ft_printf(
//                         "  %s    %c    %i    %%    %p    %X  ",
//                         mx_s, mx_c, mx_i, &mx_i, mx_u);
// ft_printf(
//                         "  %p    %%    %c    %u    %s    %X  ",
//                         &mx_i, mx_c, mx_u, mx_s, mx_u);
// ft_printf(
//                         "  %x    %c    %%    %s    %X    %i  ",
//                         mx_u, mx_c, mx_s, mx_u, mx_i);
// ft_printf(
//                         "  %%    %c    %i    %X    %s    %x  ",
//                         mx_c, mx_i, mx_u, mx_s, mx_u);
// ft_printf(
//                         "  %i    %X    %%    %c    %u    %s  ",
//                         mx_i, mx_u, mx_c, mx_u, mx_s);
// ft_printf(
//                         "  %p    %x    %c    %s    %u    %p  ",
//                         &mx_i, mx_u, mx_c, mx_s, mx_u, &mx_i);
// ft_printf(
//                         "  %u    %p    %c    %X    %s    %p  ",
//                         mx_u, &mx_i, mx_c, mx_u, mx_s, &mx_i);
// ft_printf(
//                         "  %p    %c    %u    %X    %s    %p  ",
//                         &mx_i, mx_c, mx_u, mx_u, mx_s, &mx_i);
// ft_printf(
//                         "  %i    %u    %X    %p    %c    %p  ",
//                         mx_i, mx_u, mx_u, &mx_i, mx_c, &mx_i);
// ft_printf(
//                         "  %i    %c    %p    %%    %X    %u  ",
//                         mx_i, mx_c, &mx_i, mx_u, mx_u);
// ft_printf(
//                         "  %s    %c    %i    %x    %p    %u  ",
//                         mx_s, mx_c, mx_i, mx_u, &mx_i, mx_u);
// ft_printf(
//                         "  %u    %s    %x    %p    %i    %c  ",
//                         mx_u, mx_s, mx_u, &mx_i, mx_i, mx_c);
// ft_printf(
//                         "  %u    %p    %X    %c    %%    %x  ",
//                         mx_u, &mx_i, mx_u, mx_c, mx_u);
// ft_printf(
//                         "  %c    %p    %X    %x    %%    %s  ",
//                         mx_c, &mx_i, mx_u, mx_u, mx_s);
// ft_printf(
//                         "  %x    %c    %s    %p    %u    %i  ",
//                         mx_u, mx_c, mx_s, &mx_i, mx_u, mx_i);
// ft_printf(
//                         "  %X    %p    %c    %%    %u    %i  ",
//                         mx_u, &mx_i, mx_c, mx_u, mx_i);
// ft_printf(
//                         "  %%    %i    %x    %p    %c    %s  ",
//                         mx_i, mx_u, &mx_i, mx_c, mx_s);
// ft_printf(
//                         "  %X    %p    %c    %s    %i    %u  ",
//                         mx_u, &mx_i, mx_c, mx_s, mx_i, mx_u);
// ft_printf(
//                         "  %u    %i    %p    %x    %s    %X  ",
//                         mx_u, mx_i, &mx_i, mx_u, mx_s, mx_u);
// ft_printf(
//                         "  %i    %s    %%    %p    %X    %c  ",
//                         mx_i, mx_s, &mx_i, mx_u, mx_c);
// ft_printf(
//                         "  %X    %p    %c    %u    %x    %i  ",
//                         mx_u, &mx_i, mx_c, mx_u, mx_u, mx_i);

// //Signed integers with allsign ('+')
// ft_printf("%+d", 5);
// ft_printf("%+d", -7);
// ft_printf("%+d", 2147483647);
// ft_printf("%+.7d", 234);
// ft_printf("%+.7d", -446);
// ft_printf("%+.3d", 3723);
// ft_printf("%+5d", 35);
// ft_printf("%+7d", 0);
// ft_printf("%+24d", 2147483647);
// ft_printf("%+05d", 432);
// ft_printf("%+04d", 0);
//  //Signed integers with field width and precision with allsign
// ft_printf("%+.0d", 0);
// ft_printf("%+.d", 0);
// ft_printf("%+8.5d", 34);
// ft_printf("%+10.5d", -216);
// ft_printf("%+8.5d", 0);
// ft_printf("%+8.3d", 8375);
// ft_printf("%+8.3d", -8473);
// ft_printf("%+3.7d", 3267);
// ft_printf("%+3.7d", -2375);
// ft_printf("%+3.3d", 6983);
// ft_printf("%+3.3d", -8462);
// //Signed integers with field width and precision, left-justified with allsign
// ft_printf("%+-8.5d", 34);
// ft_printf("%+-10.5d", -216);
// ft_printf("%+-8.5d", 0);
// ft_printf("%+-8.3d", 8375);
// ft_printf("%+-8.3d", -8473);
// ft_printf("%+-3.7d", 3267);
// ft_printf("%+-3.7d", -2375);
// ft_printf("%+-3.3d", 6983);
// ft_printf("%+-3.3d", -8462);
// //Signed integers with field width and precision with allsign with zeropadding
// ft_printf("%0+8.5d", 34);
// ft_printf("%0+10.5d", -216);
// ft_printf("%0+8.5d", 0);
// ft_printf("%0+8.3d", 8375);
// ft_printf("%0+8.3d", -8473);
// ft_printf("%0+3.7d", 3267);
// ft_printf("%0+3.7d", -2375);
// ft_printf("%0+3.3d", 6983);
// ft_printf("%0+3.3d", -8462);
// //Signed integers with field width and precision, left-justified with allsign with zeropadding
// ft_printf("%0+-8.5d", 34);
// ft_printf("%0+-10.5d", -216);
// ft_printf("%0+-8.5d", 0);
// ft_printf("%0+-8.3d", 8375);
// ft_printf("%0+-8.3d", -8473);
// ft_printf("%0+-3.7d", 3267);
// ft_printf("%0+-3.7d", -2375);
// ft_printf("%0+-3.3d", 6983);
// ft_printf("%0+-3.3d", -8462);
//  //Signed integers  allsign ('+')
// ft_printf("%+i", 5);
// ft_printf("%+i", -7);
// ft_printf("%+i", 2147483647);
// ft_printf("%+05i", 432);
// ft_printf("%+04i", 0);
// //signed integers  field width and allsign
// ft_printf("%+5i", 35);
// ft_printf("%+7i", 0);
// ft_printf("%+24i", 2147483647);
// //signed integers with precision
// ft_printf("%+.7i", 234);
// ft_printf("%+.7i", -446);
// ft_printf("%+.3i", 3723);
// ft_printf("%+.0i", 0);
// ft_printf("%+.i", 0);
// ft_printf("%+5.0i", 0);
// ft_printf("%+5.i", 0);
// ft_printf("%+-5.0i", 0);
// ft_printf("%+-5.i", 0);
//  //Signed integers with field width and precision with allsign
// ft_printf("%+8.5i", 34);
// ft_printf("%+10.5i", -216);
// ft_printf("%+8.5i", 0);
// ft_printf("%+8.3i", 8375);
// ft_printf("%+8.3i", -8473);
// ft_printf("%+3.7i", 3267);
// ft_printf("%+3.7i", -2375);
// ft_printf("%+3.3i", 6983);
// ft_printf("%+3.3i", -8462);
//  //Signed integers with field width and precision with allsign with zeropadding
// ft_printf("%0+8.5i", 34);
// ft_printf("%0+10.5i", -216);
// ft_printf("%0+8.5i", 0);
// ft_printf("%0+8.3i", 8375);
// ft_printf("%0+8.3i", -8473);
// ft_printf("%0+3.7i", 3267);
// ft_printf("%0+3.7i", -2375);
// ft_printf("%0+3.3i", 6983);
// ft_printf("%0+3.3i", -8462);
//  //Signed integers with field width and precision, left-justified with allsign
// ft_printf("%+-8.5i", 34);
// ft_printf("%+-10.5i", -216);
// ft_printf("%+-8.5i", 0);
// ft_printf("%+-8.3i", 8375);
// ft_printf("%+-8.3i", -8473);
// ft_printf("%+-3.7i", 3267);
// ft_printf("%+-3.7i", -2375);
// ft_printf("%+-3.3i", 6983);
// ft_printf("%+-3.3i", -8462);
//  //Signed integers with field width and precision, left-justified with allsign with zeropadding
// ft_printf("%0+-8.5i", 34);
// ft_printf("%0+-10.5i", -216);
// ft_printf("%0+-8.5i", 0);
// ft_printf("%0+-8.3i", 8375);
// ft_printf("%0+-8.3i", -8473);
// ft_printf("%0+-3.7i", 3267);
// ft_printf("%0+-3.7i", -2375);
// ft_printf("%0+-3.3i", 6983);
// ft_printf("%0+-3.3i", -8462);
//  //nocrash tests adapted from tests contributed by phtruong
// ft_printf("%++d", 42);
// ft_printf("%-+-5d", 42);
// ft_printf("%+c", 'a');
// ft_printf("%+c", -42);
// ft_printf("%+s", "hello");
// ft_printf("%+u", 42);
// ft_printf("%+x", 42);
// ft_printf("%+X", 42);
//  /* -----------------------------------------------------------------------------
// **                                              ' ' FLAG (SPACE) TESTS (BONUS)
// ** ---------------------------------------------------------------------------*/
// //Signed integers - space - no modifers
// ft_printf("this % d number", 17);
// ft_printf("this % d number", -267);
// ft_printf("this % d number", 0);
// ft_printf("% d", 3);
// ft_printf("% d", -1);
// ft_printf("% d", 0);
// ft_printf("this % d number", 17);
// ft_printf("this % d number", -267);
// ft_printf("this % d number", 0);
// ft_printf("% d", 2147483647);
// ft_printf("% d", (int)(-2147483678));
// //Signed integers - space with field width
// ft_printf("% 7d", 33);
// ft_printf("% 7d", -14);
// ft_printf("% 3d", 0);
// ft_printf("% 5d", 52625);
// ft_printf("% 5d", -2562);
// ft_printf("% 4d", 94827);
// ft_printf("% 4d", -2464);
// ft_printf("% -7d", 33);
// ft_printf("% -7d", -14);
// ft_printf("% -3d", 0);
// ft_printf("% -5d", 52625);
// ft_printf("% -5d", -2562);
// ft_printf("% -4d", 94827);
// ft_printf("% -4d", -2464);
//  //signed integers with precision
// ft_printf("% .5d", 2);
// ft_printf("% .6d", -3);
// ft_printf("% .3d", 0);
// ft_printf("% .4d", 5263);
// ft_printf("% .4d", -2372);
// ft_printf("% .3d", 13862);
// ft_printf("% .3d",-23646);
// //Signed integers - space with zero field width padding
// ft_printf("% 05d", 43);
// ft_printf("% 07d", -54);
// ft_printf("% 03d", 0);
// ft_printf("% 03d", 634);
// ft_printf("% 04d", -532);
// ft_printf("% 04d", -4825);
// //Signed integers - space with field width and precision
// ft_printf("% 8.5d", 34);
// ft_printf("% 10.5d", -216);
// ft_printf("% 8.5d", 0);
// ft_printf("% 8.3d", 8375);
// ft_printf("% 8.3d", -8473);
// ft_printf("% 3.7d", 3267);
// ft_printf("% 3.7d", -2375);
// ft_printf("% 3.3d", 6983);
// ft_printf("% 3.3d", -8462);
// //Signed integers - space with field width and precision, left-justified
// ft_printf("% -8.5d", 34);
// ft_printf("% -10.5d", -216);
// ft_printf("% -8.5d", 0);
// ft_printf("% -8.3d", 8375);
// ft_printf("% -8.3d", -8473);
// ft_printf("% -3.7d", 3267);
// ft_printf("% -3.7d", -2375);
// ft_printf("% -3.3d", 6983);
// ft_printf("% -3.3d", -8462);
// //Signed integers - space with field width and precision with zeropadding
// ft_printf("% 08.5d", 34);
// ft_printf("% 010.5d", -216);
// ft_printf("% 08.5d", 0);
// ft_printf("% 08.3d", 8375);
// ft_printf("% 08.3d", -8473);
// ft_printf("% 03.7d", 3267);
// ft_printf("% 03.7d", -2375);
// ft_printf("% 03.3d", 6983);
// ft_printf("% 03.3d", -8462);
//  //Signed integers - space with field width and precision, left-justified with zeropadding
// ft_printf("% 0-8.5d", 34);
// ft_printf("% 0-10.5d", -216);
// ft_printf("% 0-8.5d", 0);
// ft_printf("% 0-8.3d", 8375);
// ft_printf("% 0-8.3d", -8473);
// ft_printf("% 0-3.7d", 3267);
// ft_printf("% 0-3.7d", -2375);
// ft_printf("% 0-3.3d", 6983);
// ft_printf("% 0-3.3d", -8462);
//  //Signed integers - space - no modifers
// ft_printf("this % i number", 17);
// ft_printf("this % i number", -267);
// ft_printf("this % i number", 0);
// ft_printf("% i", 3);
// ft_printf("% i", -1);
// ft_printf("% i", 0);
// ft_printf("this % d number", 17);
// ft_printf("this % d number", -267);
// ft_printf("this % d number", 0);
// ft_printf("% i", 2147483647);
// ft_printf("% i", (int)(-2147483678));
//  //Signed integers - space with field width
// ft_printf("% 7i", 33);
// ft_printf("% 7i", -14);
// ft_printf("% 3i", 0);
// ft_printf("% 5i", 52625);
// ft_printf("% 5i", -2562);
// ft_printf("% 4i", 94827);
// ft_printf("% 4i", -2464);
// ft_printf("% -7i", 33);
// ft_printf("% -7i", -14);
// ft_printf("% -3i", 0);
// ft_printf("% -5i", 52625);
// ft_printf("% -5i", -2562);
// ft_printf("% -4i", 94827);
// ft_printf("% -4i", -2464);
// //signed integers with precision
// ft_printf("% .5i", 2);
// ft_printf("% .6i", -3);
// ft_printf("% .3i", 0);
// ft_printf("% .4i", 5263);
// ft_printf("% .4i", -2372);
// ft_printf("% .3i", 13862);
// ft_printf("% .3i",-23646);
//  //Signed integers - space with zero field width padding
// ft_printf("% 05i", 43);
// ft_printf("% 07i", -54);
// ft_printf("% 03i", 0);
// ft_printf("% 03i", 634);
// ft_printf("% 04i", -532);
// ft_printf("% 04i", -4825);
// //Signed integers - space with field width and precision
// ft_printf("% 8.5i", 34);
// ft_printf("% 10.5i", -216);
// ft_printf("% 8.5i", 0);
// ft_printf("% 8.3i", 8375);
// ft_printf("% 8.3i", -8473);
// ft_printf("% 3.7i", 3267);
// ft_printf("% 3.7i", -2375);
// ft_printf("% 3.3i", 6983);
// ft_printf("% 3.3i", -8462);
//  //Signed integers - space with field width and precision, left-justified
// ft_printf("% -8.5i", 34);
// ft_printf("% -10.5i", -216);
// ft_printf("% -8.5i", 0);
// ft_printf("% -8.3i", 8375);
// ft_printf("% -8.3i", -8473);
// ft_printf("% -3.7i", 3267);
// ft_printf("% -3.7i", -2375);
// ft_printf("% -3.3i", 6983);
// ft_printf("% -3.3i", -8462);
//  //Signed integers - space with field width and precision with zeropadding
// ft_printf("% 08.5i", 34);
// ft_printf("% 010.5i", -216);
// ft_printf("% 08.5i", 0);
// ft_printf("% 08.3i", 8375);
// ft_printf("% 08.3i", -8473);
// ft_printf("% 03.7i", 3267);
// ft_printf("% 03.7i", -2375);
// ft_printf("% 03.3i", 6983);
// ft_printf("% 03.3i", -8462);
// //Signed integers - space with field width and precision, left-justified with zeropadding
// ft_printf("% 0-8.5i", 34);
// ft_printf("% 0-10.5i", -216);
// ft_printf("% 0-8.5i", 0);
// ft_printf("% 0-8.3i", 8375);
// ft_printf("% 0-8.3i", -8473);
// ft_printf("% 0-3.7i", 3267);
// ft_printf("% 0-3.7i", -2375);
// ft_printf("% 0-3.3i", 6983);
// ft_printf("% 0-3.3i", -8462);

// //nocrash tests adapted from tests contributed by phtruong
// ft_printf("%  d", 42);
// //nocrash tests that came about as part of the minimal specification
// ft_printf("% c", 'a');
// ft_printf("% c", -42);
// ft_printf("% s", "hello");
// ft_printf("% u", 42);
// ft_printf("% x", 42);
// ft_printf("% X", 42);
//  /* -----------------------------------------------------------------------------
// **                                              '# +' FLAGS TESTS (BONUS)
// ** ---------------------------------------------------------------------------*/

// // SPACE WITH ALLSIGN - MIGHT BE UNDEFINED BEHAVIOR
// //Signed integers - space with allsign ('+')
// ft_printf("% +d", 5);
// ft_printf("% +d", -7);
// ft_printf("% +d", 2147483647);

// //signed integers with field width and allsign
// ft_printf("% +5d", 35);
// ft_printf("% +7d", 0);
// ft_printf("% +24d", 2147483647);
// ft_printf("% +.7d", 234);
// ft_printf("% +.7d", -446);
// ft_printf("% +.3d", 3723);
// ft_printf("% +05d", 432);
// ft_printf("% +04d", 0);
//  //Signed integers - space with field width and precision with allsign
// ft_printf("% +8.5d", 34);
// ft_printf("% +10.5d", -216);
// ft_printf("% +8.5d", 0);
// ft_printf("% +8.3d", 8375);
// ft_printf("% +8.3d", -8473);
// ft_printf("% +3.7d", 3267);
// ft_printf("% +3.7d", -2375);
// ft_printf("% +3.3d", 6983);
// ft_printf("% +3.3d", -8462);
// ft_printf("%+5.0d", 0);
// ft_printf("%+5.d", 0);
// ft_printf("%+-5.0d", 0);
// ft_printf("%+-5.d", 0);
//  //Signed integers - space with field width and precision, left-justified with allsign
// ft_printf("% +-8.5d", 34);
// ft_printf("% +-10.5d", -216);
// ft_printf("% +-8.5d", 0);
// ft_printf("% +-8.3d", 8375);
// ft_printf("% +-8.3d", -8473);
// ft_printf("% +-3.7d", 3267);
// ft_printf("% +-3.7d", -2375);
// ft_printf("% +-3.3d", 6983);
// ft_printf("% +-3.3d", -8462);
//  //Signed integers - space with field width and precision with allsign with zeropadding
// ft_printf("% 0+8.5d", 34);
// ft_printf("% 0+10.5d", -216);
// ft_printf("% 0+8.5d", 0);
// ft_printf("% 0+8.3d", 8375);
// ft_printf("% 0+8.3d", -8473);
// ft_printf("% 0+3.7d", 3267);
// ft_printf("% 0+3.7d", -2375);
// ft_printf("% 0+3.3d", 6983);
// ft_printf("% 0+3.3d", -8462);

// //Signed integers - space with field width and precision, left-justified with allsign with zeropadding
// ft_printf("% 0+-8.5d", 34);
// ft_printf("% 0+-10.5d", -216);
// ft_printf("% 0+-8.5d", 0);
// ft_printf("% 0+-8.3d", 8375);
// ft_printf("% 0+-8.3d", -8473);
// ft_printf("% 0+-3.7d", 3267);
// ft_printf("% 0+-3.7d", -2375);
// ft_printf("% 0+-3.3d", 6983);
// ft_printf("% 0+-3.3d", -8462);

//  //Signed integers - space with allsign ('+')
// ft_printf("% +i", 5);
// ft_printf("% +i", -7);
// ft_printf("% +i", 2147483647);
// //signed integers with field width and allsign
// ft_printf("% +5i", 35);
// ft_printf("% +7i", 0);
// ft_printf("% +24i", 2147483647);
// ft_printf("% +.7i", 234);
// ft_printf("% +.7i", -446);
// ft_printf("% +.3i", 3723);
// ft_printf("% +05i", 432);
// ft_printf("% +04i", 0);
//  //Signed integers - space with field width and precision with allsign
// ft_printf("% +8.5i", 34);
// ft_printf("% +10.5i", -216);
// ft_printf("% +8.5i", 0);
// ft_printf("% +8.3i", 8375);
// ft_printf("% +8.3i", -8473);
// ft_printf("% +3.7i", 3267);
// ft_printf("% +3.7i", -2375);
// ft_printf("% +3.3i", 6983);
// ft_printf("% +3.3i", -8462);
//  //Signed integers - space with field width and precision, left-justified with allsign
// ft_printf("% +-8.5i", 34);
// ft_printf("% +-10.5i", -216);
// ft_printf("% +-8.5i", 0);
// ft_printf("% +-8.3i", 8375);
// ft_printf("% +-8.3i", -8473);
// ft_printf("% +-3.7i", 3267);
// ft_printf("% +-3.7i", -2375);
// ft_printf("% +-3.3i", 6983);
// ft_printf("% +-3.3i", -8462);
//  //Signed integers - space with field width and precision with allsign with zeropadding
// ft_printf("% 0+8.5i", 34);
// ft_printf("% 0+10.5i", -216);
// ft_printf("% 0+8.5i", 0);
// ft_printf("% 0+8.3i", 8375);
// ft_printf("% 0+8.3i", -8473);
// ft_printf("% 0+3.7i", 3267);
// ft_printf("% 0+3.7i", -2375);
// ft_printf("% 0+3.3i", 6983);
// ft_printf("% 0+3.3i", -8462);
//  //Signed integers - space with field width and precision, left-justified with allsign with zeropadding
// ft_printf("% 0+-8.5i", 34);
// ft_printf("% 0+-10.5i", -216);
// ft_printf("% 0+-8.5i", 0);
// ft_printf("% 0+-8.3i", 8375);
// ft_printf("% 0+-8.3i", -8473);
// ft_printf("% 0+-3.7i", 3267);
// ft_printf("% 0+-3.7i", -2375);
// ft_printf("% 0+-3.3i", 6983);
// ft_printf("% 0+-3.3i", -8462);

//  /* -----------------------------------------------------------------------------
// **                                              'l ll h hh' FLAGS (LENGTH) TESTS (BONUS)
// ** ---------------------------------------------------------------------------*/

// static char             ch_pos_1 = 100, ch_neg_1 = -87;
// static short            sh_pos_1 = 3047, sh_neg_1 = -8875;
// static int                      i_pos_1 = 878023;
// static long                     l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
// static long long        ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
// static long                     lmax    = 9223372036854775807;
// static long                     lmin    = -9223372036854775807;
// static long long        llmax = 9223372036854775807;
// static long long        llmin = -9223372036854775807ll;
// //Signed integers of varying size modifiers
// ft_printf("%hhd", (char)45);
// ft_printf("%hhd", (char)-45);
// ft_printf("%hd", (short)385);
// ft_printf("%hd", (short)-385);
// ft_printf("%lld", (long long)43);
// ft_printf("%lld", (long long)-43);
// ft_printf("%ld", (long)32);
// ft_printf("%ld", (long)-32);
// ft_printf("%hhd", ch_pos_1);
// ft_printf("%hhd", ch_neg_1);
// ft_printf("%hd", sh_pos_1);
// ft_printf("%hd", sh_neg_1);
// ft_printf("%lld", llmax);
// ft_printf("%lld", ll_pos_1);
// ft_printf("%lld", ll_neg_1);
// ft_printf("%ld", l_pos_1);
// ft_printf("%ld", lmax);
// ft_printf("%ld", l_neg_1);
// ft_printf("%lld", 522337203685470ll);
// ft_printf("%lld", -522337203685470ll);
// ft_printf("%ld", 22337203685477);
// ft_printf("%ld", -22337203685477);
// ft_printf("%+ld", 22337203685477l);
// ft_printf("%lld", 9223372036854775807ll);
// ft_printf("%lld", llmin);
// ft_printf("%ld", 9223372036854775807l);
// ft_printf("%ld", lmin);
// ft_printf("%hd", (short)32767);
// ft_printf("%hd", (short)(-32768));
// ft_printf("%hhd", (char)127);
// ft_printf("%hhd", (char)(-128));
//  //Signed integers of varying size modifiers with some other modifiers
// ft_printf("%037ld", 22337203685477l);
// ft_printf("%.37ld", -22337203685477l);
// ft_printf("%37lld", 522337203685470ll);
// ft_printf("%-37lld", -522337203685470ll);
//  //Multiple signed integers in a row of varying sizes
// ft_printf("[%d] [%d]", i_pos_1, i_pos_1);
// ft_printf("[%d] [%ld]", i_pos_1, l_pos_1);
// ft_printf("[%d] [%lld]", i_pos_1, ll_pos_1);
// ft_printf("[%d] [%hd]", i_pos_1, sh_pos_1);
// ft_printf("[%d] [%hhd]", i_pos_1, ch_pos_1);
// ft_printf("%lld%hhd%lld", ll_pos_1, ch_neg_1, ll_neg_1);
// ft_printf("%hd%ld%hhd", sh_pos_1, l_neg_1, ch_neg_1);
// ft_printf("%ld%hhd%hd", l_neg_1, ch_pos_1, sh_pos_1);
// ft_printf("%d%lld%hhd", i_pos_1, ll_neg_1, ch_pos_1);
// ft_printf("%lli%d%ld", ll_neg_1, i_pos_1, l_pos_1);
//  //Signed integers - space of varying size modifiers
// ft_printf("% hhd", (char)45);
// ft_printf("% hhd", (char)-45);
// ft_printf("% hd", (short)385);
// ft_printf("% hd", (short)-385);
// ft_printf("% ld", (long)32);
// ft_printf("% ld", (long)-32);
// ft_printf("% lld", (long long)43);
// ft_printf("% lld", (long long)-43);
// ft_printf("% hhd", ch_pos_1);
// ft_printf("% hhd", ch_neg_1);
// ft_printf("% hd", sh_pos_1);
// ft_printf("% hd", sh_neg_1);
// ft_printf("% ld", l_pos_1);
// ft_printf("% ld", l_neg_1);
// ft_printf("% lld", ll_pos_1);
// ft_printf("% lld", ll_neg_1);
// ft_printf("% ld", 22337203685477l);
// ft_printf("% ld", -22337203685477l);
// ft_printf("% lld", 522337203685470ll);
// ft_printf("% lld", -522337203685470ll);
// ft_printf("% lld", 9223372036854775807ll);
// ft_printf("% lld", llmin);
// ft_printf("% ld", 9223372036854775807l);
// ft_printf("% ld", lmin);
// ft_printf("% hd", (short)32767);
// ft_printf("% hd", (short)(-32768));
// ft_printf("% hhd", (char)(127));
// ft_printf("% hhd", (char)(-128));

//  //Signed integers of varying size modifiers
// ft_printf("%hhi", (char)45);
// ft_printf("%hhi", (char)-45);
// ft_printf("%hi", (short)385);
// ft_printf("%hi", (short)-385);
// ft_printf("%li", (long)32);
// ft_printf("%li", (long)-32);
// ft_printf("%lli", (long long)43);
// ft_printf("%lli", (long long)-43);
// ft_printf("%hhi", ch_pos_1);
// ft_printf("%hhi", ch_neg_1);
// ft_printf("%hi", sh_pos_1);
// ft_printf("%hi", sh_neg_1);
// ft_printf("%li", l_pos_1);
// ft_printf("%li", lmax);
// ft_printf("%lli", llmax);
// ft_printf("%li", l_neg_1);
// ft_printf("%lli", ll_pos_1);
// ft_printf("%lli", ll_neg_1);
// ft_printf("%li", 22337203685477);
// ft_printf("%li", -22337203685477);
// ft_printf("%lli", 522337203685470ll);
// ft_printf("%lli", -522337203685470ll);
// ft_printf("%lli", 9223372036854775807ll);
// ft_printf("%lli", llmin);
// ft_printf("%li", 9223372036854775807l);
// ft_printf("%li", lmin);
// ft_printf("%hi", (short)32767);
// ft_printf("%hi", (short)(-32768));
// ft_printf("%hhi", (char)127);
// ft_printf("%hhi", (char)(-128));
//  //Signed integers of varying size modifiers with some other modifiers
// ft_printf("%037li", 22337203685477l);
// ft_printf("%.37li", -22337203685477l);
// ft_printf("%37lli", 522337203685470ll);
// ft_printf("%-37lli", -522337203685470ll);
// //Multiple signed integers in a row of varying sizes
// ft_printf("[%i] [%i]", i_pos_1, i_pos_1);
// ft_printf("[%i] [%li]", i_pos_1, l_pos_1);
// ft_printf("[%i] [%lli]", i_pos_1, ll_pos_1);
// ft_printf("[%i] [%hi]", i_pos_1, sh_pos_1);
// ft_printf("[%i] [%hhi]", i_pos_1, ch_pos_1);
// ft_printf("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);
// ft_printf("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);
// ft_printf("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);
// ft_printf("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);
// ft_printf("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);
// //Signed integers - space of varying size modifiers
// ft_printf("% hhi", (char)45);
// ft_printf("% hhi", (char)-45);
// ft_printf("% hi", (short)385);
// ft_printf("% hi", (short)-385);
// ft_printf("% li", (long)32);
// ft_printf("% li", (long)-32);
// ft_printf("% lli", (long long)43);
// ft_printf("% lli", (long long)-43);
// ft_printf("% hhi", ch_pos_1);
// ft_printf("% hhi", ch_neg_1);
// ft_printf("% hi", sh_pos_1);

// ft_printf("% hi", sh_neg_1);
// ft_printf("% li", l_pos_1);
// ft_printf("% li", l_neg_1);
// ft_printf("% lli", ll_pos_1);
// ft_printf("% lli", ll_neg_1);
// ft_printf("% li", 22337203685477l);
// ft_printf("% li", -22337203685477l);
// ft_printf("% lli", 522337203685470ll);
// ft_printf("% lli", -522337203685470ll);
// ft_printf("% lli", 9223372036854775807ll);
// ft_printf("% lli", llmin);
// ft_printf("% li", 9223372036854775807l);
// ft_printf("% li", lmin);
// ft_printf("% hi", (short)32767);
// ft_printf("% hi", (short)(-32768));
// ft_printf("% hhi", (char)(127));
// ft_printf("% hhi", (char)(-128));
// ft_printf("%+li", 22337203685477l);
//   //Unsigned integers of varying size modifiers
// static unsigned char            uch_pos_1 = 100;
// static unsigned short           ush_pos_1 = 3047;
// static unsigned int             ui_pos_1 = 878023;
// static unsigned long            ul_pos_1 = 22337203685477;
// static unsigned long long       ull_pos_1 = 22337203685477;
// static unsigned long long  ullmax = 9223372036854775807;
// static unsigned long            ulmax = 9223372036854775807;
// ft_printf("%hhu", (unsigned char)45);
// ft_printf("%hu", (unsigned short)385);
// ft_printf("%lu", (unsigned long)32);
// ft_printf("%llu", (unsigned long long)43);
// ft_printf("%hhu", uch_pos_1);
// ft_printf("%hu", ush_pos_1);
// ft_printf("%lu", ul_pos_1);
// ft_printf("%llu", ull_pos_1);
// ft_printf("%lu", 22337203685477ul);
// ft_printf("%llu", 522337203685470ull);
// ft_printf("%llu", ullmax);
// ft_printf("%lu", ulmax);
// ft_printf("%hu", (unsigned short)65535);
// ft_printf("%hhu", (unsigned char)255);
// //Unsigned integers of varying size modifiers with some other modifiers
// ft_printf("%037lu", 22337203685477ul);
// ft_printf("%37llu", 522337203685470ull);
// //Multiple unsigned integers in a row of varying sizes
// ft_printf("%llu%hhu%llu", ull_pos_1, uch_pos_1, ull_pos_1);
// ft_printf("%hu%lu%hhu", ush_pos_1, ul_pos_1, uch_pos_1);
// ft_printf("%lu%hhu%hu", ul_pos_1, uch_pos_1, ush_pos_1);
// ft_printf("%u%llu%hhu", ui_pos_1, ull_pos_1, uch_pos_1);
// ft_printf("%llu%u%lu", ull_pos_1, ui_pos_1, ul_pos_1);
// //Hexadecimal lowers of varying size modifiers with some other modifiers
// ft_printf("%037lx", 22337203685477ul);
// ft_printf("%37llx", 522337203685470ull);
// //Multiple Hexadecimal lowers in a row of varying sizes
// ft_printf("%llu%hhu%llx", ull_pos_1, uch_pos_1, ull_pos_1);
// ft_printf("%hu%lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);
// ft_printf("%lu%hhu%hx", ul_pos_1, uch_pos_1, ush_pos_1);
// ft_printf("%u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);
// ft_printf("%llu%u%lx", ull_pos_1, ui_pos_1, ul_pos_1);
//  //Hexadecimal lower (altform) of varying size modifiers
// ft_printf("%#hhx", (unsigned char)45);
// ft_printf("%#hx", (unsigned short)385);
// ft_printf("%#lx", (unsigned long)32);
// ft_printf("%#llx", (long long)43);
// ft_printf("%#hhx", uch_pos_1);
// ft_printf("%#hx", ush_pos_1);
// ft_printf("%#lx", ul_pos_1);
// ft_printf("%#llx", ull_pos_1);
// ft_printf("%#lx", 22337203685477lu);
// ft_printf("%#llx", 522337203685470llu);
// ft_printf("%#llx", ullmax);
// ft_printf("%#lx", ulmax);
// ft_printf("%#hx", (unsigned short)65535);
// ft_printf("%#hhx", (unsigned char)255);
//  //Hexadecimal uppers of varying size modifiers
// ft_printf("%hhX", (unsigned char)45);
// ft_printf("%hX", (unsigned short)385);
// ft_printf("%lX", (unsigned long)32);
// ft_printf("%llX", (long long)43);
// ft_printf("%hhX", uch_pos_1);
// ft_printf("%hX", ush_pos_1);
// ft_printf("%lX", ul_pos_1);
// ft_printf("%llX", ull_pos_1);
// ft_printf("%lX", 22337203685477ul);
// ft_printf("%llX", 522337203685470ull);
// ft_printf("%llX", ullmax);
// ft_printf("%lX", ulmax);
// ft_printf("%hX", (unsigned short)65535);
// ft_printf("%hhX", (unsigned char)255);
// //Hexadecimal uppers of varying size modifiers with some other modifiers
// ft_printf("%037lX", 22337203685477ul);
// ft_printf("%37llX", 522337203685470ull);
// //Multiple Hexadecimal uppers in a row of varying sizes
// ft_printf("%llu%hhu%llX", ull_pos_1, uch_pos_1, ull_pos_1);
// ft_printf("%hu%lu%hhX", ush_pos_1, ul_pos_1, uch_pos_1);
// ft_printf("%lu%hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);
// ft_printf("%u%llu%hhX", ui_pos_1, ull_pos_1, uch_pos_1);
// ft_printf("%llu%u%lX", ull_pos_1, ui_pos_1, ul_pos_1);

// //Hex uppers (altform) of varying size modifiers
// ft_printf("%#hhX", (unsigned char)45);
// ft_printf("%#hX", (unsigned short)385);
// ft_printf("%#lX", (unsigned long)32);
// ft_printf("%#llX", (long long)43);
// ft_printf("%#hhX", uch_pos_1);
// ft_printf("%#hX", ush_pos_1);
// ft_printf("%#lX", ul_pos_1);
// ft_printf("%#llX", ull_pos_1);
// ft_printf("%#lX", 22337203685477ul);
// ft_printf("%#llX", 522337203685470ull);
// ft_printf("%#llX", ullmax);
// ft_printf("%#lX", ulmax);
// ft_printf("%#hX", (unsigned short)65535);
// ft_printf("%#hhX", (unsigned char)255);
//  //Hex uppers (altform) of varying size modifiers with some other modifiers
// ft_printf("%#037lX", 22337203685477ul);
// ft_printf("%#37llX", 522337203685470ull);
// //Multiple Hex uppers (altform) in a row of varying sizes
// ft_printf("%llu%hhu%#llX", ull_pos_1, uch_pos_1, ull_pos_1);
// ft_printf("%#hx%lu%#hhX", ush_pos_1, ul_pos_1, uch_pos_1);
// ft_printf("%lu%hhu%#hX", ul_pos_1, uch_pos_1, ush_pos_1);
// ft_printf("%#x%llu%#hhX", ui_pos_1, ull_pos_1, uch_pos_1);
// ft_printf("%#llx%u%#lX", ull_pos_1, ui_pos_1, ul_pos_1);
// while(1);
// return 0;
// }
