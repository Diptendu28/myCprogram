#include <stdio.h>
#include <Windows.h>
void superscript(int x){
    SetConsoleOutputCP(CP_UTF8);
    if(x<0){
         x=-x;
         printf("⁻");
    }
    if(x==0)
        printf("⁰");
    if(x==1)
        printf("¹");
    if(x==2)
        printf("²");
    if(x==3)
        printf("³");
    if(x==4)
        printf("⁴");
    if(x==5)
        printf("⁵");
    if(x==6)
        printf("⁶");
    if(x==7)
        printf("⁷");
    if(x==8)
        printf("⁸");
    if(x==9)
        printf("⁹");
    if(x>9){
        breakNumber(x);
    }

}

void breakNumber(int n){
    int val, temp = 0, zero = 0;
   while(n>0) {
		val = n%10;
		if(val==0)
            zero++;
		n /= 10;
		temp = temp*10 + val;
	}
	while(temp>0) {
		val = temp%10;
		temp /= 10;
		superscript(val);

	}
	while(zero){
        superscript(0);
        zero--;
	}
}


int main()
{
    int size = 10;
    for(int i = -10; i <= size; i++){
        printf("x");
        superscript(i);
        if(i != size)
            printf(" + ");
    }
    return 0;
}

/***

#include <wchar.h>
#include <locale.h>

SetConsoleOutputCP(CP_UTF8);
        printf("⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ⁺ ⁻ ⁼ ⁽ ⁾ ₀ ₁ ₂ ₃ ₄ ₅ ₆ ₇ ₈ ₉ ₊ ₋ ₌ ₍ ₎ ᵃ ᵇ ᶜ ᵈ ᵉ ᶠ ᵍ ʰ ⁱ ʲ ᵏ ˡ ᵐ ⁿ ᵒ ᵖ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ  ᴬ ᴮ ᴰ ᴱ ᴳ ᴴ ᴵ ᴶ ᴷ ᴸ ᴹ ᴺ ᴼ ᴾ ᴿ ᵀ ᵁ ⱽ ᵂ ₐ ₑ ₕ ᵢ ⱼ ₖ ₗ ₘ ₙ ₒ ₚ ᵣ ₛ ₜ ᵤ ᵥ ₓ ᵅ ᵝ ᵞ ᵟ ᵋ ᶿ ᶥ ᶲ ᵠ ᵡ  ᵦ ᵧ ᵨ ᵩ ᵪ   ");
    /*
    printf("x");
    setlocale(LC_CTYPE, "");
    wchar_t bar[2];
    bar[0] = 178;
    bar[1] = 0;
    wprintf(L"%ls\n", bar);
*/

