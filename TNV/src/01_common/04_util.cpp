// 公共模块
// 定义几个实用函数
//
#include <string.h>
#include "01_types.h"
#include "03_util.h"

// long long类型整数主机序转网络序
// 0x0102030405060708   ------------------> |0x01|0x02|0x03|0x04|0x05|0x06|0x07|0x08|
void llton(long long ll, char* n) {
	for (size_t i = 0; i < sizeof(ll); ++i)
		n[i] = ll >> (sizeof(ll) - i - 1) * 8;
}

// long long类型整数网络序转主机序
// |0x01|0x02|0x03|0x04|0x05|0x06|0x07|0x08|
//   ------------------> 0x0102030405060708
long long ntoll(char const* n) {
	long long ll = 0;
	for (size_t i = 0; i < sizeof(ll); ++i)
		ll |= (long long)(unsigned char)n[i] << (sizeof(ll) - i - 1) * 8;
	return ll;
}

// long类型整数主机序转网络序
// 0x01020304   ------------------> |0x01|0x02|0x03|0x04|
void lton(long l, char* n) {
	for (size_t i = 0; i < sizeof(l); ++i)
		n[i] = l >> (sizeof(l) - i - 1) * 8;
}

// long类型整数网络序转主机序
// |0x01|0x02|0x03|0x04|   ------------------> 0x01020304
long ntol(char const* n) {
	long l = 0;
	for (size_t i = 0; i < sizeof(l); ++i)
		l |= (long)(unsigned char)n[i] << (sizeof(l) - i - 1) * 8;
	return l;
}

// short类型整数主机序转网络序
// 0x0102   ------------------> |0x01|0x02|
void ston(short s, char* n) {
	for (size_t i = 0; i < sizeof(s); ++i)
		n[i] = s >> (sizeof(s) - i - 1) * 8;
}

// short类型整数网络序转主机序
//  |0x01|0x02|  ------------------> 0x0102
short ntos(char const* n) {
	short s = 0;
	for (size_t i = 0; i < sizeof(s); ++i)
		s |= (short)(unsigned char)n[i] << (sizeof(s) - i - 1) * 8;
	return s;
}

// 字符串是否合法，即是否只包含26个英文字母大小写和0到9十个阿拉伯数字
int valid(char const* str) {
	if (!str)
		return ERROR;

	size_t len = strlen(str);
	if (!len)
		return ERROR;

	for (size_t i = 0; i < len; ++i)
		if (!(('a' <= str[i] && str[i] <= 'z') ||
			  ('A' <= str[i] && str[i] <= 'Z') ||
			  ('0' <= str[i] && str[i] <= '9')))
			return ERROR;

	return OK;
}

// 以分号为分隔符将一个字符串拆分为多个子字符串
int split(char const* str, std::vector<std::string>& substrs) {
	if (!str)
		return ERROR;

	size_t len = strlen(str);
	if (!len)
		return ERROR;

    //strtok是会修改原字符串的(万一指向只读区域,就会段错误)所以要保存下来
	char* buf = new char[len+1];
	strcpy(buf, str);

	char const* sep = ";"; // 字符集,把你向以什么样的字符作为分隔符放到这里面
    //strtok找到分隔符后把分隔符替换为'\0'然后返回str
    //内部会维护一个指针,指向分隔符的位置,第二次调用的时候传NULL,
    //从内部维护的指针那个位置开始找,找第一个不出现在sep里面的字符,
    //然后从这个位置开始找下一个出现在sep里面的字符.

	for (char* substr = strtok(buf, sep); substr;
		substr = strtok(NULL, sep))
		substrs.push_back(substr);

	delete[] buf;

	return OK;
}
