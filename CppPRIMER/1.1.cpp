#include <bits/stdc++.h>
using namespace std;

int main()
{
//     // vector<int> test = {0,5,6,7,1,6,8};
//     // sort(test.begin(), test.end(), [](int A, int B){return A < B;});
//     // for(int num:test){
//     //     cout<<num<<endl;
//     // // }
//     // int i =21;
//     // int j = -1;
//     // int x = i&j;
//     // cout<<x<<endl;
    string str("ff");

    int b = strtoul(str.c_str(),0,16);
    cout<<b<<endl;
    return 0;    
}

// #include <stdio.h>
// #include <string.h>
 
// //字符转换成整形
// int hex2int(char c)
// {
// 	if ((c >= 'A') && (c <= 'Z'))
// 	{
// 		return c - 'A' + 10;
// 	}
// 	else if ((c >= 'a') && (c <= 'z'))
// 	{
// 		return c - 'a' + 10;
// 	}
// 	else if ((c >= '0') && (c <= '9'))
// 	{
// 		return c - '0';
// 	}
// }
 
// int main()
// {
// 	//十六进制字符串转换成整形
// 	const char* hexStr = "fffffff";
// 	int data[32] = {0};
// 	int count = 0;
 
// 	for (int i=0; i<strlen(hexStr); i+=2)
// 	{
// 		int high = hex2int(hexStr[i]);   //高四位
// 		int low  = hex2int(hexStr[i+1]); //低四位
// 		data[count++] = (high<<4) + low;
// 	}
 
// 	//打印输出
// 	for (int i=0; i<strlen(hexStr)/2; i++)
// 	{
// 		printf("%d ", data[i]);
// 	}
// 	return 1;
// }
