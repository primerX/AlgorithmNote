//��������

int A[MAXN], n;		//n ΪԪ�ظ����������±�Ϊ 1~n
void insertSort()
{
	for(int i = 2; i <= n; i++){	//���� n-1 ������ 
		int temp = A[i], j = i;		//temp ��ʱ���A[j], j��i��ʼ��ǰö��
		while(j > 1 && temp < A[j-1]){	//ֻҪ temp С��ǰһ��Ԫ��A[j-1]
		 	A[j] = A[j - 1];	//��A[j-1] ����һλ�� A[j] 
		 	j--;
		} 
		A[j] = temp;	//����λ��Ϊj 
	}
}
