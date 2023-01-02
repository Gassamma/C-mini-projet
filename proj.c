#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define the structure
struct date
{
        int jour;
        int mois;
        int anneé;
};
struct Product {
  char name[50];
  float price;
  int reference;
  int stock ;
 
};
struct hist
{
  char name[50];
  float price;
  int reference;
  int Quantity ;
  struct date da ;
  int action;
  
        
};



void add_product(){
    struct Product p1,p2 ; 
   int refaux,found=1;
    struct hist h1 ;
  
 
   
    FILE* fpref ;
  fpref = fopen("Productings.txt", "r");
  if(fpref==NULL)
   { printf("give product reference  \n ");
   scanf("%d",&p1.reference);
   refaux=p1.reference;
   
   }else{
        fclose(fpref);
      while(found==1) { 
        found=0;
   printf("give product reference  \n ");
   scanf("%d",&refaux);
     fpref = fopen("Productings.txt", "r");
    while (fread(&p2, sizeof(struct Product), 1, fpref))
    {
        if(p2.reference==refaux){
            printf("reference already exists! please try again \n"); 
          found=1;
          break;
        }
       
    }
    fclose(fpref);}
  p1.reference=refaux;
    
   }
   h1.reference=p1.reference;
    printf("give product price \n");
  scanf("%f",&p1.price);
   h1.price=p1.price;
       printf("give product stock  \n ");
  scanf("%d",&p1.stock);
  h1.Quantity=p1.stock;
   printf("give product name \n ");
  fflush(stdin);
  gets(p1.name);
 
  strcpy(h1.name, p1.name);
  h1.action=1;

  do
  {
       printf("give the day of adding the product \n");
       scanf("%i",&h1.da.jour);
  } while ((h1.da.jour>31)||(h1.da.jour<1));
  do
  {
       printf("give the month of adding the product \n");
       scanf("%i",&h1.da.mois);
  } while ((h1.da.mois>12)||(h1.da.mois<1));
  printf("give the year of adding the product \n");
  scanf("%i",&h1.da.anneé);
 
  

  FILE* fp ;
  fp = fopen("Productings.txt", "a");
  fwrite(&p1, sizeof(struct Product), 1, fp);
  fclose(fp);

  FILE* fph;
   fph = fopen("ProdHis.txt", "a");
  fwrite(&h1, sizeof(struct hist), 1, fph);
  fclose(fph);

}
void print_products(){
   FILE* fp ;
  struct Product p1 ;
  fp = fopen("Productings.txt", "r");
  if (fp == NULL) {
    perror("Error opening file something went wrong!");
    
  }

 
   while(fread(&p1, sizeof(struct Product), 1, fp))
       { 
  printf("Name: %s\n", p1.name);
  printf("price: %f DT\n", p1.price);
  printf("reference: %d\n", p1.reference);
  printf("stock: %d\n", p1.stock);
 
  printf("............................ \n");
  }
    // Close the file
  fclose(fp);

}
int mod(){
 struct  Product p1,p2;
 struct hist h1 ;
 FILE *fp ;
 FILE *fp1;
 FILE *fph;
 int ref,found=0,i,q;
 printf("1-add quantity to a product \n");
 printf("2-decrease quantity of a product \n");
 printf("3-modify a product \n");
 scanf("%i",&i);
 switch (i)
 {
   case 1:
         printf("give product reference to add \n");
         scanf("%i",&ref);
         printf("give quantity to add \n");
         scanf("%i",&q);
         fp = fopen("Productings.txt", "r");
         if (fp == NULL) {
            perror("Error opening file fp");
         }
         fp1 = fopen("Produtss.txt", "a");
         if (fp1 == NULL) {
            perror("Error opening file fp1");
         }
         
         while(fread(&p1, sizeof(struct Product), 1, fp)){
           if(p1.reference==ref){
             fph = fopen("ProdHis.txt", "a");
             if (fph == NULL) {
               perror("Error opening file fph");
             }  
             h1.action=1;
             strcpy(h1.name,p1.name);
             h1.price=p1.price;
             h1.Quantity=q;
             do
             {
              printf("give the day of adding the quantity \n");
              scanf("%i",&h1.da.jour);
      
             } while ((h1.da.jour>31)||(h1.da.jour<1));
             do
             {
              printf("give the month of adding the quantity \n");
              scanf("%i",&h1.da.mois);
       
             } while ((h1.da.mois>12)||(h1.da.mois<1));
             printf("give the year of adding the quantity \n");
             scanf("%i",&h1.da.anneé);
              fwrite(&h1, sizeof(struct hist), 1, fph);
              fclose(fph);
             found=1;
             strcpy(p2.name,p1.name);
             p2.price=p1.price;
             p2.reference=p1.reference;
             p2.stock = p1.stock+q;
             fwrite(&p2, sizeof(struct Product), 1, fp1);
           }else{
              fwrite(&p1, sizeof(struct Product), 1, fp1);}
        }
         fclose(fp);
         fclose(fp1);
         remove("Productings.txt");
        { /*if(remove("Productings.txt")==0){
          printf("file deleted \n");
        }else{printf("222 \n");}*/}
        fp=fopen("Productings.txt","a");
        fp1=fopen("Produtss.txt","r");
        if (fp1 == NULL) {
          perror("Error opening file");
        }
        while(fread(&p1, sizeof(struct Product), 1, fp1))
        { 
          fwrite(&p1, sizeof(struct Product), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
        remove("Produtss.txt");
                break;
   case 2:
                  printf("give product reference to modify \n");
         scanf("%i",&ref);
         printf("Quantity of removing \n");
         scanf("%i",&q);
         fp = fopen("Productings.txt", "r");
         if (fp == NULL) {
            perror("Error opening file fp");
         }
         fp1 = fopen("Produtss.txt", "a");
         if (fp1 == NULL) {
            perror("Error opening file fp1");
         }
         
         while(fread(&p1, sizeof(struct Product), 1, fp)){
           if(p1.reference==ref){
                if(q>p1.stock){
                        printf("quantity not available!! \n");
                        return 0;}
             fph = fopen("ProdHis.txt", "a");
             if (fph == NULL) {
               perror("Error opening file fph");
             }  
             h1.action=2;
             strcpy(h1.name,p1.name);
             h1.price=p1.price;
             h1.Quantity=q;
             do
             {
              printf("give the day of modifying the product \n");
              scanf("%i",&h1.da.jour);
      
             } while ((h1.da.jour>31)||(h1.da.jour<1));
             do
             {
              printf("give the month of modifying the product \n");
              scanf("%i",&h1.da.mois);
       
             } while ((h1.da.mois>12)||(h1.da.mois<1));
             printf("give the year of modifying the product \n");
             scanf("%i",&h1.da.anneé);
              fwrite(&h1, sizeof(struct hist), 1, fph);
              fclose(fph);
             found=1;
             strcpy(p2.name,p1.name);
             p2.price=p1.price;
             p2.reference=p1.reference;
             p2.stock =p1.stock-q;
             fwrite(&p2, sizeof(struct Product), 1, fp1);
           }else{
              fwrite(&p1, sizeof(struct Product), 1, fp1);}
        }
         fclose(fp);
         fclose(fp1);
        remove("Productings.txt");
      
        fp=fopen("Productings.txt","a");
        fp1=fopen("Produtss.txt","r");
        if (fp1 == NULL) {
          perror("Error opening file");
        }
        while(fread(&p1, sizeof(struct Product), 1, fp1))
        { 
          fwrite(&p1, sizeof(struct Product), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
        remove("Produtss.txt");
                break;
   case 3:
         fp = fopen("Productings.txt", "r");
         if (fp == NULL) {
            perror("Error opening file fp");
         }
         fp1 = fopen("Produtss.txt", "a");
         if (fp1 == NULL) {
            perror("Error opening file fp1");
         }
         printf("give product reference to modify \n");
         scanf("%i",&ref);

         while(fread(&p1, sizeof(struct Product), 1, fp)){
           if(p1.reference==ref){
             found=1;
             printf("give new product price \n");
             scanf("%f",&p2.price);
             printf("give new product reference  \n ");
             scanf("%d",&p2.reference);
             printf("give new product stock  \n ");
             scanf("%d",&p2.stock);
             printf("give new product name \n ");
             fflush(stdin);
             gets(p2.name);
           
          
             fwrite(&p2, sizeof(struct Product), 1, fp1);
           }else{
              fwrite(&p1, sizeof(struct Product), 1, fp1);}
        }
         fclose(fp);
         fclose(fp1);
        remove("Productings.txt");
      
        fp=fopen("Productings.txt","a");
        fp1=fopen("Produtss.txt","r");
        if (fp1 == NULL) {
          perror("Error opening file");
        }
        while(fread(&p1, sizeof(struct Product), 1, fp1))
        { 
          fwrite(&p1, sizeof(struct Product), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
        remove("Produtss.txt");
                break;        
        default:
                break;
        }

  

}
void search(){
 struct  Product p1;
  FILE *fp;
  int ref,found=0;
  printf("give product reference to search for \n");
  scanf("%d",&ref);

  fp = fopen("Productings.txt", "r");
  while(fread(&p1, sizeof(struct Product), 1, fp)){
   if(p1.reference==ref){
    found=1;
  printf("Name: %s\n", p1.name);
  printf("price: %f DT\n", p1.price);
  printf("reference: %d\n", p1.reference);
  printf("stock: %d\n", p1.stock);
 
  printf("............................ \n");
   }

  }
  if(found!=1){
    printf("product with this reference not found please try again!");
  }

  fclose(fp);

}
void del(){
 struct  Product p1,p2;
 struct hist h1;
 FILE* fp  ;
 FILE *fph;
 
  int ref,found=0;
 char Newname[50];
  fph = fopen("ProdHis.txt", "a");
  fp = fopen("Productings.txt", "r");
    if (fp == NULL) {
    perror("Error opening file fp");
    
  }
    FILE* fp1;
  fp1 = fopen("Productss.txt", "a");
   
      if (fp1 == NULL) {
    perror("Error opening file fp1");
    
  }
     printf("give product reference to delete \n");
  scanf("%i",&ref);

  while(fread(&p1, sizeof(struct Product), 1, fp)){
   if(p1.reference==ref){
   found=1;
  printf("product deleted successfully! \n");
h1.price=p1.price;
h1.action=2;
h1.Quantity=p1.stock;
strcpy(h1.name, p1.name);
h1.reference=p1.reference;
  do
  {
       printf("give the day of deleting the product \n");
       scanf("%i",&h1.da.jour);
      
  } while ((h1.da.jour>31)||(h1.da.jour<1));
  do
  {
       printf("give the month of deleting the product \n");
       scanf("%i",&h1.da.mois);
       
  } while ((h1.da.mois>12)||(h1.da.mois<1));
  printf("give the year of deleting the product \n");
  scanf("%i",&h1.da.anneé);

fwrite(&h1, sizeof(struct hist), 1, fph);
   }else
{fwrite(&p1, sizeof(struct Product), 1, fp1);}
  }
  fclose(fp);
  fclose(fp1);
    fclose(fph);

 remove("Productings.txt");
 
   fp=fopen("Productings.txt","a");
   fp1=fopen("Productss.txt","r");
   if (fp1 == NULL) {
    perror("Error opening file");
    
  }

 
   while(fread(&p1, sizeof(struct Product), 1, fp1))
       { 
        fwrite(&p1, sizeof(struct Product), 1, fp);
  
  }
 

  fclose(fp);
  fclose(fp1);
  remove("Productss.txt");

}
void hist(){
   int choice,m,y,j;

   printf("1-View by month \n");
   printf("2-View by day \n");
   printf("3-View all history \n");
   scanf("%i",&choice);
if(choice==1){
                struct hist h1;
         FILE* fph;
        fph = fopen("ProdHis.txt", "r");

        printf("give month \n");
        scanf("%i",&m);
        printf("give year \n");
        scanf("%i",&y);
        while(fread(&h1, sizeof(struct hist), 1, fph))
       { 
        if((h1.da.mois==m)&&(h1.da.anneé==y))
        { if(h1.action==1){
        printf("added product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
          }else{
        printf("removed product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
       }}
       }
       fclose(fph);
}else if (choice==2)
{
                       struct hist h1;
         FILE* fph;
        fph = fopen("ProdHis.txt", "r");
        printf("give year \n");
        scanf("%i",&y);
        printf("give month \n");
        scanf("%i",&m);
          printf("give day \n");
        scanf("%i",&j);
      
        while(fread(&h1, sizeof(struct hist), 1, fph))
       { 
        if((h1.da.mois==m)&&(h1.da.anneé==y)&&(h1.da.jour==j))
{ if(h1.action==1){
        printf("added product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
 }else{
        printf("removed product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
 }}
  }
   fclose(fph);
}else if(choice==3)
{
                    struct hist h1;
         FILE* fph;
        fph = fopen("ProdHis.txt", "r");
      
      
        while(fread(&h1, sizeof(struct hist), 1, fph))
       { 
       
 if(h1.action==1){
        printf("added product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
 }else{
        printf("removed product %s with %d items on %i / %i /%i . \n",h1.name,h1.Quantity,h1.da.jour,h1.da.mois,h1.da.anneé);
 }
  }
   fclose(fph);  

}



       

}
int main(void) {
      int ch;
    do{
        printf("1-add product \n");
        printf("2-display product \n");
        printf("3-modify product \n");
        printf("4-delete product \n");
        printf("5-search product \n");
        printf("6-view history \n");
        printf("7-quit \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
           add_product();
            break;
        case 2:
           print_products();
            break;
        case 3:
           mod();
            break;
        case 4:
            del();
            break;
            case 5:
            search();
            break;
             case 6:
            hist();
            break;
        
        default:
            break;
        }
    }while(ch>0&&ch<=6);
 
  
  
  return 0;
  }



