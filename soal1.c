/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Alkindi Bintang Akhsan (13224022)
 *   Nama File           : soal_1.c
 *   Deskripsi           : Input jumlah pasien lalu ID dan waktu tunggu pasien. Pasien diurut sesuai urutan datang. Cetak urutan ID dan total waktu tunggu pasien
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
   char* id;
   int d;
   struct node* next;
   int sumd;
}node;
struct node* head = NULL;

node* inputpasien(){
   struct node* newnode = (node*)malloc(sizeof(node));
   char* id;
   int d;
   int sumd = 0;
   scanf("%s %d", id, &d);
   newnode->id = id;
   newnode->d = d;
   newnode->next = NULL;

   if(head == NULL){
      head = newnode;
   }
   else{
      struct node* temp = head;
      while(temp->next != NULL){
         temp = temp->next;
      }
      temp->next = newnode;
      sumd = sumd+newnode->d;
   }

   return newnode;
}

void printList(struct node* head) {
   while (head != NULL) {
      printf("%s ", head->id);
      head = head->next;
   }
} //[1]

void printsumd(struct node* head){
   printf("%d", head->sumd);
}


  
int main(void) {
   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      inputpasien();
   }
   printf("ORDER: ");
   printList(head);
   printf("\n");
   printf("WAIT: ");
   printf("%d", head->sumd);
   return 0;

}
 

 
