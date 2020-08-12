#include <stdio.h>

char	*ft_strcapitalize(char *str);
int main(){
    char str1[100] = "salut, commAnt tu vas ? 42mots quarante-deux; cinquante+et+un";
    char str2[100] = "*LCRQGBiexzfFXf9!-@#STtv?KZ<P$";
    char str3[100] = "DFkeyo_#{%9QkW;P@1MCp_*,W >,Q1*<LVcT";
    char *org1 = "salut, commAnt tu vas ? 42mots quarante-deux; cinquante+et+un";
    char *org2 = "*LCRQGBiexzfFXf9!-@#STtv?KZ<P$";
    char *org3 = "DFkeyo_#{%9QkW;P@1MCp_*,W >,Q1*<LVcT";
    printf("org: %s\ncap: %s\n", org1, ft_strcapitalize(str1));
    printf("org: %s\ncap: %s\n", org2, ft_strcapitalize(str2));
    printf("org: %s\ncap: %s\n", org3, ft_strcapitalize(str3));
    return 0;
}