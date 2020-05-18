#include <stdio.h>
#include <stdlib.h>

struct n{
	n* next;
	int data;
};
typedef n node;

void display(node*);

node* add(node*, int);

node* addSort(node*, int);

node* del(node*,int);

void find(node*, int);

int main(){
	node* root=NULL;
	root=add(root,25);
	root=add(root,35);
	display(root);
	for(int i=20;i>0;i--)
		root=addSort(root,i*10);
	display(root);
	printf("\ncheck point \n\n");
	root=del(root,35);
	display(root);
	root=del(root,35);
	display(root);
	printf("\ncheck point \n\n");
	find(root,25);
	find(root,35);
	find(root,10);
	return 0;
}
void display(node* r){
	node* iter=r;
	if(r==NULL)
		printf("List Empty!");
	printf("%d->",iter->data);
	iter=iter->next;
	while(iter!=r){
		printf("%d->",iter->data);
		iter=iter->next;
	}
}
node* add(node*r, int x){
	node* iter=r;
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=r;
		return r;
	}
	while(iter->next!=r)
		iter=iter->next;
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	iter->next=temp;
	temp->next=r;
	return r;
}
node* addSort(node* r, int x){
	node* iter=r;
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=r;
		return r;
	}
	if(r->data>x){
		while(iter->next!=r)
			iter=iter->next;
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;
		iter->next=temp;
		r=temp;
		return r;
	}
	while(iter->next!=r && iter->next->data<x)
		iter=iter->next;	
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=iter->next;
	iter->next=temp;
	return r;
}
node* del(node* r,int x){
	node* iter=r;
	if(r==NULL){
		printf("List is Empty!");
		return r;
	}
	if(r->data==x){
		while(iter->next!=r)
			iter=iter->next;
		node* temp=r;
		r=r->next;
		iter->next=r;
		free(temp);
		return r;
	}
	while(iter->next!=r && iter->next->data!=x)
		iter=iter->next;
	if(iter->next->data!=x){
		printf("Item was not found!");
		return r;
	}
	node * temp=iter->next;
	iter->next=temp->next;
	free(temp);
	return r;
}
void find(node* r, int x){
	node* iter=r;
	if(r==NULL)
		printf("List is Empty!  ");
	if(r!=NULL){
		if(r->data==x){
			printf("Item %d was found, adress : %x  ",x,r);
		}
		while(iter->next!=r && iter->next->data!=x)
			iter=iter->next;
		if(iter->next->data!=x)
			printf("Item %d was not found!  ",x);
		if(iter->next!=r)
			printf("Item %d was found, adress : %x  ",x,iter->next);
	}
}
		
	
	

