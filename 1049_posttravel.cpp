#include<iostream>
#include<string>
using namespace std;

string posttravel(string pre, string mid)
{
  if(pre.size() == 0){
    return "";
  }
  if(pre.size() == 1){
    return pre;
  }
  char root = pre[0];
  size_t loc = mid.find_first_of(root);
  string left = "";
  string right = "";
  if(loc > 0){
    left = posttravel(pre.substr(1,loc),mid.substr(0,loc));
  }
  if(loc < mid.size() - 1){
    right = posttravel(pre.substr(1+loc),mid.substr(loc+1));
  }
  return left + right + root;
}

int main()
{
  string pre,mid;
  cin >> pre;
  cin >> mid;
  cout << posttravel(pre,mid) << endl;
  return 0;
}
