#include <algorithm> //find_if()
#include <cctype>    //isspace()
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//�μ��� ������ ���� true, �׷��� ���� ���� false�� ��ȯ
bool space(char c) {
	return isspace(c);
}

//�μ��� ������ ���� false, �׷��� ���� ���� true�� ��ȯ
bool not_space(char c) {
	return !isspace(c);
}

vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	//for(iter i = str.begin(); i != str.end(); i++)
	while (i != str.end()) {
		//���� ������ ����
		//���� i��ġ���� ù ��° ���� �ƴ� ���� ã��
		i = find_if(i, str.end(), not_space);

		//���� �ܾ��� ���� ã��
		//while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����
		//���� i��ġ���� ù ��° ���� ���� ã��
		iter j = find_if(i, str.end(), space);

		//[i, j)������ ���ڸ� ����
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}

		//i�ݺ��� ��ġ�� j�ݺ����� ��ġ�� �����ϱ�
		i = j;
	}
	return ret;
}