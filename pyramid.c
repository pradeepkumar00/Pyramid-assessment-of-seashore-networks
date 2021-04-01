#include<stdio.h> 
#include<stdlib.h>
void printno1(int l,int x,int size){
	int j=0;
	char *c = (char *)malloc(sizeof(char)*l); #memory allocation in heap

	while(j<l){
		if(j==(l-x)/2+1){   # first we have store edge char
			*(c+j)='/';}
		else if(j==(l+x)/2){
			*(c+j)='\\';}
		else if(j>(l-x)/2+1 && j<(l+x)/2){ 
			*(c+j)='*';}
		else{
			*(c+j)=' ';}
		j++;}
	//printf("%s\n",c);
	write(1, c, l);
	free(c);}
void printno(int l,int x,int size){
	int j=0;
	char *c = (char *)malloc(sizeof(char)*(l+10));

	while(j<=l){
		if(j==(l-x)/2+1){
			*(c+j)='/';}
		else if(j==(l+x)/2){
			*(c+j)='\\';}
		else if(j>(l-size-2)/2+1 && j<(l+size+2)/2){
			*(c+j)='|';}
		else if(j>(l-x)/2+1 && j<(l+x)/2){
			*(c+j)='*';}
		else{
			*(c+j)=' ';}
		j++;}
	//printf("%s\n",c);
	write(1, c, l+10);
	free(c);}
void pyramid(int size){
	int height=3, length=7, x=3, count=0, n=3,i=1,j=0;

	if(size==0){return;}
	while(i<size){
		height=height+3+i;
		length=length+6+2*(2+i);
		i++;}
	while(j<height){
		if(j>=height-size){
			printno(length,x,size);}
		else{	
			printno1(length,x,size);}
		x+=2;
		count++;
		j++;
		if(count==n){
			n++;
			count=0;
			x+=4;}}}
int main(int argc,char const *argv[]) 
{ 
    int pyramid_size; 
    pyramid_size=atoi(argv[1]);
    pyramid(pyramid_size);
    return (0); 
}
