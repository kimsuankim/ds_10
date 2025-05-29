/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) main.c (5) 2025.05.28 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�̿�Ž��Ʈ���� ��� ���� ���� 
typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}Node; 

//���� �Լ�
Node* insertKey(Node* p, int x){
	Node* newNode;
	if(p==NULL){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->key = x;
		newNode->left=newNode->right = NULL; //�ϳ��� ��Ʈ
		return newNode; 
	}
	else if(x <p->key){ //���ʿ� ���� 
		p->left = insertKey(p->left, x);
		return p; //���� ��򰡿� ���ԵǸ� �� 
	}
	else if(x>p->key){ //�����ʿ� ���� 
		p->right = insertKey(p->right, x);
		return p;
	}
	else{	//�ߺ��� �ȵ�. ���� �ȵ�. 
		printf("Ű���� �̹� �ֽ��ϴ�.");
		return p;
	}
}
void insert(Node** root, int x){ //��� ����Ű�� �������� ������ 
	*root = insertKey(*root, x); //��� ����Ű�� ������ ������Ʈ 
}
//������ȸ ��� 
void printInorder(Node* p){
	if(p!=NULL){
		printInorder(p->left); //���ʸ��� 
		printf("%d ", p->key);
		printInorder(p->right);
	}
} 
//�˻��Լ� .. ����Լ��� �ƴϱ���***** 
Node* find(Node* root, int x){
	Node* p;
	p=root;
	while(p!=NULL){
		if(x< p->key){
			p = p->left; //�������̸� �������� �̵� 
		}
		else if(x==p->key){
			printf("�˻� ���:%d�� Ʈ���� �����մϴ�.",x);
			return p;
		} 
		else p = p->right; //ũ�� ������ Ž�� 
	}
	printf("�˻� ���: %d�� Ʈ���� �������� �ʽ��ϴ�.", x);
	return p; //�� ��ġ�� ���ڰ� �־���� ��ġ�̱⵵ �� 
} 

int main(int argc, char *argv[]) {
	//���ڼ������� �������
	//���� Ž�� Ʈ��
	Node* root = NULL; //�����̿�Ž��Ʈ�� ���� 
	//1.������� ���� ����
	int num[7] = {50,30,70,20,40,60,80}; //������ ���ڹ迭
	int i; 
	for(i=0;i<7;i++){
		insert(&root, num[i]); //Ʈ���� �����Ϳ� �����Ұ� 
	} 
	//2.���Ե� ������ ������ȸ�Ͽ� ���
	printf("���� ��ȸ ���:");
	printInorder(root); 
	printf("\n");
	//3.�Է����� ���� �޾�, ���ڰ� Ʈ���� �����ϴ��� �˻�, ������
	//3-1.�Է¹ޱ� 
	int fnum;
	printf("�˻��� ���� �Է�:");
	scanf("%d", &fnum);
	//3-2.Ʈ�� �˻�
	find(root,fnum);
	
	//3-3.��� ��� 
	//printf("�˻� ���:%d�� Ʈ���� �����մϴ�.",fnum); 
	//printf("�˻� ���:%d�� Ʈ���� �������� �ʽ��ϴ�."); 
	return 0;
}
