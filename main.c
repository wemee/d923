#include "stdio.h"
#include "stdlib.h"
#include "math.h"

unsigned long long **matrix;

void create_matrix(int size, unsigned long long base, int i, int j){
    unsigned long long base_op;
    if (size==1) {
//        printf("i:%d ,j:%d", i, j);
        matrix[i][j] = base;
    } else {
        size /= 2;
        base_op = (unsigned long long)size*size;
        /* 左上 */
        create_matrix(size, base, i, j);
        
        /* 右下 */
        create_matrix(size, base_op+base, i+size, j+size);
        
        /* 右上 */
        create_matrix(size, base_op*2+base, i, j+size);
        
        /* 左下 */
        create_matrix(size, base_op*3+base, i+size, j);
    }
}

int main(){
    int i,j, max, size,cnt;
    unsigned long long *p_matrix;
    
    scanf("%d%d", &i, &j);
    max = i>j ? i:j;
    size = pow(2, ceil(log(max)/log(2)));
    
    matrix = malloc( size*sizeof(unsigned long long *) +
                     size*size*sizeof(unsigned long long) );
    for (cnt=0, p_matrix = (unsigned long long *)(matrix+size); cnt<size; cnt++, p_matrix += size)
        matrix[cnt] = p_matrix;
    
    create_matrix(size, 1, 0, 0);
    printf("%lld\n", matrix[i-1][j-1]);
    
    free(matrix);
    return 0;
}
