# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
long long sum(int arr[],int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i];
	}
	return ans;
}
long long sum_(int a) {
	long long ans=0;
	for (int i = 1; i <= a; i++) {
		ans += i;
	}
	return ans;
}
int main(){
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int* que=(int *)malloc(sizeof(int)*300000);
		for (int i = 0; i < m; i++) {
			scanf("%d", que+i);
		}
		int* abili = (int*)malloc(sizeof(int) * 300000);
		for (int i = 0; i < k; i++) {
			scanf("%d", abili+i);
		}
		int dis = sum_(n) - sum(abili,k);
		if (n - k > 1) {
			for (int i = 0; i < m; i++) {
				printf("0");
			}
			printf("\n");
			free(que);
			free(abili);
			continue;
		}
		else if (n == k) {
			for (int i = 0; i < m; i++) {
				printf("1");
			}
			printf("\n");
			free(que);
			free(abili);
			continue;
		}
		else
		{
			int* score = (int*)malloc(sizeof(int) * 300000);
			for (int i = 0; i < m; i++) {
				if (que[i] == dis)score[i] = 1;
				else
				{
					score[i] = 0;
				}
			}
			for (int i = 0; i < m; i++)printf("%d", score[i]);
			free(score);
			free(que);
			free(abili);
			printf("\n");
		}
	}
}
