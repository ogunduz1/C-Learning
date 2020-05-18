#include <stdio.h>
#include <stdlib.h>

struct n{
	n* prev;
	n* next;
	int data;
};
typedef n node;

void display(node*);

bool isEmpty(node*);

node* add(node*,int);

node* addSort(node*,int);

node* del(node*,int);

void find(node*,int);

int main(){
	node* root=NULL;
	root=add(root,25);
	root=add(root,35);
	display(root);
	if(!isEmpty(root))
		printf("list not empty!");
	for(int i=20;i>0;i--){
		root=addSort(root,i*10);
	}
	display(root);
	root=del(root,35);
	display(root);
	find(root,30);
	find(root,25);
	return 0;
}
void display(node* r){
	if(r==NULL)
		printf("List Empty!");
	while(r!=NULL){
		printf("%d->",r->data);
		r=r->next;
	}
}
bool isEmpty(node* r) {
	return (r==NULL);
}
node* add(node* r,int x){
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r->prev=NULL;
		r->data=x;
		return r;
	}
	node* iter=r;
	while(iter->next!=NULL) {
		iter->prev=iter;
		iter=iter->next;
	}
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	iter->next=temp;
	temp->prev=iter;
	temp->next=NULL;
	return r;
}
node* addSort(node* r,int x){
	node* iter=r;
	node *temp;
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=NULL;
		r->prev=NULL;
		return r;
	}
	
	if(r->data>x){
		temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;
		r->prev=temp;
		return temp;
	}
	while(iter->next!=NULL && iter->next->data < x) {
		iter=iter->next;
	}
	temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)
		temp->next->prev=temp;
	temp->data=x;
	return r;
}
node* del(node* r,int x) {
	node* iter=r;
	if(r==NULL)
		printf("List Empty!");
	if(iter->data==x){
		r=r->next;
		r->prev=NULL;
		free(iter);
		printf(" Item %d deleted! ",x);
		return r;
	}
	while(iter->next!=NULL && iter->next->data !=x)
		iter=iter->next;
	if(iter->next==NULL){
		printf("Item was not found!");
		return r;
	}
	node* temp=iter->next;
	iter->next=iter->next->next;
	iter->next->prev=iter;
	free(temp);
	printf(" Item %d deleted! ",x);
	return r;
}
void find(node* r,int x){
	node* iter=r;
	if(r==NULL)
		printf("List Empty!");
	if(iter->data==x)
		printf(" Item %d found, adress : %x ",x,r);
	while(iter->next!=NULL && iter->next->data !=x)
		iter=iter->next;
	if(iter->next==NULL){
		printf("Item was not found!");
	}
	printf(" Item %d found, adress : %x ",x,iter->next);
}
		
		


	
	




	


