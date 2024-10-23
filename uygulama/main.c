#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node*start=NULL;
struct node*temp=NULL;
struct node*prev=NULL;
void basaEkle(int veri)
{
	struct node* eleman=(struct node*)malloc(sizeof (struct node));
	eleman->data=veri;
			if(start==NULL)
  {
	start=eleman;
	start->next=NULL;			
  }
  else 
  {
  	temp=start;
  	start=eleman;
  	start->next=temp;
  }
}
 void sonaEkle(int veri)
 {
 	struct node*eleman=(struct node*)malloc(sizeof(struct node));
 	eleman->data=veri;
 	eleman->next=NULL;
 	if(start==NULL)
 	{
 		start=eleman;
	 }
	 else
	 {
	 	temp=start;
	 	while(temp->next!=NULL)
	 	{
	 		temp=temp->next;
		 }
		 temp->next=eleman;
	 }
  } 
  void listele()
  {
  	system("cls");
  	if(start==NULL)
  	{
	
  	printf("Liste Bos.. \n");
  	start=NULL;
  }
  	else
	  {
  	     temp=start;
		   while(temp->next!=NULL)	
		   {
		   	printf("%d ->", temp->data);
		   	temp=temp->next;
		   }
		   printf("%d ", temp->data);
	  }
  }
void bastanSil()
{
	if(start==NULL)
	{
		printf("Liste bos,silinecek eleman yok \n");
	}
	else
	{
		if(start->next==NULL)
		{
	
		free(start);//dugum boþ ise silmeye yarýyor
		start=NULL;
    	}
    	else 
    	{
    		temp=start->next;//startan sonraki ikinci düðümü göster
    		free(start);
    		start=temp;
		}
	}
}
void sondanSil()
{
	if(start==NULL)
	{
		printf("Listede Hic eleman yok!\n");
	}
	else 
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
		}
		else
		{
		
		temp=start;
		while(temp->next->next!=NULL)//son eleman olduðunu bulmak için nextin nexti kullanýlýr.
		{
			temp=temp->next;
		}
		prev=temp;//son düðümden bir önceki düðümü tut dedik burada
		free(temp->next);// tutuðumuz düðümden sonraki düðümü sil
		prev->next=NULL;
	}
	}
}
int elemanSay()
{
	int adet=0;
	if(start==NULL)
	return 0;
	else
    {	
    temp=start;
	while(temp->next!=NULL)
	{ 
    	adet++; 
	   temp=temp->next;
	}
	adet++;
    }
      return adet;
}   
int dataToplam()
{
	int toplam=0;
	if(start == NULL)
	return 0;
	else
	{
		temp=start;
		while(temp->next!=NULL )
		{
			toplam+= temp->data;
			temp=temp->next;
		}
		toplam+=temp->data;
	}
	return toplam;
}
int main(int argc, char *argv[]) {
	
	while(1)
	{
		
	int secim,sayi;
	printf("\n \t MENU \n");
	printf(" 1---> basa eleman ekleme \n");
	printf("2---> sona eleman ekleme \n");
	printf("3---> bastan eleman silme \n");
	printf("4---> sondan eleman silme \n");
	printf("5--->  eleman adeti \n");
	printf("6--->  eleman deger toplami \n");
	printf("7---> LISTELE\n");
	printf("8---> CIKIS \n");
	scanf("%d", &secim );
	switch(secim)
{
      case 1:printf("Basa eklenecek Eleman: ");
             scanf("%d",&sayi);
             basaEkle(sayi);
            break;
      case 2:printf("Sona  eklenecek Eleman: ");
            scanf("%d",&sayi);
            sonaEkle(sayi);
             break;
        
      case 3:
            bastanSil();
             break;
      case 4:
            sondanSil();
             break;
      case 5:printf("Eleman adeti: %d ", elemanSay());
           break;    
   	 case 6:printf(" Elemanlarin Degerlerinin Toplami :  %d", dataToplam());
            
             break;		   

      case 7: listele();
      break;
      
      case 8: 
      return 0;
      

}
}
}
