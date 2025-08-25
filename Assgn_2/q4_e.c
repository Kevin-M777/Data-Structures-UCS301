#include <stdio.h>
//case conversion
int main(){
    char c;
    printf("Enter character for case conversion:");
    scanf("%c",&c);
    if (c>'A'&&c<'Z')printf("%c",c+32);
    else printf("%c",c-32);
    return 0;
}