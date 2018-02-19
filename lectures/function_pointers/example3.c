// Programming 1. Sample at 2018-02-15-14-55.05
#include <stdio.h>
 
struct S{
  int a;
  int b;
};
 
void* search( void *key,
              void *arr,
              int n,
              int size,
              int (*comp)(const void *, const void *)
            ){
 
  for(int i=0;i<n;i++){
    if(comp(key, arr+i*size) == 0){
      return arr+i*size;
    }
  }
  return NULL;
}
 
// if both fields are equal, the structures are equal
// otherwise compare by the sum of two fields
int comp(const void *a, const void *b){
  struct S *aa = (struct S*)a;
  struct S *bb = (struct S*)b;
  if(aa->a == bb->a && aa->b == bb->b){
    return 0;
  }
  if((aa->a + aa->b) - (bb->a + bb->b) > 0){
    return 1;
  }
  return -1;
}
 
int main(){
  struct S arr[]={{1,2},{3,4},{5,6},{6,7}};
  struct S* value;
  struct S key={5,6};
 
  value = search(&key, arr, 4, sizeof(struct S), comp);
  if(value){
    printf("%zu\n", value - arr);
  }else{
    printf("nooooo\n");
  }
  return 0;
}
