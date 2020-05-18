#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n* next;
};
typedef n node;
	
void write(node *);

node* add(node*,int);
	
node* del(node*,int);

node* addSorted(node* ,int ); 

int main() {
	node * root;
	root=NULL;
	for(int i=0;i<20;i++) {
		root=add(root,10*i);
	}
	write(root);
	root=del(root,30);
	write(root);
	root=addSorted(root,33);
	/*for(int i=21; i<30; i++) {
		root=addSorted(root,i*12);
	}*/
	write(root);
	return 0;
}

//ilk değerden küçükse ++
//liste boşsa ++
//ara değer ise ++
//en büyükse++
node* addSorted(node* r,int x) {
	node * iter=r;
	node * temp;
	if (r==NULL){
			r=(node*)malloc(sizeof(node));
			r->data=x;
			r->next=NULL;
			return r;
	}
	if(r->data>x){
		temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=r;
		return temp;
	}
	while(x > iter->next->data && iter->next!=NULL){
		iter=iter->next;
	}
	temp=(node*)malloc(sizeof(node));
	temp->data=x;
	if(iter->next==NULL){
		iter->next=temp;
		temp->next=NULL;
		return r;
	}
	temp->next=iter->next;
	iter->next=temp;
	return r;
}

node* add(node* r, int x) {
	if (r==NULL){
		r=(node*)malloc(sizeof(node));
		r->data=x;
		r->next=NULL;
		return r;
	}
	node * iter=r;
	while (iter->next!=NULL)
		iter=iter->next;
	iter->next=(node*)malloc(sizeof(node));
	iter=iter->next;
	iter->data=x;
	iter->next=NULL;
	return r;	
}

void write(node *r) {
	if(r==NULL)
		printf("liste boş\n");
	else{ 
		while(r->next!=NULL) {
			printf("%d -> ",r->data);
			r=r->next;
		}
		printf("%d \n",r->data);
	}
}

node* del(node* r,int x) {//değer listede yoksa parçalanma arızası veriyor
	node * iter=r;
	node * temp;
	if(r==NULL) {
		printf("liste boş");
		return r;
	}
	if(r->data==x) {
		temp=r;
		r=r->next;
		free(temp);
		return r;
	}
	while(iter->next->data!=x && iter->next!=NULL){
		iter=iter->next;
	}
	if(iter->next==NULL) {
		printf("Aranan değer bulunamadı\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}





