/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) main.c (5) 2025.05.28 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//이원탐색트리의 노드 구조 정의 
typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}Node; 

//삽입 함수
Node* insertKey(Node* p, int x){
	Node* newNode;
	if(p==NULL){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->key = x;
		newNode->left=newNode->right = NULL; //하나의 루트
		return newNode; 
	}
	else if(x <p->key){ //왼쪽에 삽입 
		p->left = insertKey(p->left, x);
		return p; //왼쪽 어딘가에 삽입되면 끝 
	}
	else if(x>p->key){ //오른쪽에 삽입 
		p->right = insertKey(p->right, x);
		return p;
	}
	else{	//중복은 안됨. 삽입 안됨. 
		printf("키값이 이미 있습니다.");
		return p;
	}
}
void insert(Node** root, int x){ //노드 가리키는 포인터의 포인터 
	*root = insertKey(*root, x); //노드 가리키는 포인터 업데이트 
}
//중위순회 출력 
void printInorder(Node* p){
	if(p!=NULL){
		printInorder(p->left); //왼쪽먼저 
		printf("%d ", p->key);
		printInorder(p->right);
	}
} 
//검색함수 .. 재귀함수가 아니긴해***** 
Node* find(Node* root, int x){
	Node* p;
	p=root;
	while(p!=NULL){
		if(x< p->key){
			p = p->left; //작은값이면 왼쪽으로 이동 
		}
		else if(x==p->key){
			printf("검색 결과:%d은 트리에 존재합니다.",x);
			return p;
		} 
		else p = p->right; //크면 오른쪽 탐색 
	}
	printf("검색 결과: %d는 트리에 존재하지 않습니다.", x);
	return p; //이 위치는 숫자가 있어야할 위치이기도 함 
} 

int main(int argc, char *argv[]) {
	//숫자수집가의 비밀정원
	//이진 탐색 트리
	Node* root = NULL; //공백이원탐색트리 선언 
	//1.순서대로 숫자 삽입
	int num[7] = {50,30,70,20,40,60,80}; //삽입할 숫자배열
	int i; 
	for(i=0;i<7;i++){
		insert(&root, num[i]); //트리의 포인터와 삽입할것 
	} 
	//2.삽입된 노드들을 중위순회하여 출력
	printf("중위 순회 결과:");
	printInorder(root); 
	printf("\n");
	//3.입력으로 숫자 받아, 숫자가 트리에 존재하는지 검색, 결과출력
	//3-1.입력받기 
	int fnum;
	printf("검색할 숫자 입력:");
	scanf("%d", &fnum);
	//3-2.트리 검색
	find(root,fnum);
	
	//3-3.결과 출력 
	//printf("검색 결과:%d은 트리에 존재합니다.",fnum); 
	//printf("검색 결과:%d은 트리에 존재하지 않습니다."); 
	return 0;
}
