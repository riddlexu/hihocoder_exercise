#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
  int num,money;
  cin >> num >> money;
  int* need = (int*)malloc(num*sizeof(int));
  int* value = (int*)malloc(num*sizeof(int));
  for(int i = 0; i < num; i++){
    cin >> need[i] >> value[i];
  }
  int* f = (int*)malloc((money+1)*sizeof(int));
  for(int i = 0; i < money + 1; i++){
    f[i] = 0;
  }
  for(int i = 0; i < num; i++){
    for(int j = money; j >= need[i]; j--){
      f[j] = max(f[j],f[j-need[i]] + value[i]);
    }
  }
  cout << f[money] << endl;
  return 0;
}
