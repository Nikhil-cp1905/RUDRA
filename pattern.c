//code for patternO
#include <stdio.h>
void pt(int r){
 for(int i=1;i<=r;i++){
                for (int j=1;j<=i;j++){
                        printf("*");
                }
                printf("\n");
        }
}

int main(){
	int r;
	printf("Enter number of rows");
	scanf("%d",&r);
        pt(r);

}
