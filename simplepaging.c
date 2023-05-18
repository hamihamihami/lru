#include<stdio.h>
int main()
{
	int phya,loga,ipla,oppa,pgsize,pgoffset,pgno,no_pages,no_frames,pgtable[100],i,pgentry;
	printf("\n enter logical address space:");
	scanf("%d",&loga);
	printf("\n enter physical address space:");
	scanf("%d",&phya);
	printf("\n enter page size:");
	scanf("%d",&pgsize);
	no_pages=loga/pgsize;
	no_frames=phya/pgsize;
	printf("\n no of pages=%d \n no of frames=%d",no_pages,no_frames);
	printf("\n enter table entries:");
	for(i=0;i<no_pages;i++)
	scanf("%d",&pgtable[i]);
	printf("\n enter logical address:");
	scanf("%d",&ipla);
	pgoffset=ipla%pgsize;
	pgno=ipla/no_pages;
	pgentry=pgtable[pgno];
	oppa=(pgentry*pgsize)+pgoffset;
	printf("\n physical address=%d",oppa);
	return 0;
}
